// OpenGL 2.0 >> 3.0

#include "load.h"
#include "pack.h"
#include "pack_.h"
#include "Initialization.h"
//#include "toext.h"


#include <string.h>
#include "printf_def.h"

//int loaded = 0;

//#define _LOAD_GLES if(loaded == 0){loaded=load_all();}

//int count=0;
//int num = 700;

// GLuint glCreateShader( GLenum type )
// {    _LOAD_GLES    
//  return gl4es_glCreateShader( type );     // Because gl4es_glFunc() has been declared as an external type in load.h,
// }								      // So you can use these gl4es_glFunc() directly here. 
									      // However, their function definitions are in load_.h.




// GL_VERSION_1_0
void glCullFace (GLenum mode){    _LOAD_GLES    
 gl4es_glCullFace (mode);

}

void glFrontFace (GLenum mode){    _LOAD_GLES    
 gl4es_glFrontFace (mode);

}

void glHint (GLenum target, GLenum mode){    _LOAD_GLES    
 gl4es_glHint (target, mode);

}

void glLineWidth (GLfloat width){    _LOAD_GLES    
 gl4es_glLineWidth (width);

}

void glPointSize (GLfloat size){    _LOAD_GLES    
 gl4es_glPointSize (size);

}

void glPolygonMode (GLenum face, GLenum mode){    _LOAD_GLES    
 gl4es_glPolygonMode (face, mode);

}

void glScissor (GLint x, GLint y, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glScissor (x, y, width, height);

}

void glTexParameterf (GLenum target, GLenum pname, GLfloat param){    _LOAD_GLES    
 gl4es_glTexParameterf (target, pname, param);

}

void glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params){    _LOAD_GLES    
 gl4es_glTexParameterfv (target, pname, params);

}

void glTexParameteri (GLenum target, GLenum pname, GLint param){    _LOAD_GLES    
 gl4es_glTexParameteri (target, pname, param);

}

void glTexParameteriv (GLenum target, GLenum pname, const GLint *params){    _LOAD_GLES    
 gl4es_glTexParameteriv (target, pname, params);

}

void glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexImage1D (target, level, internalformat, width, border, format, type, pixels);

}

void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexImage2D (target, level, internalformat, width, height, border, format, type, pixels);

}

void glDrawBuffer (GLenum buf){    _LOAD_GLES    
 //Printf("GL: glDrawBuffer(%x) \n", buf);
 GLenum *bufs = &buf;
 gles_glDrawBuffers (1, (const GLenum *)bufs);

}

void glClear (GLbitfield mask){    _LOAD_GLES    
 /*if(count%num==0){
  Printf("////////glClear : %x  MaxDrawBuffers : %d ////////\n", (int)mask, MaxDrawBuffers);
  if((mask&GL_COLOR_BUFFER_BIT)!=0){
  	Printf("mask&GL_COLOR_BUFFER_BIT != 0");
  }
 }
 count++;
 if(count>50000000){
  count=0;
 }*/
 //Printf("GL: glClear(%x) \n", mask);
 
 if((mask&GL_COLOR_BUFFER_BIT)!=0){
 //if(mask==GL_COLOR_BUFFER_BIT){
    /*gles_glDrawBuffers(MaxDrawBuffers, (const GLenum *)Attachs);
    for(int n=1; n<MaxDrawBuffers; n++){
    	gles_glClearBufferfv(GL_COLOR, n, (const float *)ClearColorValue);
    }*/
    //Printf("GL: DrawBufs_Num=%d \n", DrawBufs_Num);
    if(DrawBufs_Num==0){
    	DrawBufs_Num++;
    	DrawBufs[0]=GL_COLOR_ATTACHMENT0;
    }
    gles_glDrawBuffers(MaxDrawBuffers, (const GLenum *)Attachs);
    //gles_glDrawBuffers(DrawBufs_Num, (const GLenum *)DrawBufs);
    for(int n=0; n<DrawBufs_Num; n++){
    	gles_glClearBufferfv(GL_COLOR, 
    						 DrawBufs[n]-GL_COLOR_ATTACHMENT0, 
    						 (const GLfloat *)ClearColorValue
    						);
 		//Printf("GL: DrawBufs[%d]=%d \n", n, DrawBufs[n]-GL_COLOR_ATTACHMENT0);
    }
 }
 /*
 if((mask&GL_DEPTH_BUFFER_BIT)!=0){
 	gles_glClearBufferfv(GL_DEPTH, 0, (const GLfloat *)ClearDepthValue);
 }
 
 if((mask&GL_STENCIL_BUFFER_BIT)!=0){
 	gles_glClearBufferiv(GL_STENCIL, 0, (const GLint *)ClearStencilValue);
 }
 */
 gles_glClear (mask);
//====
}

void glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){    _LOAD_GLES    
 ClearColorValue[0]=red;
 ClearColorValue[1]=green;
 ClearColorValue[2]=blue;
 ClearColorValue[3]=alpha;
 
 gles_glClearColor (red, green, blue, alpha);
//====
}

void glClearStencil (GLint s){    _LOAD_GLES    
 //ClearStencilValue[0]=s;
 gles_glClearStencil (s);
//====
}

void glClearDepth (GLdouble depth){    _LOAD_GLES    
 //ClearDepthValue[0]=(GLfloat)depth;
 gles_glClearDepthf ((GLfloat)depth);
//====pack
}

void glStencilMask (GLuint mask){    _LOAD_GLES    
 gles_glStencilMask (mask);

}

void glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha){    _LOAD_GLES    
 gles_glColorMask (red, green, blue, alpha);

}

void glDepthMask (GLboolean flag){    _LOAD_GLES    
 gles_glDepthMask (flag);

}

void glDisable (GLenum cap){    _LOAD_GLES    
 gl4es_glDisable (cap);

}

void glEnable (GLenum cap){    _LOAD_GLES    
 gl4es_glEnable (cap);

}

void glFinish (void){    _LOAD_GLES    
 gles_glFinish ();

}

void glFlush (void){    _LOAD_GLES    
 gles_glFlush ();

}

void glBlendFunc (GLenum sfactor, GLenum dfactor){    _LOAD_GLES    
 gles_glBlendFunc (sfactor, dfactor);

}

void glLogicOp (GLenum opcode){    _LOAD_GLES    
 gl4es_glLogicOp (opcode);

}

void glStencilFunc (GLenum func, GLint ref, GLuint mask){    _LOAD_GLES    
 gles_glStencilFunc (func, ref, mask);

}

void glStencilOp (GLenum fail, GLenum zfail, GLenum zpass){    _LOAD_GLES    
 gl4es_glStencilOp (fail, zfail, zpass);

}

void glDepthFunc (GLenum func){    _LOAD_GLES    
 gles_glDepthFunc (func);

}

void glPixelStoref (GLenum pname, GLfloat param){    _LOAD_GLES    
 gl4es_glPixelStoref (pname, param);

}

void glPixelStorei (GLenum pname, GLint param){    _LOAD_GLES    
 gl4es_glPixelStorei (pname, param);

}

void glReadBuffer (GLenum src){    _LOAD_GLES    
 gl4es_glReadBuffer (src);

}

void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels){    _LOAD_GLES    
 gl4es_glReadPixels (x, y, width, height, format, type, pixels);

}

void glGetBooleanv (GLenum pname, GLboolean *data){    _LOAD_GLES    
 gl4es_glGetBooleanv (pname, data);

}

void glGetDoublev (GLenum pname, GLdouble *data){    _LOAD_GLES    
 gl4es_glGetDoublev (pname, data);

}

GLenum glGetError (void){    _LOAD_GLES    
 return gl4es_glGetError ();

}

void glGetFloatv (GLenum pname, GLfloat *data){    _LOAD_GLES    
 gl4es_glGetFloatv (pname, data);

}

void glGetIntegerv (GLenum pname, GLint *data){    _LOAD_GLES    
 gl4es_glGetIntegerv (pname, data);

}

const GLubyte *glGetString (GLenum name){    _LOAD_GLES    
 
 if(name == GL_RENDERER){
  return (const GLubyte *)"holy spawn";
 }
 if(name == GL_VERSION){
  return (const GLubyte *)"3.0";
 }
 if(name == GL_VENDOR){
  return (const GLubyte *)"holy gl4es";
 }
 if(name == GL_SHADING_LANGUAGE_VERSION){
  return (const GLubyte *)"130";
 }
 
 return gles_glGetString (name);

}

void glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels){    _LOAD_GLES    
 gl4es_glGetTexImage (target, level, format, type, pixels);

}

void glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params){    _LOAD_GLES    
 gl4es_glGetTexParameterfv (target, pname, params);

}

void glGetTexParameteriv (GLenum target, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetTexParameteriv (target, pname, params);

}

void glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params){    _LOAD_GLES    
 gl4es_glGetTexLevelParameterfv (target, level, pname, params);

}

void glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetTexLevelParameteriv (target, level, pname, params);

}

GLboolean glIsEnabled (GLenum cap){    _LOAD_GLES    
 return gl4es_glIsEnabled (cap);

}

void glDepthRange (GLdouble n, GLdouble f){    _LOAD_GLES    
 gl4es_glDepthRange (n, f);

}

void glViewport (GLint x, GLint y, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glViewport (x, y, width, height);

}



// GL_VERSION_1_1
void glDrawArrays (GLenum mode, GLint first, GLsizei count){    _LOAD_GLES    
 gl4es_glDrawArrays (mode, first, count);

}

void glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices){    _LOAD_GLES    
 gl4es_glDrawElements (mode, count, type, indices);

}

void glGetPointerv (GLenum pname, void **params){    _LOAD_GLES    
 gl4es_glGetPointerv (pname, params);

}

void glPolygonOffset (GLfloat factor, GLfloat units){    _LOAD_GLES    
 gl4es_glPolygonOffset (factor, units);

}

void glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border){    _LOAD_GLES    
 gl4es_glCopyTexImage1D (target, level, internalformat, x, y, width, border);

}

void glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){    _LOAD_GLES    
 gl4es_glCopyTexImage2D (target, level, internalformat, x, y, width, height, border);

}

void glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){    _LOAD_GLES    
 gl4es_glCopyTexSubImage1D (target, level, xoffset, x, y, width);

}

void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glCopyTexSubImage2D (target, level, xoffset, yoffset, x, y, width, height);

}

void glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexSubImage1D (target, level, xoffset, width, format, type, pixels);

}

void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexSubImage2D (target, level, xoffset, yoffset, width, height, format, type, pixels);

}

void glBindTexture (GLenum target, GLuint texture){    _LOAD_GLES    
 gl4es_glBindTexture (target, texture);

}

void glDeleteTextures (GLsizei n, const GLuint *textures){    _LOAD_GLES    
 gl4es_glDeleteTextures (n, textures);

}

void glGenTextures (GLsizei n, GLuint *textures){    _LOAD_GLES    
 gl4es_glGenTextures (n, textures);

}

GLboolean glIsTexture (GLuint texture){    _LOAD_GLES    
 return gl4es_glIsTexture (texture);

}



// GL_VERSION_1_2
void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices){    _LOAD_GLES    
 gl4es_glDrawRangeElements (mode, start, end, count, type, indices);

}

void glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexImage3D (target, level, internalformat, width, height, depth, border, format, type, pixels);

}

void glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels){    _LOAD_GLES    
 gl4es_glTexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);

}

void glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glCopyTexSubImage3D (target, level, xoffset, yoffset, zoffset, x, y, width, height);

}



// GL_VERSION_1_3
void glActiveTexture (GLenum texture){    _LOAD_GLES    
 gl4es_glActiveTexture (texture);

}

void glSampleCoverage (GLfloat value, GLboolean invert){    _LOAD_GLES    
 gl4es_glSampleCoverage (value, invert);

}

void glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexImage3D (target, level, internalformat, width, height, depth, border, imageSize, data);

}

void glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexImage2D (target, level, internalformat, width, height, border, imageSize, data);

}

void glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexImage1D (target, level, internalformat, width, border, imageSize, data);

}

void glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);

}

void glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexSubImage2D (target, level, xoffset, yoffset, width, height, format, imageSize, data);

}

void glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data){    _LOAD_GLES    
 gl4es_glCompressedTexSubImage1D (target, level, xoffset, width, format, imageSize, data);

}

void glGetCompressedTexImage (GLenum target, GLint level, void *img){    _LOAD_GLES    
 gl4es_glGetCompressedTexImage (target, level, img);

}



// GL_VERSION_1_4
void glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha){    _LOAD_GLES    
 gl4es_glBlendFuncSeparate (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);

}

void glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount){    _LOAD_GLES    
 gl4es_glMultiDrawArrays (mode, first, count, drawcount);

}

void glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount){    _LOAD_GLES    
 gl4es_glMultiDrawElements (mode, count, type, indices, drawcount);

}

void glPointParameterf (GLenum pname, GLfloat param){    _LOAD_GLES    
 gl4es_glPointParameterf (pname, param);

}

void glPointParameterfv (GLenum pname, const GLfloat *params){    _LOAD_GLES    
 gl4es_glPointParameterfv (pname, params);

}

void glPointParameteri (GLenum pname, GLint param){    _LOAD_GLES    
 gl4es_glPointParameteri (pname, param);

}

void glPointParameteriv (GLenum pname, const GLint *params){    _LOAD_GLES    
 gl4es_glPointParameteriv (pname, params);

}

void glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){    _LOAD_GLES    
 gl4es_glBlendColor (red, green, blue, alpha);

}

void glBlendEquation (GLenum mode){    _LOAD_GLES    
 gl4es_glBlendEquation (mode);

}



// GL_VERSION_1_5
void glGenQueries (GLsizei n, GLuint *ids){    _LOAD_GLES    
 gl4es_glGenQueries (n, ids);

}

void glDeleteQueries (GLsizei n, const GLuint *ids){    _LOAD_GLES    
 gl4es_glDeleteQueries (n, ids);

}

GLboolean glIsQuery (GLuint id){    _LOAD_GLES    
 return gl4es_glIsQuery (id);

}

void glBeginQuery (GLenum target, GLuint id){    _LOAD_GLES    
 gl4es_glBeginQuery (target, id);

}

void glEndQuery (GLenum target){    _LOAD_GLES    
 gl4es_glEndQuery (target);

}

void glGetQueryiv (GLenum target, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetQueryiv (target, pname, params);

}

void glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetQueryObjectiv (id, pname, params);

}

void glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params){    _LOAD_GLES    
 gl4es_glGetQueryObjectuiv (id, pname, params);

}

void glBindBuffer (GLenum target, GLuint buffer){    _LOAD_GLES    
 gl4es_glBindBuffer (target, buffer);

}

void glDeleteBuffers (GLsizei n, const GLuint *buffers){    _LOAD_GLES    
 gl4es_glDeleteBuffers (n, buffers);

}

void glGenBuffers (GLsizei n, GLuint *buffers){    _LOAD_GLES    
 gl4es_glGenBuffers (n, buffers);

}

GLboolean glIsBuffer (GLuint buffer){    _LOAD_GLES    
 return gl4es_glIsBuffer (buffer);

}

void glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage){    _LOAD_GLES    
 gl4es_glBufferData (target, size, data, usage);

}

void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data){    _LOAD_GLES    
 gl4es_glBufferSubData (target, offset, size, data);

}

void glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data){    _LOAD_GLES    
 gl4es_glGetBufferSubData (target, offset, size, data);

}

void *glMapBuffer (GLenum target, GLenum access){    _LOAD_GLES    
 return gl4es_glMapBuffer (target, access);

}

GLboolean glUnmapBuffer (GLenum target){    _LOAD_GLES    
 return gl4es_glUnmapBuffer (target);

}

void glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetBufferParameteriv (target, pname, params);

}

void glGetBufferPointerv (GLenum target, GLenum pname, void **params){    _LOAD_GLES    
 gl4es_glGetBufferPointerv (target, pname, params);

}



// GL_VERSION_2_0
void glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha){    _LOAD_GLES    
 gl4es_glBlendEquationSeparate (modeRGB, modeAlpha);

}

void glDrawBuffers (GLsizei n, const GLenum *bufs){    _LOAD_GLES    
/* if(count%num==0){
  for(int x=0; x<n; x++){
   Printf("////////DrawBuffers attachment : %x  //////// n = %d   ////////\n", bufs[x], n);
  }
 }
 count++;
 if(count>50000000){
  count=0;
 }
*/
 /*
 Printf("GL: glDrawBuffers( \n");
 for(GLsizei i=0; i<n; i++){
 	Printf("%x, \n", bufs[i]);
 }
 Printf(") \n");
 */
 
 DrawBufs_Num	=	n;
 for	(int i=0; i<n; i++)	{
 	DrawBufs[i]	=	bufs[i];
 }
 
 gles_glDrawBuffers (n, bufs);

}

void glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass){    _LOAD_GLES    
 gl4es_glStencilOpSeparate (face, sfail, dpfail, dppass);

}

void glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask){    _LOAD_GLES    
 gl4es_glStencilFuncSeparate (face, func, ref, mask);

}

void glStencilMaskSeparate (GLenum face, GLuint mask){    _LOAD_GLES    
 gl4es_glStencilMaskSeparate (face, mask);

}

void glAttachShader (GLuint program, GLuint shader){    _LOAD_GLES    
 gl4es_glAttachShader (program, shader);

}

void glBindAttribLocation (GLuint program, GLuint index, const GLchar *name){    _LOAD_GLES    
 gl4es_glBindAttribLocation (program, index, name);

}

void glCompileShader (GLuint shader){    _LOAD_GLES    
 gl4es_glCompileShader (shader);

}

GLuint glCreateProgram (void){    _LOAD_GLES    
 return gl4es_glCreateProgram ();

}

GLuint glCreateShader (GLenum type){    _LOAD_GLES    
 return gl4es_glCreateShader (type);

}

void glDeleteProgram (GLuint program){    _LOAD_GLES    
 gl4es_glDeleteProgram (program);

}

void glDeleteShader (GLuint shader){    _LOAD_GLES    
 gl4es_glDeleteShader (shader);

}

void glDetachShader (GLuint program, GLuint shader){    _LOAD_GLES    
 gl4es_glDetachShader (program, shader);

}

void glDisableVertexAttribArray (GLuint index){    _LOAD_GLES    
 gl4es_glDisableVertexAttribArray (index);

}

void glEnableVertexAttribArray (GLuint index){    _LOAD_GLES    
 gl4es_glEnableVertexAttribArray (index);

}

void glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name){    _LOAD_GLES    
 gl4es_glGetActiveAttrib (program, index, bufSize, length, size, type, name);

}

void glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name){    _LOAD_GLES    
 gl4es_glGetActiveUniform (program, index, bufSize, length, size, type, name);

}

void glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders){    _LOAD_GLES    
 gl4es_glGetAttachedShaders (program, maxCount, count, shaders);

}

GLint glGetAttribLocation (GLuint program, const GLchar *name){    _LOAD_GLES    
 return gl4es_glGetAttribLocation (program, name);

}

void glGetProgramiv (GLuint program, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetProgramiv (program, pname, params);

}

void glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog){    _LOAD_GLES    
 gl4es_glGetProgramInfoLog (program, bufSize, length, infoLog);

}

void glGetShaderiv (GLuint shader, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetShaderiv (shader, pname, params);

}

void glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog){    _LOAD_GLES    
 gl4es_glGetShaderInfoLog (shader, bufSize, length, infoLog);

}

void glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source){    _LOAD_GLES    
 gl4es_glGetShaderSource (shader, bufSize, length, source);

}

GLint glGetUniformLocation (GLuint program, const GLchar *name){    _LOAD_GLES    
 return gl4es_glGetUniformLocation (program, name);

}

void glGetUniformfv (GLuint program, GLint location, GLfloat *params){    _LOAD_GLES    
 gl4es_glGetUniformfv (program, location, params);

}

void glGetUniformiv (GLuint program, GLint location, GLint *params){    _LOAD_GLES    
 gl4es_glGetUniformiv (program, location, params);

}

void glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params){    _LOAD_GLES    
 gl4es_glGetVertexAttribdv (index, pname, params);

}

void glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params){    _LOAD_GLES    
 gl4es_glGetVertexAttribfv (index, pname, params);

}

void glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetVertexAttribiv (index, pname, params);

}

void glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer){    _LOAD_GLES    
 gl4es_glGetVertexAttribPointerv (index, pname, pointer);

}

GLboolean glIsProgram (GLuint program){    _LOAD_GLES    
 return gl4es_glIsProgram (program);

}

GLboolean glIsShader (GLuint shader){    _LOAD_GLES    
 return gl4es_glIsShader (shader);

}

void glLinkProgram (GLuint program){    _LOAD_GLES    
 gl4es_glLinkProgram (program);

}

void glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length){    _LOAD_GLES    
 
 /*
 char * A[14] = {
  "vec4 gl_FragCoord",
  "#version 110",
  "#version 120",
  "#version 130",
  "#version 140",
  "#version 150",
  "#version 330",
  "#version 400",
  "#version 410",
  "#version 420",
  "#version 430",
  "#version 440",
  "#version 450",
  "#version 460"
  
 };
 char * B[14] = {
  "highp vec4 gl_FragCoord",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es",
  "#version 320 es"
  
 };
 
 int number = 14;	// Number of strings to be processed.
 
 GLint length1[count];
 
 
 GLchar * ptr;
 ptr = shaderconv (number, A, B, *string, length1, length, count);
 
 const GLchar *const*string1 = (const GLchar *const*)(&ptr);
 
 if(length == NULL){
  gl4es_glShaderSource (shader, count, string1, NULL);
 }
 else{
  gl4es_glShaderSource (shader, count, string1, length1);
 }
 Printf("Calling glShaderSource() succeed!");
 
 free(ptr);
 */
 
 gl4es_glShaderSource (shader, count, string, length);
 
}

void glUseProgram (GLuint program){    _LOAD_GLES    
 gl4es_glUseProgram (program);

}

void glUniform1f (GLint location, GLfloat v0){    _LOAD_GLES    
 gl4es_glUniform1f (location, v0);

}

void glUniform2f (GLint location, GLfloat v0, GLfloat v1){    _LOAD_GLES    
 gl4es_glUniform2f (location, v0, v1);

}

void glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2){    _LOAD_GLES    
 gl4es_glUniform3f (location, v0, v1, v2);

}

void glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){    _LOAD_GLES    
 gl4es_glUniform4f (location, v0, v1, v2, v3);

}

void glUniform1i (GLint location, GLint v0){    _LOAD_GLES    
 gl4es_glUniform1i (location, v0);

}

void glUniform2i (GLint location, GLint v0, GLint v1){    _LOAD_GLES    
 gl4es_glUniform2i (location, v0, v1);

}

void glUniform3i (GLint location, GLint v0, GLint v1, GLint v2){    _LOAD_GLES    
 gl4es_glUniform3i (location, v0, v1, v2);

}

void glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3){    _LOAD_GLES    
 gl4es_glUniform4i (location, v0, v1, v2, v3);

}

void glUniform1fv (GLint location, GLsizei count, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniform1fv (location, count, value);

}

void glUniform2fv (GLint location, GLsizei count, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniform2fv (location, count, value);

}

void glUniform3fv (GLint location, GLsizei count, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniform3fv (location, count, value);

}

void glUniform4fv (GLint location, GLsizei count, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniform4fv (location, count, value);

}

void glUniform1iv (GLint location, GLsizei count, const GLint *value){    _LOAD_GLES    
 gl4es_glUniform1iv (location, count, value);

}

void glUniform2iv (GLint location, GLsizei count, const GLint *value){    _LOAD_GLES    
 gl4es_glUniform2iv (location, count, value);

}

void glUniform3iv (GLint location, GLsizei count, const GLint *value){    _LOAD_GLES    
 gl4es_glUniform3iv (location, count, value);

}

void glUniform4iv (GLint location, GLsizei count, const GLint *value){    _LOAD_GLES    
 gl4es_glUniform4iv (location, count, value);

}

void glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniformMatrix2fv (location, count, transpose, value);

}

void glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniformMatrix3fv (location, count, transpose, value);

}

void glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gl4es_glUniformMatrix4fv (location, count, transpose, value);

}

void glValidateProgram (GLuint program){    _LOAD_GLES    
 gl4es_glValidateProgram (program);

}

void glVertexAttrib1d (GLuint index, GLdouble x){    _LOAD_GLES    
 gl4es_glVertexAttrib1d (index, x);

}

void glVertexAttrib1dv (GLuint index, const GLdouble *v){    _LOAD_GLES    
 gl4es_glVertexAttrib1dv (index, v);

}

void glVertexAttrib1f (GLuint index, GLfloat x){    _LOAD_GLES    
 gl4es_glVertexAttrib1f (index, x);

}

void glVertexAttrib1fv (GLuint index, const GLfloat *v){    _LOAD_GLES    
 gl4es_glVertexAttrib1fv (index, v);

}

void glVertexAttrib1s (GLuint index, GLshort x){    _LOAD_GLES    
 gl4es_glVertexAttrib1s (index, x);

}

void glVertexAttrib1sv (GLuint index, const GLshort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib1sv (index, v);

}

void glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y){    _LOAD_GLES    
 gl4es_glVertexAttrib2d (index, x, y);

}

void glVertexAttrib2dv (GLuint index, const GLdouble *v){    _LOAD_GLES    
 gl4es_glVertexAttrib2dv (index, v);

}

void glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y){    _LOAD_GLES    
 gl4es_glVertexAttrib2f (index, x, y);

}

void glVertexAttrib2fv (GLuint index, const GLfloat *v){    _LOAD_GLES    
 gl4es_glVertexAttrib2fv (index, v);

}

void glVertexAttrib2s (GLuint index, GLshort x, GLshort y){    _LOAD_GLES    
 gl4es_glVertexAttrib2s (index, x, y);

}

void glVertexAttrib2sv (GLuint index, const GLshort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib2sv (index, v);

}

void glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z){    _LOAD_GLES    
 gl4es_glVertexAttrib3d (index, x, y, z);

}

void glVertexAttrib3dv (GLuint index, const GLdouble *v){    _LOAD_GLES    
 gl4es_glVertexAttrib3dv (index, v);

}

void glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z){    _LOAD_GLES    
 gl4es_glVertexAttrib3f (index, x, y, z);

}

void glVertexAttrib3fv (GLuint index, const GLfloat *v){    _LOAD_GLES    
 gl4es_glVertexAttrib3fv (index, v);

}

void glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z){    _LOAD_GLES    
 gl4es_glVertexAttrib3s (index, x, y, z);

}

void glVertexAttrib3sv (GLuint index, const GLshort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib3sv (index, v);

}

void glVertexAttrib4Nbv (GLuint index, const GLbyte *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nbv (index, v);

}

void glVertexAttrib4Niv (GLuint index, const GLint *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Niv (index, v);

}

void glVertexAttrib4Nsv (GLuint index, const GLshort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nsv (index, v);

}

void glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nub (index, x, y, z, w);

}

void glVertexAttrib4Nubv (GLuint index, const GLubyte *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nubv (index, v);

}

void glVertexAttrib4Nuiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nuiv (index, v);

}

void glVertexAttrib4Nusv (GLuint index, const GLushort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4Nusv (index, v);

}

void glVertexAttrib4bv (GLuint index, const GLbyte *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4bv (index, v);

}

void glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){    _LOAD_GLES    
 gl4es_glVertexAttrib4d (index, x, y, z, w);

}

void glVertexAttrib4dv (GLuint index, const GLdouble *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4dv (index, v);

}

void glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){    _LOAD_GLES    
 gl4es_glVertexAttrib4f (index, x, y, z, w);

}

void glVertexAttrib4fv (GLuint index, const GLfloat *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4fv (index, v);

}

void glVertexAttrib4iv (GLuint index, const GLint *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4iv (index, v);

}

void glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w){    _LOAD_GLES    
 gl4es_glVertexAttrib4s (index, x, y, z, w);

}

void glVertexAttrib4sv (GLuint index, const GLshort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4sv (index, v);

}

void glVertexAttrib4ubv (GLuint index, const GLubyte *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4ubv (index, v);

}

void glVertexAttrib4uiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4uiv (index, v);

}

void glVertexAttrib4usv (GLuint index, const GLushort *v){    _LOAD_GLES    
 gl4es_glVertexAttrib4usv (index, v);

}

void glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer){    _LOAD_GLES    
 gl4es_glVertexAttribPointer (index, size, type, normalized, stride, pointer);

}



// GL_VERSION_2_1
void glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix2x3fv (location, count, transpose, value);

}

void glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix3x2fv (location, count, transpose, value);

}

void glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix2x4fv (location, count, transpose, value);

}

void glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix4x2fv (location, count, transpose, value);

}

void glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix3x4fv (location, count, transpose, value);

}

void glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){    _LOAD_GLES    
 gles_glUniformMatrix4x3fv (location, count, transpose, value);

}



// GL_VERSION_3_0
void glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a){    _LOAD_GLES    
 gles_glColorMaski (index, r, g, b, a);

}

void glGetBooleani_v (GLenum target, GLuint index, GLboolean *data){    _LOAD_GLES    
 gles_glGetBooleani_v (target, index, data);

}

void glGetIntegeri_v (GLenum target, GLuint index, GLint *data){    _LOAD_GLES    
 gles_glGetIntegeri_v (target, index, data);

}

void glEnablei (GLenum target, GLuint index){    _LOAD_GLES    
 gles_glEnablei (target, index);

}

void glDisablei (GLenum target, GLuint index){    _LOAD_GLES    
 gles_glDisablei (target, index);

}

GLboolean glIsEnabledi (GLenum target, GLuint index){    _LOAD_GLES    
 return gles_glIsEnabledi (target, index);

}

void glBeginTransformFeedback (GLenum primitiveMode){    _LOAD_GLES    
 gles_glBeginTransformFeedback (primitiveMode);

}

void glEndTransformFeedback (void){    _LOAD_GLES    
 gles_glEndTransformFeedback ();

}

void glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){    _LOAD_GLES    
 gles_glBindBufferRange (target, index, buffer, offset, size);

}

void glBindBufferBase (GLenum target, GLuint index, GLuint buffer){    _LOAD_GLES    
 gles_glBindBufferBase (target, index, buffer);

}

void glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode){    _LOAD_GLES    
 gles_glTransformFeedbackVaryings (program, count, varyings, bufferMode);

}

void glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name){    _LOAD_GLES    
 gles_glGetTransformFeedbackVarying (program, index, bufSize, length, size, type, name);

}

void glClampColor (GLenum target, GLenum clamp){    _LOAD_GLES    
 gl4es_glClampColor (target, clamp);

}

void glBeginConditionalRender (GLuint id, GLenum mode){    _LOAD_GLES    
;// gles_glBeginConditionalRender (id, mode);

}

void glEndConditionalRender (void){    _LOAD_GLES    
;// gles_glEndConditionalRender ();

}

void glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer){    _LOAD_GLES    
 gles_glVertexAttribIPointer (index, size, type, stride, pointer);				// Direct conversion to int.

}

void glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params){    _LOAD_GLES    
 gles_glGetVertexAttribIiv (index, pname, params);

}

void glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params){    _LOAD_GLES    
 gles_glGetVertexAttribIuiv (index, pname, params);

}

void glVertexAttribI1i (GLuint index, GLint x){    _LOAD_GLES    
 gles_glVertexAttribI4i (index, x, 0, 0, 1);

}

void glVertexAttribI2i (GLuint index, GLint x, GLint y){    _LOAD_GLES    
 gles_glVertexAttribI4i (index, x, y, 0, 1);

}

void glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z){    _LOAD_GLES    
 gles_glVertexAttribI4i (index, x, y, z, 1);

}

void glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w){    _LOAD_GLES    
 gles_glVertexAttribI4i (index, x, y, z, w);

}

void glVertexAttribI1ui (GLuint index, GLuint x){    _LOAD_GLES    
 gles_glVertexAttribI4ui (index, x, 0, 0, 1);

}

void glVertexAttribI2ui (GLuint index, GLuint x, GLuint y){    _LOAD_GLES    
 gles_glVertexAttribI4ui (index, x, y, 0, 1);

}

void glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z){    _LOAD_GLES    
 gles_glVertexAttribI4ui (index, x, y, z, 1);

}

void glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){    _LOAD_GLES    
 gles_glVertexAttribI4ui (index, x, y, z, w);

}

void glVertexAttribI1iv (GLuint index, const GLint *v){    _LOAD_GLES    
 const GLint v1[4] = {v[0], 0, 0, 1};
 gles_glVertexAttribI4iv (index, v1);

}

void glVertexAttribI2iv (GLuint index, const GLint *v){    _LOAD_GLES    
 const GLint v1[4] = {v[0], v[1], 0, 1};
 gles_glVertexAttribI4iv (index, v1);
}

void glVertexAttribI3iv (GLuint index, const GLint *v){    _LOAD_GLES    
 const GLint v1[4] = {v[0], v[1], v[2], 1};
 gles_glVertexAttribI4iv (index, v1);

}

void glVertexAttribI4iv (GLuint index, const GLint *v){    _LOAD_GLES    
 gles_glVertexAttribI4iv (index, v);

}

void glVertexAttribI1uiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 const GLuint v1[4] = {v[0], 0, 0, 1};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI2uiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 const GLuint v1[4] = {v[0], v[1], 0, 1};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI3uiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 const GLuint v1[4] = {v[0], v[1], v[2], 1};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI4uiv (GLuint index, const GLuint *v){    _LOAD_GLES    
 gles_glVertexAttribI4uiv (index, v);

}

void glVertexAttribI4bv (GLuint index, const GLbyte *v){    _LOAD_GLES    
 const GLuint v1[4] = {(GLuint)v[0], (GLuint)v[1], (GLuint)v[3], (GLuint)v[3]};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI4sv (GLuint index, const GLshort *v){    _LOAD_GLES    
 const GLuint v1[4] = {(GLuint)v[0], (GLuint)v[1], (GLuint)v[2], (GLuint)v[3]};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI4ubv (GLuint index, const GLubyte *v){    _LOAD_GLES    
 const GLuint v1[4] = {(GLuint)v[0], (GLuint)v[1], (GLuint)v[2], (GLuint)v[3]};
 gles_glVertexAttribI4uiv (index, v1);
}

void glVertexAttribI4usv (GLuint index, const GLushort *v){    _LOAD_GLES    
 const GLuint v1[4] = {(GLuint)v[0], (GLuint)v[1], (GLuint)v[2], (GLuint)v[3]};
 gles_glVertexAttribI4uiv (index, v1);
}

void glGetUniformuiv (GLuint program, GLint location, GLuint *params){    _LOAD_GLES    
 gles_glGetUniformuiv (program, location, params);

}

void glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name){    _LOAD_GLES    
;// gles_glBindFragDataLocation (program, color, name);

}

GLint glGetFragDataLocation (GLuint program, const GLchar *name){    _LOAD_GLES    
 return gles_glGetFragDataLocation (program, name);

}

void glUniform1ui (GLint location, GLuint v0){    _LOAD_GLES    
 gles_glUniform1ui (location, v0);

}

void glUniform2ui (GLint location, GLuint v0, GLuint v1){    _LOAD_GLES    
 gles_glUniform2ui (location, v0, v1);

}

void glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2){    _LOAD_GLES    
 gles_glUniform3ui (location, v0, v1, v2);

}

void glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){    _LOAD_GLES    
 gles_glUniform4ui (location, v0, v1, v2, v3);

}

void glUniform1uiv (GLint location, GLsizei count, const GLuint *value){    _LOAD_GLES    
 gles_glUniform1uiv (location, count, value);

}

void glUniform2uiv (GLint location, GLsizei count, const GLuint *value){    _LOAD_GLES    
 gles_glUniform2uiv (location, count, value);

}

void glUniform3uiv (GLint location, GLsizei count, const GLuint *value){    _LOAD_GLES    
 gles_glUniform3uiv (location, count, value);

}

void glUniform4uiv (GLint location, GLsizei count, const GLuint *value){    _LOAD_GLES    
 gles_glUniform4uiv (location, count, value);

}

void glTexParameterIiv (GLenum target, GLenum pname, const GLint *params){    _LOAD_GLES    
 gles_glTexParameterIiv (target, pname, params);

}

void glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params){    _LOAD_GLES    
 gles_glTexParameterIuiv (target, pname, params);

}

void glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params){    _LOAD_GLES    
 gles_glGetTexParameterIiv (target, pname, params);

}

void glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params){    _LOAD_GLES    
 gles_glGetTexParameterIuiv (target, pname, params);

}

void glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value){    _LOAD_GLES    
 //gles_glDrawBuffers(1, (const GLenum *)(Attachs+drawbuffer));
 //Printf("VGPU: Calling glClearBufferiv()\n");
 gles_glClearBufferiv (buffer, drawbuffer, value);
//====
}

void glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value){    _LOAD_GLES    
 //gles_glDrawBuffers(1, (const GLenum *)(Attachs+drawbuffer));
 //Printf("VGPU: Calling glClearBufferuiv()\n");
 gles_glClearBufferuiv (buffer, drawbuffer, value);
//====
}

void glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value){    _LOAD_GLES    
 //gles_glDrawBuffers(1, (const GLenum *)(Attachs+drawbuffer));
 //Printf("VGPU: Calling glClearBufferfv()\n");
 gles_glClearBufferfv (buffer, drawbuffer, value);
//====
}

void glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil){    _LOAD_GLES    
 //gles_glDrawBuffers(1, (const GLenum *)(Attachs+drawbuffer));
 //Printf("VGPU: Calling glClearBufferfi()\n");
 gles_glClearBufferfi (buffer, drawbuffer, depth, stencil);
//====
}

const GLubyte *glGetStringi (GLenum name, GLuint index){    _LOAD_GLES    
 return gl4es_glGetStringi (name, index);

}

GLboolean glIsRenderbuffer (GLuint renderbuffer){    _LOAD_GLES    
 return gl4es_glIsRenderbuffer (renderbuffer);

}

void glBindRenderbuffer (GLenum target, GLuint renderbuffer){    _LOAD_GLES    
 gl4es_glBindRenderbuffer (target, renderbuffer);

}

void glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers){    _LOAD_GLES    
 gl4es_glDeleteRenderbuffers (n, renderbuffers);

}

void glGenRenderbuffers (GLsizei n, GLuint *renderbuffers){    _LOAD_GLES    
 gl4es_glGenRenderbuffers (n, renderbuffers);

}

void glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glRenderbufferStorage (target, internalformat, width, height);

}

void glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params){    _LOAD_GLES    
 gl4es_glGetRenderbufferParameteriv (target, pname, params);

}

GLboolean glIsFramebuffer (GLuint framebuffer){    _LOAD_GLES    
 return gl4es_glIsFramebuffer (framebuffer);

}

void glBindFramebuffer (GLenum target, GLuint framebuffer){    _LOAD_GLES    
 gl4es_glBindFramebuffer (target, framebuffer);

}

void glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers){    _LOAD_GLES    
 gl4es_glDeleteFramebuffers (n, framebuffers);

}

void glGenFramebuffers (GLsizei n, GLuint *framebuffers){    _LOAD_GLES    
 gl4es_glGenFramebuffers (n, framebuffers);

}

GLenum glCheckFramebufferStatus (GLenum target){    _LOAD_GLES    
 return gl4es_glCheckFramebufferStatus (target);

}

void glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){    _LOAD_GLES    
 gl4es_glFramebufferTexture1D (target, attachment, textarget, texture, level);

}

void glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){    _LOAD_GLES    
/* if(count%num==0){
  Printf("////////FramebufferTexture2D attachment : %x  ////////\n", attachment);
 }
 count++;
 if(count>50000000){
  count=0;
 }
*/
 gles_glFramebufferTexture2D (target, attachment, textarget, texture, level);

}

void glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset){    _LOAD_GLES    
 gl4es_glFramebufferTexture3D (target, attachment, textarget, texture, level, zoffset);

}

void glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){    _LOAD_GLES    
 gles_glFramebufferRenderbuffer (target, attachment, renderbuffertarget, renderbuffer);

}

void glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params){    _LOAD_GLES    
 gles_glGetFramebufferAttachmentParameteriv (target, attachment, pname, params);

}

void glGenerateMipmap (GLenum target){    _LOAD_GLES    
 gl4es_glGenerateMipmap (target);

}

void glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){    _LOAD_GLES    
 gl4es_glBlitFramebuffer (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

}

void glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){    _LOAD_GLES    
 gl4es_glRenderbufferStorageMultisample (target, samples, internalformat, width, height);

}

void glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer){    _LOAD_GLES    
 gles_glFramebufferTextureLayer (target, attachment, texture, level, layer);

}

void *glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access){    _LOAD_GLES    
 return gl4es_glMapBufferRange (target, offset, length, access);

}

void glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length){    _LOAD_GLES    
 gl4es_glFlushMappedBufferRange (target, offset, length);

}

void glBindVertexArray (GLuint array){    _LOAD_GLES    
 gl4es_glBindVertexArray (array);

}

void glDeleteVertexArrays (GLsizei n, const GLuint *arrays){    _LOAD_GLES    
 gl4es_glDeleteVertexArrays (n, arrays);

}

void glGenVertexArrays (GLsizei n, GLuint *arrays){    _LOAD_GLES    
 gl4es_glGenVertexArrays (n, arrays);

}

GLboolean glIsVertexArray (GLuint array){    _LOAD_GLES    
 return gl4es_glIsVertexArray (array);

}






