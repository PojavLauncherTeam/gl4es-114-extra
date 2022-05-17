// OpenGL 2.0 >> 3.0

// Simplified version of the header file


#include "pack.h"

#define GLAPI extern





// GL_VERSION_1_0

GLAPI void gl4es_glCullFace (GLenum mode);
GLAPI void gl4es_glFrontFace (GLenum mode);
GLAPI void gl4es_glHint (GLenum target, GLenum mode);
GLAPI void gl4es_glLineWidth (GLfloat width);
GLAPI void gl4es_glPointSize (GLfloat size);
GLAPI void gl4es_glPolygonMode (GLenum face, GLenum mode);
GLAPI void gl4es_glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void gl4es_glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GLAPI void gl4es_glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void gl4es_glTexParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void gl4es_glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void gl4es_glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glDrawBuffer (GLenum buf);
GLAPI void gl4es_glClear (GLbitfield mask);
GLAPI void gl4es_glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void gl4es_glClearStencil (GLint s);
GLAPI void gl4es_glClearDepth (GLdouble depth);
GLAPI void gl4es_glStencilMask (GLuint mask);
GLAPI void gl4es_glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void gl4es_glDepthMask (GLboolean flag);
GLAPI void gl4es_glDisable (GLenum cap);
GLAPI void gl4es_glEnable (GLenum cap);
GLAPI void gl4es_glFinish (void);
GLAPI void gl4es_glFlush (void);
GLAPI void gl4es_glBlendFunc (GLenum sfactor, GLenum dfactor);
GLAPI void gl4es_glLogicOp (GLenum opcode);
GLAPI void gl4es_glStencilFunc (GLenum func, GLint ref, GLuint mask);
GLAPI void gl4es_glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void gl4es_glDepthFunc (GLenum func);
GLAPI void gl4es_glPixelStoref (GLenum pname, GLfloat param);
GLAPI void gl4es_glPixelStorei (GLenum pname, GLint param);
GLAPI void gl4es_glReadBuffer (GLenum src);
GLAPI void gl4es_glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void gl4es_glGetBooleanv (GLenum pname, GLboolean *data);
GLAPI void gl4es_glGetDoublev (GLenum pname, GLdouble *data);
GLAPI GLenum gl4es_glGetError (void);
GLAPI void gl4es_glGetFloatv (GLenum pname, GLfloat *data);
GLAPI void gl4es_glGetIntegerv (GLenum pname, GLint *data);
GLAPI const GLubyte *gl4es_glGetString (GLenum name);
GLAPI void gl4es_glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void gl4es_glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void gl4es_glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void gl4es_glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void gl4es_glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean gl4es_glIsEnabled (GLenum cap);
GLAPI void gl4es_glDepthRange (GLdouble n, GLdouble f);
GLAPI void gl4es_glViewport (GLint x, GLint y, GLsizei width, GLsizei height);


// GL_VERSION_1_1

GLAPI void gl4es_glDrawArrays (GLenum mode, GLint first, GLsizei count);
GLAPI void gl4es_glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI void gl4es_glGetPointerv (GLenum pname, void **params);
GLAPI void gl4es_glPolygonOffset (GLfloat factor, GLfloat units);
GLAPI void gl4es_glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void gl4es_glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void gl4es_glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void gl4es_glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void gl4es_glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glBindTexture (GLenum target, GLuint texture);
GLAPI void gl4es_glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void gl4es_glGenTextures (GLsizei n, GLuint *textures);
GLAPI GLboolean gl4es_glIsTexture (GLuint texture);


// GL_VERSION_1_2

GLAPI void gl4es_glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void gl4es_glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void gl4es_glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);


// GL_VERSION_1_3

GLAPI void gl4es_glActiveTexture (GLenum texture);
GLAPI void gl4es_glSampleCoverage (GLfloat value, GLboolean invert);
GLAPI void gl4es_glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void gl4es_glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void gl4es_glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void gl4es_glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void gl4es_glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void gl4es_glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void gl4es_glGetCompressedTexImage (GLenum target, GLint level, void *img);


// GL_VERSION_1_4

GLAPI void gl4es_glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void gl4es_glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void gl4es_glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void gl4es_glPointParameterf (GLenum pname, GLfloat param);
GLAPI void gl4es_glPointParameterfv (GLenum pname, const GLfloat *params);
GLAPI void gl4es_glPointParameteri (GLenum pname, GLint param);
GLAPI void gl4es_glPointParameteriv (GLenum pname, const GLint *params);
GLAPI void gl4es_glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void gl4es_glBlendEquation (GLenum mode);


// GL_VERSION_1_5

GLAPI void gl4es_glGenQueries (GLsizei n, GLuint *ids);
GLAPI void gl4es_glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean gl4es_glIsQuery (GLuint id);
GLAPI void gl4es_glBeginQuery (GLenum target, GLuint id);
GLAPI void gl4es_glEndQuery (GLenum target);
GLAPI void gl4es_glGetQueryiv (GLenum target, GLenum pname, GLint *params);
GLAPI void gl4es_glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void gl4es_glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void gl4es_glBindBuffer (GLenum target, GLuint buffer);
GLAPI void gl4es_glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void gl4es_glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI GLboolean gl4es_glIsBuffer (GLuint buffer);
GLAPI void gl4es_glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void gl4es_glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void gl4es_glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *gl4es_glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean gl4es_glUnmapBuffer (GLenum target);
GLAPI void gl4es_glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void gl4es_glGetBufferPointerv (GLenum target, GLenum pname, void **params);


// GL_VERSION_2_0

GLAPI void gl4es_glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
GLAPI void gl4es_glDrawBuffers (GLsizei n, const GLenum *bufs);
GLAPI void gl4es_glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void gl4es_glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void gl4es_glStencilMaskSeparate (GLenum face, GLuint mask);
GLAPI void gl4es_glAttachShader (GLuint program, GLuint shader);
GLAPI void gl4es_glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
GLAPI void gl4es_glCompileShader (GLuint shader);
GLAPI GLuint gl4es_glCreateProgram (void);
GLAPI GLuint gl4es_glCreateShader (GLenum type);
GLAPI void gl4es_glDeleteProgram (GLuint program);
GLAPI void gl4es_glDeleteShader (GLuint shader);
GLAPI void gl4es_glDetachShader (GLuint program, GLuint shader);
GLAPI void gl4es_glDisableVertexAttribArray (GLuint index);
GLAPI void gl4es_glEnableVertexAttribArray (GLuint index);
GLAPI void gl4es_glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void gl4es_glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void gl4es_glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint gl4es_glGetAttribLocation (GLuint program, const GLchar *name);
GLAPI void gl4es_glGetProgramiv (GLuint program, GLenum pname, GLint *params);
GLAPI void gl4es_glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void gl4es_glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
GLAPI void gl4es_glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void gl4es_glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint gl4es_glGetUniformLocation (GLuint program, const GLchar *name);
GLAPI void gl4es_glGetUniformfv (GLuint program, GLint location, GLfloat *params);
GLAPI void gl4es_glGetUniformiv (GLuint program, GLint location, GLint *params);
GLAPI void gl4es_glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void gl4es_glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
GLAPI void gl4es_glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
GLAPI void gl4es_glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean gl4es_glIsProgram (GLuint program);
GLAPI GLboolean gl4es_glIsShader (GLuint shader);
GLAPI void gl4es_glLinkProgram (GLuint program);
GLAPI void gl4es_glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void gl4es_glUseProgram (GLuint program);
GLAPI void gl4es_glUniform1f (GLint location, GLfloat v0);
GLAPI void gl4es_glUniform2f (GLint location, GLfloat v0, GLfloat v1);
GLAPI void gl4es_glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void gl4es_glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void gl4es_glUniform1i (GLint location, GLint v0);
GLAPI void gl4es_glUniform2i (GLint location, GLint v0, GLint v1);
GLAPI void gl4es_glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void gl4es_glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void gl4es_glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void gl4es_glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void gl4es_glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void gl4es_glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void gl4es_glUniform1iv (GLint location, GLsizei count, const GLint *value);
GLAPI void gl4es_glUniform2iv (GLint location, GLsizei count, const GLint *value);
GLAPI void gl4es_glUniform3iv (GLint location, GLsizei count, const GLint *value);
GLAPI void gl4es_glUniform4iv (GLint location, GLsizei count, const GLint *value);
GLAPI void gl4es_glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glValidateProgram (GLuint program);
GLAPI void gl4es_glVertexAttrib1d (GLuint index, GLdouble x);
GLAPI void gl4es_glVertexAttrib1dv (GLuint index, const GLdouble *v);
GLAPI void gl4es_glVertexAttrib1f (GLuint index, GLfloat x);
GLAPI void gl4es_glVertexAttrib1fv (GLuint index, const GLfloat *v);
GLAPI void gl4es_glVertexAttrib1s (GLuint index, GLshort x);
GLAPI void gl4es_glVertexAttrib1sv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void gl4es_glVertexAttrib2dv (GLuint index, const GLdouble *v);
GLAPI void gl4es_glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
GLAPI void gl4es_glVertexAttrib2fv (GLuint index, const GLfloat *v);
GLAPI void gl4es_glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
GLAPI void gl4es_glVertexAttrib2sv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void gl4es_glVertexAttrib3dv (GLuint index, const GLdouble *v);
GLAPI void gl4es_glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void gl4es_glVertexAttrib3fv (GLuint index, const GLfloat *v);
GLAPI void gl4es_glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void gl4es_glVertexAttrib3sv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
GLAPI void gl4es_glVertexAttrib4Niv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttrib4Nsv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void gl4es_glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
GLAPI void gl4es_glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttrib4Nusv (GLuint index, const GLushort *v);
GLAPI void gl4es_glVertexAttrib4bv (GLuint index, const GLbyte *v);
GLAPI void gl4es_glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void gl4es_glVertexAttrib4dv (GLuint index, const GLdouble *v);
GLAPI void gl4es_glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void gl4es_glVertexAttrib4fv (GLuint index, const GLfloat *v);
GLAPI void gl4es_glVertexAttrib4iv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void gl4es_glVertexAttrib4sv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttrib4ubv (GLuint index, const GLubyte *v);
GLAPI void gl4es_glVertexAttrib4uiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttrib4usv (GLuint index, const GLushort *v);
GLAPI void gl4es_glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);


// GL_VERSION_2_1

GLAPI void gl4es_glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void gl4es_glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);


// GL_VERSION_3_0

GLAPI void gl4es_glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void gl4es_glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
GLAPI void gl4es_glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
GLAPI void gl4es_glEnablei (GLenum target, GLuint index);
GLAPI void gl4es_glDisablei (GLenum target, GLuint index);
GLAPI GLboolean gl4es_glIsEnabledi (GLenum target, GLuint index);
GLAPI void gl4es_glBeginTransformFeedback (GLenum primitiveMode);
GLAPI void gl4es_glEndTransformFeedback (void);
GLAPI void gl4es_glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void gl4es_glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
GLAPI void gl4es_glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void gl4es_glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void gl4es_glClampColor (GLenum target, GLenum clamp);
GLAPI void gl4es_glBeginConditionalRender (GLuint id, GLenum mode);
GLAPI void gl4es_glEndConditionalRender (void);
GLAPI void gl4es_glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void gl4es_glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
GLAPI void gl4es_glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
GLAPI void gl4es_glVertexAttribI1i (GLuint index, GLint x);
GLAPI void gl4es_glVertexAttribI2i (GLuint index, GLint x, GLint y);
GLAPI void gl4es_glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
GLAPI void gl4es_glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void gl4es_glVertexAttribI1ui (GLuint index, GLuint x);
GLAPI void gl4es_glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
GLAPI void gl4es_glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void gl4es_glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void gl4es_glVertexAttribI1iv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttribI2iv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttribI3iv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttribI4iv (GLuint index, const GLint *v);
GLAPI void gl4es_glVertexAttribI1uiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttribI2uiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttribI3uiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttribI4uiv (GLuint index, const GLuint *v);
GLAPI void gl4es_glVertexAttribI4bv (GLuint index, const GLbyte *v);
GLAPI void gl4es_glVertexAttribI4sv (GLuint index, const GLshort *v);
GLAPI void gl4es_glVertexAttribI4ubv (GLuint index, const GLubyte *v);
GLAPI void gl4es_glVertexAttribI4usv (GLuint index, const GLushort *v);
GLAPI void gl4es_glGetUniformuiv (GLuint program, GLint location, GLuint *params);
GLAPI void gl4es_glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
GLAPI GLint gl4es_glGetFragDataLocation (GLuint program, const GLchar *name);
GLAPI void gl4es_glUniform1ui (GLint location, GLuint v0);
GLAPI void gl4es_glUniform2ui (GLint location, GLuint v0, GLuint v1);
GLAPI void gl4es_glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void gl4es_glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void gl4es_glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void gl4es_glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void gl4es_glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void gl4es_glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void gl4es_glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
GLAPI void gl4es_glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
GLAPI void gl4es_glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
GLAPI void gl4es_glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
GLAPI void gl4es_glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void gl4es_glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void gl4es_glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void gl4es_glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *gl4es_glGetStringi (GLenum name, GLuint index);
GLAPI GLboolean gl4es_glIsRenderbuffer (GLuint renderbuffer);
GLAPI void gl4es_glBindRenderbuffer (GLenum target, GLuint renderbuffer);
GLAPI void gl4es_glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
GLAPI void gl4es_glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void gl4es_glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void gl4es_glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean gl4es_glIsFramebuffer (GLuint framebuffer);
GLAPI void gl4es_glBindFramebuffer (GLenum target, GLuint framebuffer);
GLAPI void gl4es_glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
GLAPI void gl4es_glGenFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI GLenum gl4es_glCheckFramebufferStatus (GLenum target);
GLAPI void gl4es_glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void gl4es_glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void gl4es_glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void gl4es_glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void gl4es_glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void gl4es_glGenerateMipmap (GLenum target);
GLAPI void gl4es_glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void gl4es_glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void gl4es_glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *gl4es_glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void gl4es_glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void gl4es_glBindVertexArray (GLuint array);
GLAPI void gl4es_glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
GLAPI void gl4es_glGenVertexArrays (GLsizei n, GLuint *arrays);
GLAPI GLboolean gl4es_glIsVertexArray (GLuint array);

