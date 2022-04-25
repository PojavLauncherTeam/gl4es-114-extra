//
// Created by serpentspirale on 13/01/2022.
//

#ifndef UNTITLED_SHADERCONV_H
#define UNTITLED_SHADERCONV_H

#include "../shader.h"

char * ConvertShaderVgpu(struct shader_s * shader_source);

char * GLSLHeader(char* source);
char * RemoveConstInsideBlocks(char* source, int * sourceLength);
char * ForceIntegerArrayAccess(char* source, int * sourceLength);
char * CoerceIntToFloat(char * source, int * sourceLength);
char * ReplaceModOperator(char * source, int * sourceLength);
char * WrapIvecFunctions(char * source, int * sourceLength);
char * WrapFunction(char * source, int * sourceLength, char * functionName, char * wrapperFunctionName, char * wrapperFunction);
int FindPositionAfterDirectives(char * source);
char * ReplaceGLFragData(char * source, int * sourceLength);
char * ReplaceGLFragColor(char * source, int * sourceLength);
char * ReplaceVariableName(char * source, int * sourceLength, char * initialName, char* newName);
char * RemoveUnsupportedExtensions(char * source);
int doesShaderVersionContainsES(const char * source);
char * getClosingTokens(char openingToken);
int isOpeningToken(char openingToken);
int getClosingTokenPosition(const char * source, int initialTokenPosition);
int getClosingTokenPositionTokenOverride(const char * source, int initialTokenPosition, char initialToken);
int getNextTokenPosition(const char * source, int initialPosition, const char token, const char * acceptedChars);
unsigned long strstrPos(const char * haystack, const char * needle);
char * insertIntAtFunctionCall(char * source, int * sourceSize, const char * functionName, int argumentPosition);


char* GetOperandFromOperator(char* source, int operatorIndex, int rightOperand, int * limit);

#endif //UNTITLED_SHADERCONV_H
