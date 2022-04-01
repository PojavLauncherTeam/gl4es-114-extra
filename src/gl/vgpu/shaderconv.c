//
// Created by serpentspirale on 13/01/2022.
//

#include <string.h>
#include <malloc.h>
#include "shaderconv.h"
#include "../string_utils.h"
#include "../logs.h"
#include "../const.h"

// Version expected to be replaced
char * old_version = "#version 120";
// The version we will declare as
//char * new_version = "#version 450 compatibility";
char * new_version = "#version 320 es\n";

int NO_OPERATOR_VALUE = 9999;

/** Convert the shader through multiple steps
 * @param source The start of the shader as a string*/
char * ConvertShaderVgpu(struct shader_s * shader_source){

    SHUT_LOGD("VGPU BEGIN: \n%s", shader_source->converted);
    // Get the shader source
    char * source = shader_source->converted;
    int sourceLength = strlen(source);


    // Remove 'const' storage qualifier
    //SHUT_LOGD("REMOVING CONST qualifiers");
    //source = RemoveConstInsideBlocks(source, &sourceLength);
    //source = ReplaceVariableName(source, &sourceLength, "const", " ");


    SHUT_LOGD("FUCKING UP PRECISION");
    source = ReplaceVariableName(source, &sourceLength, "highp", "lowp");
    source = ReplaceVariableName(source, &sourceLength, "mediump", "lowp");

    // Avoid keyword clash with gl4es #define blocks
    SHUT_LOGD("REPLACING KEYWORDS");
    //source = ReplaceVariableName(source, "texture", "vgpu_Texture");
    source = ReplaceVariableName(source, &sourceLength, "sample", "vgpu_Sample");

    SHUT_LOGD("REMOVING \" CHARS ");
    // " not really supported here
    source = InplaceReplaceSimple(source, &sourceLength, "\"", "");

    // For now let's hope no extensions are used
    // TODO deal with extensions but properly
    SHUT_LOGD("REMOVING EXTENSIONS");
    source = RemoveUnsupportedExtensions(source);

    // OpenGL natively supports non const global initializers, not OPENGL ES except if we add an extension
    SHUT_LOGD("ADDING EXTENSIONS\n");
    int insertPoint = FindPositionAfterDirectives(source);
    SHUT_LOGD("INSERT POINT: %i\n", insertPoint);
    source = InplaceReplaceByIndex(source, &sourceLength, insertPoint, insertPoint-1, "\n#extension GL_EXT_shader_non_constant_global_initializers : enable\n");

    SHUT_LOGD("REPLACING mod OPERATORS");
    // No support for % operator, so we replace it
    source = ReplaceModOperator(source, &sourceLength);

    SHUT_LOGD("COERCING INT TO FLOATS");
    // Hey we don't want to deal with implicit type stuff
    source = CoerceIntToFloat(source, &sourceLength);

    SHUT_LOGD("FIXING ARRAY ACCESS");
    // Avoid any weird type trying to be an index for an array
    source = ForceIntegerArrayAccess(source, &sourceLength);

    SHUT_LOGD("WRAPPING FUNCTION");
    // Since everything is a float, we need to overload WAY TOO MANY functions
    source = WrapIvecFunctions(source, &sourceLength);

    // Draw buffers aren't dealt the same on OPEN GL|ES
    if(shader_source->type == GL_FRAGMENT_SHADER && doesShaderVersionContainsES(source) ){
        SHUT_LOGD("REPLACING FRAG DATA");
        source = ReplaceGLFragData(source, &sourceLength);
        SHUT_LOGD("REPLACING FRAG COLOR");
        source = ReplaceGLFragColor(source, &sourceLength);
    }
    SHUT_LOGD("VGPU END: \n%s", source);
    return source;
}

int doesShaderVersionContainsES(const char * source){
    if(FindString(source, "#version 300 es") || FindString(source, "#version 310 es") || FindString(source, "#version 320 es")){
        return 1;
    }
    return 0;
}

char * WrapIvecFunctions(char * source, int * sourceLength){
    source = WrapFunction(source, sourceLength, "texelFetch", "vgpu_texelFetch", "\nvec4 vgpu_texelFetch(sampler2D sampler, vec2 P, float lod){return texelFetch(sampler,ivec2(int(P.x),int(P.y)),int(lod));}");


    return source;
}

/**
 * Replace a function and its calls by a wrapper version, only if needed
 * @param source The shader code as a string
 * @param functionName The function to be replaced
 * @param wrapperFunctionName The replacing function name
 * @param function The wrapper function itself
 * @return The shader as a string, maybe in a different memory location
 */
char * WrapFunction(char * source, int * sourceLength, char * functionName, char * wrapperFunctionName, char * wrapperFunction){
    // Okay, we have a few cases to distinguish to make sure we don't replace something unintended:
    // Let's say we want to replace a "FunctionName"
    // float FunctionNameResult ...             ----- something between FunctionName and the ( , skip it.
    // BiggerFunctionName(...                   ----- FunctionName part of another function ! Skip it.
    // Function(FunctionName( ...               ----- There is a call to function name


    const char * findStringPtr = FindString(source, functionName);
    if(findStringPtr){
        // Check the right end
        for(int i= strlen(functionName); 1; ++i){
            if(findStringPtr[i] == ' ' || findStringPtr[i] == '\n') continue;
            if (findStringPtr[i] == '(') break; // Allowed going further, since it looks like a function call
            return source;
        }

        // Left end
        findStringPtr --;
        if(isValidFunctionName(findStringPtr[0])) return source; // Var or function name
        // At this point, the call is real, so just replace them
        int insertPoint = FindPositionAfterDirectives(source);
        source = InplaceReplaceSimple(source, sourceLength, functionName, wrapperFunctionName);
        source = InplaceReplaceByIndex(source, sourceLength, insertPoint, insertPoint-1, wrapperFunction);
        //SHUT_LOGD("WHAT THE FUCK IS BROKEN TIMES TWO : \n%s", wrapperFunction);
    }
    return source;
}

/**
 * Replace the % operator with a mathematical equivalent (x - y * floor(x/y))
 * @param source The shader as a string
 * @return The shader as a string, maybe in a different memory location
 */
char * ReplaceModOperator(char * source, int * sourceLength){
    char * modelString = " mod(x, y) ";
    int startIndex, endIndex = 0;
    int * startPtr = &startIndex, *endPtr = &endIndex;

    for(int i=0;i<*sourceLength; ++i){
        if(source[i] != '%') continue;
        // A mod operator is found !
        char * leftOperand = GetOperandFromOperator(source, i, 0, startPtr);
        char * rightOperand = GetOperandFromOperator(source,  i, 1, endPtr);

        // Generate a model string to be inserted
        char * replacementString = malloc(strlen(modelString) + 1);
        strcpy(replacementString, modelString);
        int replacementSize = strlen(replacementString);
        replacementString = InplaceReplace(replacementString, &replacementSize, "x", leftOperand);
        replacementString = InplaceReplace(replacementString, &replacementSize, "y", rightOperand);

        // Insert the new string
        source = InplaceReplaceByIndex(source, sourceLength, startIndex, endIndex, replacementString);

        // Free all the temporary strings
        free(leftOperand);
        free(rightOperand);
        free(replacementString);
    }

    return source;
}

/**
 * Change all (u)ints to floats.
 * This is a hack to avoid dealing with implicit conversions on common operators
 * @param source The shader as a string
 * @return The shader as a string, maybe in a new memory location
 * @see ForceIntegerArrayAccess
 */
char * CoerceIntToFloat(char * source, int * sourceLength){
    // Let's go the "freestyle way"

    // Step 1 is to translate keywords
    // Attempt and loop unrolling -> worked well, time to fix my shit I guess
    source = ReplaceVariableName(source, sourceLength, "int", "float");
    source = WrapFunction(source, sourceLength, "int", "float", "\n ");
    source = ReplaceVariableName(source, sourceLength, "uint", "float");
    source = WrapFunction(source, sourceLength, "uint", "float", "\n ");
    // TODO Yes I could just do the same as above.
    
    source = InplaceReplaceSimple(source, sourceLength, "ivec", "vec");


    // Step 3 is slower.
    // We need to parse hardcoded values like 1 and turn it into 1.(0)
    for(int i=0; i<*sourceLength; ++i){

        // Avoid version directives
        if(source[i] == '#' && (source[i + 1] == 'v' || source[i + 1] == 'l') ){
            // Look for the next line
            while (source[i] != '\n'){
                i++;
            }
        }

        if(!isDigit(source[i])){ continue; }
        // So there is a few situations that we have to distinguish:
        // functionName1 (      ----- meaning there is SOMETHING on its left side that is related to the number
        // function(1,          ----- there is something, and it ISN'T related to the number
        // float test=3;        ----- something on both sides, not related to the number.
        // float test=X.2       ----- There is a dot, so it is part of a float already
        // float test = 0.00000 ----- I have to backtrack to find the dot

        if(source[i-1] == '.' || source[i+1] == '.') continue;// Number part of a float
        if(isValidFunctionName(source[i - 1])) continue; // Char attached to something related
        if(/*isDigit(source[i-1]) || */ isDigit(source[i+1])) continue; // End of number not reached
        if(isDigit(source[i-1])){
            // Backtrack to check if the number is floating point
            int shouldBeCoerced = 0;
            for(int j=1; 1; ++j){
                if(isDigit(source[i-j])) continue;
                if(isValidFunctionName(source[i-j])) break; // Function or variable name, don't coerce
                if(source[i-j] == '.' || source[i-j] == '+') break; // No coercion, float or scientific notation already
                // Nothing found, should be coerced then
                shouldBeCoerced = 1;
                break;
            }

            if(!shouldBeCoerced) continue;
        }

        // Now we know there is nothing related to the digit, turn it into a float
        source = InplaceReplaceByIndex(source, sourceLength, i+1, i, ".0");
    }

    // TODO Hacks for special built in values and typecasts ?
    source = InplaceReplaceSimple(source, sourceLength, "gl_VertexID", "float(gl_VertexID)");
    source = InplaceReplaceSimple(source, sourceLength, "gl_InstanceID", "float(gl_InstanceID)");

    return source;
}

/** Force all array accesses to use integers by adding an explicit typecast
 * @param source The shader as a string
 * @return The shader as a string, maybe at a new memory location */
char * ForceIntegerArrayAccess(char* source, int * sourceLength){
    char * markerStart = "$";
    char * markerEnd = "`";

    // Step 1, we need to mark all [] that are empty and must not be changed
    int leftCharIndex = 0;
    for(int i=0; i< *sourceLength; ++i){
        if(source[i] == '['){
            leftCharIndex = i;
            continue;
        }
        // If a start has been found
        if(leftCharIndex){
            if(source[i] == ' ' || source[i] == '\n'){
                continue;
            }
            // We find the other side and mark both ends
            if(source[i] == ']'){
                source[leftCharIndex] = *markerStart;
                source[i] = *markerEnd;
            }
        }
        //Something else is there, abort the marking phase for this one
        leftCharIndex = 0;
    }

    // Step 2, replace the array accesses with a forced typecast version
    source = InplaceReplaceSimple(source, sourceLength, "]", ")]");
    source = InplaceReplaceSimple(source, sourceLength, "[", "[int(");

    // Step 3, restore all marked empty []
    source = InplaceReplaceSimple(source, sourceLength, markerStart, "[");
    source = InplaceReplaceSimple(source, sourceLength, markerEnd, "]");

    return source;
}


/** Small helper to help evaluate whether to continue or not I guess
 * Values over 9900 are not for real operators, more like stop indicators*/
int GetOperatorValue(char operator){
    if(operator == ',' || operator == ';') return 9998;
    if(operator == '=') return 9997;
    if(operator == '+' || operator == '-') return 3;
    if(operator == '*' || operator == '/' || operator == '%') return 2;
    return NO_OPERATOR_VALUE; // Meaning no value;
}

/** Get the left or right operand, given the last index of the operator
 * It bases its ability to get operands by evaluating the priority of operators.
 * @param source The shader as a string
 * @param operatorIndex The index the operator is found
 * @param rightOperand Whether we get the right or left operator
 * @param limit The left or right index of the operand
 * @return newly allocated string with the operand
 */
char* GetOperandFromOperator(char* source, int operatorIndex, int rightOperand, int * limit){
    int parserState = 0;
    int parserDirection = rightOperand ? 1 : -1;
    int operandStartIndex = 0, operandEndIndex = 0;
    int parenthesesLeft = 0, hasFoundParentheses = 0;
    int operatorValue = GetOperatorValue(source[operatorIndex]);
    int lastOperator = 0; // Used to determine priority for unary operators

    char parenthesesStart = rightOperand ? '(' : ')';
    char parenthesesEnd = rightOperand ? ')' : '(';
    int stringIndex = operatorIndex;

    // Get to the operand
    while (parserState == 0){
        stringIndex += parserDirection;
        if(source[stringIndex] != ' '){
            parserState = 1;
            // Place the mark
            if(rightOperand){
                operandStartIndex = stringIndex;
            }else{
                operandEndIndex = stringIndex;
            }

            // Special case for unary operator when parsing to the right
            if(GetOperatorValue(source[stringIndex]) == 3 ){ // 3 is +- operators
                stringIndex += parserDirection;
            }
        }
    }

    // Get to the other side of the operand, the twist is here.
    while (parenthesesLeft > 0 || parserState == 1){

        // Look for parentheses
        if(source[stringIndex] == parenthesesStart){
            hasFoundParentheses = 1;
            parenthesesLeft += 1;
            stringIndex += parserDirection;
            continue;
        }

        if(source[stringIndex] == parenthesesEnd){
            hasFoundParentheses = 1;
            parenthesesLeft -= 1;

            // Likely to happen in a function call
            if(parenthesesLeft < 0){
                parserState = 3;
                if(rightOperand){
                    operandEndIndex = stringIndex - 1;
                }else{
                    operandStartIndex = stringIndex + 1;
                }
                continue;
            }
            stringIndex += parserDirection;
            continue;
        }

        // Small optimisation
        if(parenthesesLeft > 0){
            stringIndex += parserDirection;
            continue;
        }

        // So by now the following assumptions are made
        // 1 - We aren't between parentheses
        // 2 - No implicit multiplications are present
        // 3 - No fuckery with operators like "test = +-+-+-+-+-+-+-+-3;" although I attempt to support them

        // Higher value operators have less priority
        int currentValue = GetOperatorValue(source[stringIndex]);


        // The condition is different due to the evaluation order which is left to right, aside from the unary operators
        if((rightOperand ? currentValue >= operatorValue: currentValue > operatorValue)){
            if(currentValue == NO_OPERATOR_VALUE){
                if(source[stringIndex] == ' '){
                    stringIndex += parserDirection;
                    continue;
                }

                // Found an operand, so reset the operator eval for unary
                if(rightOperand) lastOperator = NO_OPERATOR_VALUE;

                // maybe it is the start of a function ?
                if(hasFoundParentheses){
                    parserState = 2;
                    continue;
                }
                // If no full () set is found, assume we didn't fully travel the operand
                stringIndex += parserDirection;
                continue;
            }

            // Special case when parsing unary operator to the right
            if(rightOperand && operatorValue == 3 && lastOperator < currentValue){
                stringIndex += parserDirection;
                continue;
            }

            // Stop, we found an operator of same worth.
            parserState = 3;
            if(rightOperand){
                operandEndIndex = stringIndex - 1;
            }else{
                operandStartIndex = stringIndex + 1;
            }
        }

        // Special case for unary operators from the right
        if(rightOperand && operatorValue == 3) { // 3 is + - operators
            lastOperator = currentValue;
        } // Special case for unary operators from the left
        if(!rightOperand && operatorValue < 3 && currentValue == 3){
            lastOperator = NO_OPERATOR_VALUE;
            for(int j=1; 1; ++j){
                int subCurrentValue = GetOperatorValue(source[stringIndex - j]);
                if(subCurrentValue != NO_OPERATOR_VALUE){
                    lastOperator = subCurrentValue;
                    continue;
                }

                // No operator value, can be almost anything
                if(source[stringIndex - j] == ' ') continue;
                // Else we found something. Did we found a high priority operator ?
                if(lastOperator <= operatorValue){ // If so, we allow continuing and going out of the loop
                    stringIndex -= j;
                    parserState = 1;
                    break;
                }
                // No other operator found
                operandStartIndex = stringIndex;
                parserState = 3;
                break;
            }
        }
        stringIndex += parserDirection;
    }

    // Status when we get the name of a function and nothing else.
    while (parserState == 2){
        if(source[stringIndex] != ' '){
            stringIndex += parserDirection;
            continue;
        }
        if(rightOperand){
            operandEndIndex = stringIndex - 1;
        }else{
            operandStartIndex = stringIndex + 1;
        }
        parserState = 3;
    }

    // At this point, we know both the start and end point of our operand, let's copy it
    char * operand = malloc(operandEndIndex - operandStartIndex + 2);
    memcpy(operand, source+operandStartIndex, operandEndIndex - operandStartIndex + 1);
    // Make sure the string is null terminated
    operand[operandEndIndex - operandStartIndex + 1] = '\0';

    // Send back the limitIndex
    *limit = rightOperand ? operandEndIndex : operandStartIndex;

    return operand;
}

/**
 * Replace any gl_FragData[n] reference by creating an out variable with the manual layout binding
 * @param source  The shader source as a string
 * @return The shader as a string, maybe at a different memory location
 */
char * ReplaceGLFragData(char * source, int * sourceLength){

    // 10 is arbitrary, but I don't expect the shader to use so many
    // TODO I guess the array could be accessed with one or more spaces :think:
    // TODO wait they can access via a variable !
    for (int i = 0; i < 10; ++i) {
        // Check for 2 forms on the glFragData and take the first one found
        char needle[30];
        sprintf(needle, "gl_FragData[%i]", i);

        // Skip if the draw buffer isn't used at this index
        char * useFragData = strstr(source, &needle[0]);
        if(useFragData == NULL){
            sprintf(needle, "gl_FragData[int(%i.0)]", i);
            useFragData = strstr(source, &needle[0]);
            if(useFragData == NULL) continue;
        }

        // Construct replacement string
        char replacement[20];
        char replacementLine[70];
        sprintf(replacement, "vgpu_FragData%i", i);
        sprintf(replacementLine, "\nlayout(location = %i) out mediump vec4 %s;\n", i, replacement);
        int insertPoint = FindPositionAfterDirectives(source);

        // And place them into the shader
        source = InplaceReplaceSimple(source, sourceLength, &needle[0], &replacement[0]);
        source = InplaceReplaceByIndex(source, sourceLength, insertPoint, insertPoint-1, &replacementLine[0]);
    }
    return source;
}

/**
 * Replace the gl_FragColor
 * @param source The shader as a string
 * @return The shader a a string, maybe in a different memory location
 */
char * ReplaceGLFragColor(char * source, int * sourceLength){
    if(strstr(source, "gl_FragColor")){
        source = InplaceReplaceSimple(source, sourceLength, "gl_FragColor", "vgpu_FragColor");
        int insertPoint = FindPositionAfterDirectives(source);
        source = InplaceReplaceByIndex(source, sourceLength, insertPoint, insertPoint-1, "\nout mediump vec4 vgpu_FragColor;\n");
    }
    return source;
}

/**
 * Remove all extensions right now by replacing them with spaces
 * @param source The shader as a string
 * @return The shader as a string, maybe in a different memory location
 */
char * RemoveUnsupportedExtensions(char * source){
    //TODO remove only specific extensions ?
    for(char * extensionPtr = strstr(source, "#extension "); extensionPtr; extensionPtr = strstr(source, "#extension ")){
        int i = 0;
        while(extensionPtr[i] != '\n'){
            extensionPtr[i] = ' ';
            ++i;
        }
    }
    return source;
}

/**
 * Replace the variable name in a shader, mostly used to avoid keyword clashing
 * @param source The shader as a string
 * @param initialName The initial name for the variable
 * @param newName The new name for the variable
 * @return The shader as a string, maybe in a different memory location
 */
char * ReplaceVariableName(char * source, int * sourceLength, char * initialName, char* newName) {

    char * toReplace = malloc(strlen(initialName) + 3);
    char * replacement = malloc(strlen(newName) + 3);
    //char * chars = "()[].+-*/~!%<>&|;,{} \n\t";
    char * charBefore = "([];+-*/~!%<>,&| \n\t";
    char * charAfter = ")[];+-*/%<>;,|&. \n\t";

    for (int i = 0; i < strlen(charBefore); ++i) {
        for (int j = 0; j < strlen(charAfter); ++j) {
            // Prepare the string to replace
            toReplace[0] = charBefore[i];
            strcpy(toReplace+1, initialName);
            toReplace[strlen(initialName)+1] = charAfter[j];
            toReplace[strlen(initialName)+2] = '\0';

            // Prepare the replacement string
            replacement[0] = charBefore[i];
            strcpy(replacement+1, newName);
            replacement[strlen(newName)+1] = charAfter[j];
            replacement[strlen(newName)+2] = '\0';

            source = InplaceReplaceSimple(source, sourceLength, toReplace, replacement);
        }
    }

    free(toReplace);
    free(replacement);

    return source;
}

/** Replace the version by new version, period.
 * @param source The pointer to the start of the shader */
char * GLSLHeader(char* source){
    /*
    if(!hardext.glsl320es && !hardext.glsl310es && !hardext.glsl300es){
        return source;
    }*/
    int sourceLength = strlen(source);
    int startIndex, endIndex = 0;
    int index = 0;
    int parserState = 0;

    // Step 1 get to the version
    while (parserState == 0){
        if(source[index] == '#' && source[index + 1] == 'v'){
            parserState = 1;
            startIndex = index;
        }
        index ++;
    }

    //Step 2 get to the end of the line
    while(parserState == 1){
        if(source[index] == '\n'){
            parserState = 2;
            endIndex = index;
        }
        index++;
    }

    // Step 3, replace.
    source = InplaceReplaceByIndex(source, &sourceLength, startIndex, endIndex, new_version);

    return source;
}

/** Remove 'const ' storage qualifier from variables inside {..} blocks
 * @param source The pointer to the start of the shader */
char * RemoveConstInsideBlocks(char* source, int * sourceLength){
    int insideBlock = 0;
    char * keyword = "const \0";
    int keywordLength = strlen(keyword);


    for(int i=0; i< *sourceLength+1; ++i){
        // Step 1, look for a block
        if(source[i] == '{'){
            insideBlock += 1;
            continue;
        }
        if(!insideBlock) continue;

        // A block has been found, look for the keyword
        if(source[i] == keyword[0]){
            int keywordMatch = 1;
            int j = 1;
            while (j < keywordLength){
                if (source[i+j] != keyword[j]){
                    keywordMatch = 0;
                    break;
                }
                j +=1;
            }
            // A match is found, remove it
            if(keywordMatch){
                source = InplaceReplaceByIndex(source, sourceLength, i, i+j - 1, " ");
                continue;
            }
        }

        // Look for an exit
        if(source[i] == '}'){
            insideBlock -= 1;
            continue;
        }
    }
    return source;
}

/** Find the first point which is right after most shader directives
 * @param source The shader as a string
 * @return The index position after the #version line, start of the shader if not found
 */
int FindPositionAfterDirectives(char * source){
    const char * position = FindString(source, "#version");
    if (position == NULL) return 0;
    for(int i=7; 1; ++i){
        if(position[i] == '\n'){
            if(position[i+1] == '#') continue; // a directive is present right after, skip
            return i;
        }
    }
}
