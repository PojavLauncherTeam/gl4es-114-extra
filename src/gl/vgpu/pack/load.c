#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "load_.h"
#include "Initialization.h"

int loaded = 0;
const char *LIB_GLES_NAME = "libGLESv2.so"/*"libGLESv2_angle.so"*/;
const char *LIB_EGL_NAME = "libEGL.so"/*"libEGL_angle.so"*/;

void load_all(void){
	
	printf("VGPU: Calling load_all()\n");
	loaded++;
	if(loaded)
	printf("VGPU: loaded succeed\n");
	
	void* libGL;
	char* gles_ = getenv("LIBGL_GLES");
	int flags = RTLD_LOCAL | RTLD_NOW;
	
	libGL = dlopen(LIB_GLES_NAME, flags);
	/*if(libGL == NULL)
		libGL = dlopen("libGLESv2.so", flags);
	*/
	if(libGL == NULL) {
		printf("VGPU: load_all(): failed to dlopen \"%s\" \n", LIB_GLES_NAME);
		loaded = 0;
		return;
	}
	
//	if(libGL == NULL)
//		libGL = dlopen(gles_, flags);
	
// Find the addresses of all the GLES functions,
// and assign them to the corresponding gles_glFunction,
// so that the gles_glFunction can be called in pack.c.


// GL_ES_VERSION_2_0
/*PFNglActiveTexture */    gles_glActiveTexture = (PTR_glActiveTexture)dlsym(libGL, "glActiveTexture");
/*PFNglAttachShader */    gles_glAttachShader = (PTR_glAttachShader)dlsym(libGL, "glAttachShader");
/*PFNglBindAttribLocation */    gles_glBindAttribLocation = (PTR_glBindAttribLocation)dlsym(libGL, "glBindAttribLocation");
/*PFNglBindBuffer */    gles_glBindBuffer = (PTR_glBindBuffer)dlsym(libGL, "glBindBuffer");
/*PFNglBindFramebuffer */    gles_glBindFramebuffer = (PTR_glBindFramebuffer)dlsym(libGL, "glBindFramebuffer");
/*PFNglBindRenderbuffer */    gles_glBindRenderbuffer = (PTR_glBindRenderbuffer)dlsym(libGL, "glBindRenderbuffer");
/*PFNglBindTexture */    gles_glBindTexture = (PTR_glBindTexture)dlsym(libGL, "glBindTexture");
/*PFNglBlendColor */    gles_glBlendColor = (PTR_glBlendColor)dlsym(libGL, "glBlendColor");
/*PFNglBlendEquation */    gles_glBlendEquation = (PTR_glBlendEquation)dlsym(libGL, "glBlendEquation");
/*PFNglBlendEquationSeparate */    gles_glBlendEquationSeparate = (PTR_glBlendEquationSeparate)dlsym(libGL, "glBlendEquationSeparate");
/*PFNglBlendFunc */    gles_glBlendFunc = (PTR_glBlendFunc)dlsym(libGL, "glBlendFunc");
/*PFNglBlendFuncSeparate */    gles_glBlendFuncSeparate = (PTR_glBlendFuncSeparate)dlsym(libGL, "glBlendFuncSeparate");
/*PFNglBufferData */    gles_glBufferData = (PTR_glBufferData)dlsym(libGL, "glBufferData");
/*PFNglBufferSubData */    gles_glBufferSubData = (PTR_glBufferSubData)dlsym(libGL, "glBufferSubData");
/*PFNglCheckFramebufferStatus */    gles_glCheckFramebufferStatus = (PTR_glCheckFramebufferStatus)dlsym(libGL, "glCheckFramebufferStatus");
/*PFNglClear */    gles_glClear = (PTR_glClear)dlsym(libGL, "glClear");
/*PFNglClearColor */    gles_glClearColor = (PTR_glClearColor)dlsym(libGL, "glClearColor");
/*PFNglClearDepthf */    gles_glClearDepthf = (PTR_glClearDepthf)dlsym(libGL, "glClearDepthf");
/*PFNglClearStencil */    gles_glClearStencil = (PTR_glClearStencil)dlsym(libGL, "glClearStencil");
/*PFNglColorMask */    gles_glColorMask = (PTR_glColorMask)dlsym(libGL, "glColorMask");
/*PFNglCompileShader */    gles_glCompileShader = (PTR_glCompileShader)dlsym(libGL, "glCompileShader");
/*PFNglCompressedTexImage2D */    gles_glCompressedTexImage2D = (PTR_glCompressedTexImage2D)dlsym(libGL, "glCompressedTexImage2D");
/*PFNglCompressedTexSubImage2D */    gles_glCompressedTexSubImage2D = (PTR_glCompressedTexSubImage2D)dlsym(libGL, "glCompressedTexSubImage2D");
/*PFNglCopyTexImage2D */    gles_glCopyTexImage2D = (PTR_glCopyTexImage2D)dlsym(libGL, "glCopyTexImage2D");
/*PFNglCopyTexSubImage2D */    gles_glCopyTexSubImage2D = (PTR_glCopyTexSubImage2D)dlsym(libGL, "glCopyTexSubImage2D");
/*PFNglCreateProgram */    gles_glCreateProgram = (PTR_glCreateProgram)dlsym(libGL, "glCreateProgram");
/*PFNglCreateShader */    gles_glCreateShader = (PTR_glCreateShader)dlsym(libGL, "glCreateShader");
/*PFNglCullFace */    gles_glCullFace = (PTR_glCullFace)dlsym(libGL, "glCullFace");
/*PFNglDeleteBuffers */    gles_glDeleteBuffers = (PTR_glDeleteBuffers)dlsym(libGL, "glDeleteBuffers");
/*PFNglDeleteFramebuffers */    gles_glDeleteFramebuffers = (PTR_glDeleteFramebuffers)dlsym(libGL, "glDeleteFramebuffers");
/*PFNglDeleteProgram */    gles_glDeleteProgram = (PTR_glDeleteProgram)dlsym(libGL, "glDeleteProgram");
/*PFNglDeleteRenderbuffers */    gles_glDeleteRenderbuffers = (PTR_glDeleteRenderbuffers)dlsym(libGL, "glDeleteRenderbuffers");
/*PFNglDeleteShader */    gles_glDeleteShader = (PTR_glDeleteShader)dlsym(libGL, "glDeleteShader");
/*PFNglDeleteTextures */    gles_glDeleteTextures = (PTR_glDeleteTextures)dlsym(libGL, "glDeleteTextures");
/*PFNglDepthFunc */    gles_glDepthFunc = (PTR_glDepthFunc)dlsym(libGL, "glDepthFunc");
/*PFNglDepthMask */    gles_glDepthMask = (PTR_glDepthMask)dlsym(libGL, "glDepthMask");
/*PFNglDepthRangef */    gles_glDepthRangef = (PTR_glDepthRangef)dlsym(libGL, "glDepthRangef");
/*PFNglDetachShader */    gles_glDetachShader = (PTR_glDetachShader)dlsym(libGL, "glDetachShader");
/*PFNglDisable */    gles_glDisable = (PTR_glDisable)dlsym(libGL, "glDisable");
/*PFNglDisableVertexAttribArray */    gles_glDisableVertexAttribArray = (PTR_glDisableVertexAttribArray)dlsym(libGL, "glDisableVertexAttribArray");
/*PFNglDrawArrays */    gles_glDrawArrays = (PTR_glDrawArrays)dlsym(libGL, "glDrawArrays");
/*PFNglDrawElements */    gles_glDrawElements = (PTR_glDrawElements)dlsym(libGL, "glDrawElements");
/*PFNglEnable */    gles_glEnable = (PTR_glEnable)dlsym(libGL, "glEnable");
/*PFNglEnableVertexAttribArray */    gles_glEnableVertexAttribArray = (PTR_glEnableVertexAttribArray)dlsym(libGL, "glEnableVertexAttribArray");
/*PFNglFinish */    gles_glFinish = (PTR_glFinish)dlsym(libGL, "glFinish");
/*PFNglFlush */    gles_glFlush = (PTR_glFlush)dlsym(libGL, "glFlush");
/*PFNglFramebufferRenderbuffer */    gles_glFramebufferRenderbuffer = (PTR_glFramebufferRenderbuffer)dlsym(libGL, "glFramebufferRenderbuffer");
/*PFNglFramebufferTexture2D */    gles_glFramebufferTexture2D = (PTR_glFramebufferTexture2D)dlsym(libGL, "glFramebufferTexture2D");
/*PFNglFrontFace */    gles_glFrontFace = (PTR_glFrontFace)dlsym(libGL, "glFrontFace");
/*PFNglGenBuffers */    gles_glGenBuffers = (PTR_glGenBuffers)dlsym(libGL, "glGenBuffers");
/*PFNglGenerateMipmap */    gles_glGenerateMipmap = (PTR_glGenerateMipmap)dlsym(libGL, "glGenerateMipmap");
/*PFNglGenFramebuffers */    gles_glGenFramebuffers = (PTR_glGenFramebuffers)dlsym(libGL, "glGenFramebuffers");
/*PFNglGenRenderbuffers */    gles_glGenRenderbuffers = (PTR_glGenRenderbuffers)dlsym(libGL, "glGenRenderbuffers");
/*PFNglGenTextures */    gles_glGenTextures = (PTR_glGenTextures)dlsym(libGL, "glGenTextures");
/*PFNglGetActiveAttrib */    gles_glGetActiveAttrib = (PTR_glGetActiveAttrib)dlsym(libGL, "glGetActiveAttrib");
/*PFNglGetActiveUniform */    gles_glGetActiveUniform = (PTR_glGetActiveUniform)dlsym(libGL, "glGetActiveUniform");
/*PFNglGetAttachedShaders */    gles_glGetAttachedShaders = (PTR_glGetAttachedShaders)dlsym(libGL, "glGetAttachedShaders");
/*PFNglGetAttribLocation */    gles_glGetAttribLocation = (PTR_glGetAttribLocation)dlsym(libGL, "glGetAttribLocation");
/*PFNglGetBooleanv */    gles_glGetBooleanv = (PTR_glGetBooleanv)dlsym(libGL, "glGetBooleanv");
/*PFNglGetBufferParameteriv */    gles_glGetBufferParameteriv = (PTR_glGetBufferParameteriv)dlsym(libGL, "glGetBufferParameteriv");
/*PFNglGetError */    gles_glGetError = (PTR_glGetError)dlsym(libGL, "glGetError");
/*PFNglGetFloatv */    gles_glGetFloatv = (PTR_glGetFloatv)dlsym(libGL, "glGetFloatv");
/*PFNglGetFramebufferAttachmentParameteriv */    gles_glGetFramebufferAttachmentParameteriv = (PTR_glGetFramebufferAttachmentParameteriv)dlsym(libGL, "glGetFramebufferAttachmentParameteriv");
/*PFNglGetIntegerv */    gles_glGetIntegerv = (PTR_glGetIntegerv)dlsym(libGL, "glGetIntegerv");
/*PFNglGetProgramiv */    gles_glGetProgramiv = (PTR_glGetProgramiv)dlsym(libGL, "glGetProgramiv");
/*PFNglGetProgramInfoLog */    gles_glGetProgramInfoLog = (PTR_glGetProgramInfoLog)dlsym(libGL, "glGetProgramInfoLog");
/*PFNglGetRenderbufferParameteriv */    gles_glGetRenderbufferParameteriv = (PTR_glGetRenderbufferParameteriv)dlsym(libGL, "glGetRenderbufferParameteriv");
/*PFNglGetShaderiv */    gles_glGetShaderiv = (PTR_glGetShaderiv)dlsym(libGL, "glGetShaderiv");
/*PFNglGetShaderInfoLog */    gles_glGetShaderInfoLog = (PTR_glGetShaderInfoLog)dlsym(libGL, "glGetShaderInfoLog");
/*PFNglGetShaderPrecisionFormat */    gles_glGetShaderPrecisionFormat = (PTR_glGetShaderPrecisionFormat)dlsym(libGL, "glGetShaderPrecisionFormat");
/*PFNglGetShaderSource */    gles_glGetShaderSource = (PTR_glGetShaderSource)dlsym(libGL, "glGetShaderSource");
/*PFNglGetString */    gles_glGetString = (PTR_glGetString)dlsym(libGL, "glGetString");
/*PFNglGetTexParameterfv */    gles_glGetTexParameterfv = (PTR_glGetTexParameterfv)dlsym(libGL, "glGetTexParameterfv");
/*PFNglGetTexParameteriv */    gles_glGetTexParameteriv = (PTR_glGetTexParameteriv)dlsym(libGL, "glGetTexParameteriv");
/*PFNglGetUniformfv */    gles_glGetUniformfv = (PTR_glGetUniformfv)dlsym(libGL, "glGetUniformfv");
/*PFNglGetUniformiv */    gles_glGetUniformiv = (PTR_glGetUniformiv)dlsym(libGL, "glGetUniformiv");
/*PFNglGetUniformLocation */    gles_glGetUniformLocation = (PTR_glGetUniformLocation)dlsym(libGL, "glGetUniformLocation");
/*PFNglGetVertexAttribfv */    gles_glGetVertexAttribfv = (PTR_glGetVertexAttribfv)dlsym(libGL, "glGetVertexAttribfv");
/*PFNglGetVertexAttribiv */    gles_glGetVertexAttribiv = (PTR_glGetVertexAttribiv)dlsym(libGL, "glGetVertexAttribiv");
/*PFNglGetVertexAttribPointerv */    gles_glGetVertexAttribPointerv = (PTR_glGetVertexAttribPointerv)dlsym(libGL, "glGetVertexAttribPointerv");
/*PFNglHint */    gles_glHint = (PTR_glHint)dlsym(libGL, "glHint");
/*PFNglIsBuffer */    gles_glIsBuffer = (PTR_glIsBuffer)dlsym(libGL, "glIsBuffer");
/*PFNglIsEnabled */    gles_glIsEnabled = (PTR_glIsEnabled)dlsym(libGL, "glIsEnabled");
/*PFNglIsFramebuffer */    gles_glIsFramebuffer = (PTR_glIsFramebuffer)dlsym(libGL, "glIsFramebuffer");
/*PFNglIsProgram */    gles_glIsProgram = (PTR_glIsProgram)dlsym(libGL, "glIsProgram");
/*PFNglIsRenderbuffer */    gles_glIsRenderbuffer = (PTR_glIsRenderbuffer)dlsym(libGL, "glIsRenderbuffer");
/*PFNglIsShader */    gles_glIsShader = (PTR_glIsShader)dlsym(libGL, "glIsShader");
/*PFNglIsTexture */    gles_glIsTexture = (PTR_glIsTexture)dlsym(libGL, "glIsTexture");
/*PFNglLineWidth */    gles_glLineWidth = (PTR_glLineWidth)dlsym(libGL, "glLineWidth");
/*PFNglLinkProgram */    gles_glLinkProgram = (PTR_glLinkProgram)dlsym(libGL, "glLinkProgram");
/*PFNglPixelStorei */    gles_glPixelStorei = (PTR_glPixelStorei)dlsym(libGL, "glPixelStorei");
/*PFNglPolygonOffset */    gles_glPolygonOffset = (PTR_glPolygonOffset)dlsym(libGL, "glPolygonOffset");
/*PFNglReadPixels */    gles_glReadPixels = (PTR_glReadPixels)dlsym(libGL, "glReadPixels");
/*PFNglReleaseShaderCompiler */    gles_glReleaseShaderCompiler = (PTR_glReleaseShaderCompiler)dlsym(libGL, "glReleaseShaderCompiler");
/*PFNglRenderbufferStorage */    gles_glRenderbufferStorage = (PTR_glRenderbufferStorage)dlsym(libGL, "glRenderbufferStorage");
/*PFNglSampleCoverage */    gles_glSampleCoverage = (PTR_glSampleCoverage)dlsym(libGL, "glSampleCoverage");
/*PFNglScissor */    gles_glScissor = (PTR_glScissor)dlsym(libGL, "glScissor");
/*PFNglShaderBinary */    gles_glShaderBinary = (PTR_glShaderBinary)dlsym(libGL, "glShaderBinary");
/*PFNglShaderSource */    gles_glShaderSource = (PTR_glShaderSource)dlsym(libGL, "glShaderSource");
/*PFNglStencilFunc */    gles_glStencilFunc = (PTR_glStencilFunc)dlsym(libGL, "glStencilFunc");
/*PFNglStencilFuncSeparate */    gles_glStencilFuncSeparate = (PTR_glStencilFuncSeparate)dlsym(libGL, "glStencilFuncSeparate");
/*PFNglStencilMask */    gles_glStencilMask = (PTR_glStencilMask)dlsym(libGL, "glStencilMask");
/*PFNglStencilMaskSeparate */    gles_glStencilMaskSeparate = (PTR_glStencilMaskSeparate)dlsym(libGL, "glStencilMaskSeparate");
/*PFNglStencilOp */    gles_glStencilOp = (PTR_glStencilOp)dlsym(libGL, "glStencilOp");
/*PFNglStencilOpSeparate */    gles_glStencilOpSeparate = (PTR_glStencilOpSeparate)dlsym(libGL, "glStencilOpSeparate");
/*PFNglTexImage2D */    gles_glTexImage2D = (PTR_glTexImage2D)dlsym(libGL, "glTexImage2D");
/*PFNglTexParameterf */    gles_glTexParameterf = (PTR_glTexParameterf)dlsym(libGL, "glTexParameterf");
/*PFNglTexParameterfv */    gles_glTexParameterfv = (PTR_glTexParameterfv)dlsym(libGL, "glTexParameterfv");
/*PFNglTexParameteri */    gles_glTexParameteri = (PTR_glTexParameteri)dlsym(libGL, "glTexParameteri");
/*PFNglTexParameteriv */    gles_glTexParameteriv = (PTR_glTexParameteriv)dlsym(libGL, "glTexParameteriv");
/*PFNglTexSubImage2D */    gles_glTexSubImage2D = (PTR_glTexSubImage2D)dlsym(libGL, "glTexSubImage2D");
/*PFNglUniform1f */    gles_glUniform1f = (PTR_glUniform1f)dlsym(libGL, "glUniform1f");
/*PFNglUniform1fv */    gles_glUniform1fv = (PTR_glUniform1fv)dlsym(libGL, "glUniform1fv");
/*PFNglUniform1i */    gles_glUniform1i = (PTR_glUniform1i)dlsym(libGL, "glUniform1i");
/*PFNglUniform1iv */    gles_glUniform1iv = (PTR_glUniform1iv)dlsym(libGL, "glUniform1iv");
/*PFNglUniform2f */    gles_glUniform2f = (PTR_glUniform2f)dlsym(libGL, "glUniform2f");
/*PFNglUniform2fv */    gles_glUniform2fv = (PTR_glUniform2fv)dlsym(libGL, "glUniform2fv");
/*PFNglUniform2i */    gles_glUniform2i = (PTR_glUniform2i)dlsym(libGL, "glUniform2i");
/*PFNglUniform2iv */    gles_glUniform2iv = (PTR_glUniform2iv)dlsym(libGL, "glUniform2iv");
/*PFNglUniform3f */    gles_glUniform3f = (PTR_glUniform3f)dlsym(libGL, "glUniform3f");
/*PFNglUniform3fv */    gles_glUniform3fv = (PTR_glUniform3fv)dlsym(libGL, "glUniform3fv");
/*PFNglUniform3i */    gles_glUniform3i = (PTR_glUniform3i)dlsym(libGL, "glUniform3i");
/*PFNglUniform3iv */    gles_glUniform3iv = (PTR_glUniform3iv)dlsym(libGL, "glUniform3iv");
/*PFNglUniform4f */    gles_glUniform4f = (PTR_glUniform4f)dlsym(libGL, "glUniform4f");
/*PFNglUniform4fv */    gles_glUniform4fv = (PTR_glUniform4fv)dlsym(libGL, "glUniform4fv");
/*PFNglUniform4i */    gles_glUniform4i = (PTR_glUniform4i)dlsym(libGL, "glUniform4i");
/*PFNglUniform4iv */    gles_glUniform4iv = (PTR_glUniform4iv)dlsym(libGL, "glUniform4iv");
/*PFNglUniformMatrix2fv */    gles_glUniformMatrix2fv = (PTR_glUniformMatrix2fv)dlsym(libGL, "glUniformMatrix2fv");
/*PFNglUniformMatrix3fv */    gles_glUniformMatrix3fv = (PTR_glUniformMatrix3fv)dlsym(libGL, "glUniformMatrix3fv");
/*PFNglUniformMatrix4fv */    gles_glUniformMatrix4fv = (PTR_glUniformMatrix4fv)dlsym(libGL, "glUniformMatrix4fv");
/*PFNglUseProgram */    gles_glUseProgram = (PTR_glUseProgram)dlsym(libGL, "glUseProgram");
/*PFNglValidateProgram */    gles_glValidateProgram = (PTR_glValidateProgram)dlsym(libGL, "glValidateProgram");
/*PFNglVertexAttrib1f */    gles_glVertexAttrib1f = (PTR_glVertexAttrib1f)dlsym(libGL, "glVertexAttrib1f");
/*PFNglVertexAttrib1fv */    gles_glVertexAttrib1fv = (PTR_glVertexAttrib1fv)dlsym(libGL, "glVertexAttrib1fv");
/*PFNglVertexAttrib2f */    gles_glVertexAttrib2f = (PTR_glVertexAttrib2f)dlsym(libGL, "glVertexAttrib2f");
/*PFNglVertexAttrib2fv */    gles_glVertexAttrib2fv = (PTR_glVertexAttrib2fv)dlsym(libGL, "glVertexAttrib2fv");
/*PFNglVertexAttrib3f */    gles_glVertexAttrib3f = (PTR_glVertexAttrib3f)dlsym(libGL, "glVertexAttrib3f");
/*PFNglVertexAttrib3fv */    gles_glVertexAttrib3fv = (PTR_glVertexAttrib3fv)dlsym(libGL, "glVertexAttrib3fv");
/*PFNglVertexAttrib4f */    gles_glVertexAttrib4f = (PTR_glVertexAttrib4f)dlsym(libGL, "glVertexAttrib4f");
/*PFNglVertexAttrib4fv */    gles_glVertexAttrib4fv = (PTR_glVertexAttrib4fv)dlsym(libGL, "glVertexAttrib4fv");
/*PFNglVertexAttribPointer */    gles_glVertexAttribPointer = (PTR_glVertexAttribPointer)dlsym(libGL, "glVertexAttribPointer");
/*PFNglViewport */    gles_glViewport = (PTR_glViewport)dlsym(libGL, "glViewport");


// GL_ES_VERSION_3_0
/*PFNglReadBuffer */    gles_glReadBuffer = (PTR_glReadBuffer)dlsym(libGL, "glReadBuffer");
/*PFNglDrawRangeElements */    gles_glDrawRangeElements = (PTR_glDrawRangeElements)dlsym(libGL, "glDrawRangeElements");
/*PFNglTexImage3D */    gles_glTexImage3D = (PTR_glTexImage3D)dlsym(libGL, "glTexImage3D");
/*PFNglTexSubImage3D */    gles_glTexSubImage3D = (PTR_glTexSubImage3D)dlsym(libGL, "glTexSubImage3D");
/*PFNglCopyTexSubImage3D */    gles_glCopyTexSubImage3D = (PTR_glCopyTexSubImage3D)dlsym(libGL, "glCopyTexSubImage3D");
/*PFNglCompressedTexImage3D */    gles_glCompressedTexImage3D = (PTR_glCompressedTexImage3D)dlsym(libGL, "glCompressedTexImage3D");
/*PFNglCompressedTexSubImage3D */    gles_glCompressedTexSubImage3D = (PTR_glCompressedTexSubImage3D)dlsym(libGL, "glCompressedTexSubImage3D");
/*PFNglGenQueries */    gles_glGenQueries = (PTR_glGenQueries)dlsym(libGL, "glGenQueries");
/*PFNglDeleteQueries */    gles_glDeleteQueries = (PTR_glDeleteQueries)dlsym(libGL, "glDeleteQueries");
/*PFNglIsQuery */    gles_glIsQuery = (PTR_glIsQuery)dlsym(libGL, "glIsQuery");
/*PFNglBeginQuery */    gles_glBeginQuery = (PTR_glBeginQuery)dlsym(libGL, "glBeginQuery");
/*PFNglEndQuery */    gles_glEndQuery = (PTR_glEndQuery)dlsym(libGL, "glEndQuery");
/*PFNglGetQueryiv */    gles_glGetQueryiv = (PTR_glGetQueryiv)dlsym(libGL, "glGetQueryiv");
/*PFNglGetQueryObjectuiv */    gles_glGetQueryObjectuiv = (PTR_glGetQueryObjectuiv)dlsym(libGL, "glGetQueryObjectuiv");
/*PFNglUnmapBuffer */    gles_glUnmapBuffer = (PTR_glUnmapBuffer)dlsym(libGL, "glUnmapBuffer");
/*PFNglGetBufferPointerv */    gles_glGetBufferPointerv = (PTR_glGetBufferPointerv)dlsym(libGL, "glGetBufferPointerv");
/*PFNglDrawBuffers */    gles_glDrawBuffers = (PTR_glDrawBuffers)dlsym(libGL, "glDrawBuffers");
/*PFNglUniformMatrix2x3fv */    gles_glUniformMatrix2x3fv = (PTR_glUniformMatrix2x3fv)dlsym(libGL, "glUniformMatrix2x3fv");
/*PFNglUniformMatrix3x2fv */    gles_glUniformMatrix3x2fv = (PTR_glUniformMatrix3x2fv)dlsym(libGL, "glUniformMatrix3x2fv");
/*PFNglUniformMatrix2x4fv */    gles_glUniformMatrix2x4fv = (PTR_glUniformMatrix2x4fv)dlsym(libGL, "glUniformMatrix2x4fv");
/*PFNglUniformMatrix4x2fv */    gles_glUniformMatrix4x2fv = (PTR_glUniformMatrix4x2fv)dlsym(libGL, "glUniformMatrix4x2fv");
/*PFNglUniformMatrix3x4fv */    gles_glUniformMatrix3x4fv = (PTR_glUniformMatrix3x4fv)dlsym(libGL, "glUniformMatrix3x4fv");
/*PFNglUniformMatrix4x3fv */    gles_glUniformMatrix4x3fv = (PTR_glUniformMatrix4x3fv)dlsym(libGL, "glUniformMatrix4x3fv");
/*PFNglBlitFramebuffer */    gles_glBlitFramebuffer = (PTR_glBlitFramebuffer)dlsym(libGL, "glBlitFramebuffer");
/*PFNglRenderbufferStorageMultisample */    gles_glRenderbufferStorageMultisample = (PTR_glRenderbufferStorageMultisample)dlsym(libGL, "glRenderbufferStorageMultisample");
/*PFNglFramebufferTextureLayer */    gles_glFramebufferTextureLayer = (PTR_glFramebufferTextureLayer)dlsym(libGL, "glFramebufferTextureLayer");
/*PFNglMapBufferRange */    gles_glMapBufferRange = (PTR_glMapBufferRange)dlsym(libGL, "glMapBufferRange");
/*PFNglFlushMappedBufferRange */    gles_glFlushMappedBufferRange = (PTR_glFlushMappedBufferRange)dlsym(libGL, "glFlushMappedBufferRange");
/*PFNglBindVertexArray */    gles_glBindVertexArray = (PTR_glBindVertexArray)dlsym(libGL, "glBindVertexArray");
/*PFNglDeleteVertexArrays */    gles_glDeleteVertexArrays = (PTR_glDeleteVertexArrays)dlsym(libGL, "glDeleteVertexArrays");
/*PFNglGenVertexArrays */    gles_glGenVertexArrays = (PTR_glGenVertexArrays)dlsym(libGL, "glGenVertexArrays");
/*PFNglIsVertexArray */    gles_glIsVertexArray = (PTR_glIsVertexArray)dlsym(libGL, "glIsVertexArray");
/*PFNglGetIntegeri_v */    gles_glGetIntegeri_v = (PTR_glGetIntegeri_v)dlsym(libGL, "glGetIntegeri_v");
/*PFNglBeginTransformFeedback */    gles_glBeginTransformFeedback = (PTR_glBeginTransformFeedback)dlsym(libGL, "glBeginTransformFeedback");
/*PFNglEndTransformFeedback */    gles_glEndTransformFeedback = (PTR_glEndTransformFeedback)dlsym(libGL, "glEndTransformFeedback");
/*PFNglBindBufferRange */    gles_glBindBufferRange = (PTR_glBindBufferRange)dlsym(libGL, "glBindBufferRange");
/*PFNglBindBufferBase */    gles_glBindBufferBase = (PTR_glBindBufferBase)dlsym(libGL, "glBindBufferBase");
/*PFNglTransformFeedbackVaryings */    gles_glTransformFeedbackVaryings = (PTR_glTransformFeedbackVaryings)dlsym(libGL, "glTransformFeedbackVaryings");
/*PFNglGetTransformFeedbackVarying */    gles_glGetTransformFeedbackVarying = (PTR_glGetTransformFeedbackVarying)dlsym(libGL, "glGetTransformFeedbackVarying");
/*PFNglVertexAttribIPointer */    gles_glVertexAttribIPointer = (PTR_glVertexAttribIPointer)dlsym(libGL, "glVertexAttribIPointer");
/*PFNglGetVertexAttribIiv */    gles_glGetVertexAttribIiv = (PTR_glGetVertexAttribIiv)dlsym(libGL, "glGetVertexAttribIiv");
/*PFNglGetVertexAttribIuiv */    gles_glGetVertexAttribIuiv = (PTR_glGetVertexAttribIuiv)dlsym(libGL, "glGetVertexAttribIuiv");
/*PFNglVertexAttribI4i */    gles_glVertexAttribI4i = (PTR_glVertexAttribI4i)dlsym(libGL, "glVertexAttribI4i");
/*PFNglVertexAttribI4ui */    gles_glVertexAttribI4ui = (PTR_glVertexAttribI4ui)dlsym(libGL, "glVertexAttribI4ui");
/*PFNglVertexAttribI4iv */    gles_glVertexAttribI4iv = (PTR_glVertexAttribI4iv)dlsym(libGL, "glVertexAttribI4iv");
/*PFNglVertexAttribI4uiv */    gles_glVertexAttribI4uiv = (PTR_glVertexAttribI4uiv)dlsym(libGL, "glVertexAttribI4uiv");
/*PFNglGetUniformuiv */    gles_glGetUniformuiv = (PTR_glGetUniformuiv)dlsym(libGL, "glGetUniformuiv");
/*PFNglGetFragDataLocation */    gles_glGetFragDataLocation = (PTR_glGetFragDataLocation)dlsym(libGL, "glGetFragDataLocation");
/*PFNglUniform1ui */    gles_glUniform1ui = (PTR_glUniform1ui)dlsym(libGL, "glUniform1ui");
/*PFNglUniform2ui */    gles_glUniform2ui = (PTR_glUniform2ui)dlsym(libGL, "glUniform2ui");
/*PFNglUniform3ui */    gles_glUniform3ui = (PTR_glUniform3ui)dlsym(libGL, "glUniform3ui");
/*PFNglUniform4ui */    gles_glUniform4ui = (PTR_glUniform4ui)dlsym(libGL, "glUniform4ui");
/*PFNglUniform1uiv */    gles_glUniform1uiv = (PTR_glUniform1uiv)dlsym(libGL, "glUniform1uiv");
/*PFNglUniform2uiv */    gles_glUniform2uiv = (PTR_glUniform2uiv)dlsym(libGL, "glUniform2uiv");
/*PFNglUniform3uiv */    gles_glUniform3uiv = (PTR_glUniform3uiv)dlsym(libGL, "glUniform3uiv");
/*PFNglUniform4uiv */    gles_glUniform4uiv = (PTR_glUniform4uiv)dlsym(libGL, "glUniform4uiv");
/*PFNglClearBufferiv */    gles_glClearBufferiv = (PTR_glClearBufferiv)dlsym(libGL, "glClearBufferiv");
/*PFNglClearBufferuiv */    gles_glClearBufferuiv = (PTR_glClearBufferuiv)dlsym(libGL, "glClearBufferuiv");
/*PFNglClearBufferfv */    gles_glClearBufferfv = (PTR_glClearBufferfv)dlsym(libGL, "glClearBufferfv");
/*PFNglClearBufferfi */    gles_glClearBufferfi = (PTR_glClearBufferfi)dlsym(libGL, "glClearBufferfi");
/*PFNglGetStringi */    gles_glGetStringi = (PTR_glGetStringi)dlsym(libGL, "glGetStringi");
/*PFNglCopyBufferSubData */    gles_glCopyBufferSubData = (PTR_glCopyBufferSubData)dlsym(libGL, "glCopyBufferSubData");
/*PFNglGetUniformIndices */    gles_glGetUniformIndices = (PTR_glGetUniformIndices)dlsym(libGL, "glGetUniformIndices");
/*PFNglGetActiveUniformsiv */    gles_glGetActiveUniformsiv = (PTR_glGetActiveUniformsiv)dlsym(libGL, "glGetActiveUniformsiv");
/*PFNglGetUniformBlockIndex */    gles_glGetUniformBlockIndex = (PTR_glGetUniformBlockIndex)dlsym(libGL, "glGetUniformBlockIndex");
/*PFNglGetActiveUniformBlockiv */    gles_glGetActiveUniformBlockiv = (PTR_glGetActiveUniformBlockiv)dlsym(libGL, "glGetActiveUniformBlockiv");
/*PFNglGetActiveUniformBlockName */    gles_glGetActiveUniformBlockName = (PTR_glGetActiveUniformBlockName)dlsym(libGL, "glGetActiveUniformBlockName");
/*PFNglUniformBlockBinding */    gles_glUniformBlockBinding = (PTR_glUniformBlockBinding)dlsym(libGL, "glUniformBlockBinding");
/*PFNglDrawArraysInstanced */    gles_glDrawArraysInstanced = (PTR_glDrawArraysInstanced)dlsym(libGL, "glDrawArraysInstanced");
/*PFNglDrawElementsInstanced */    gles_glDrawElementsInstanced = (PTR_glDrawElementsInstanced)dlsym(libGL, "glDrawElementsInstanced");
/*PFNglFenceSync */    gles_glFenceSync = (PTR_glFenceSync)dlsym(libGL, "glFenceSync");
/*PFNglIsSync */    gles_glIsSync = (PTR_glIsSync)dlsym(libGL, "glIsSync");
/*PFNglDeleteSync */    gles_glDeleteSync = (PTR_glDeleteSync)dlsym(libGL, "glDeleteSync");
/*PFNglClientWaitSync */    gles_glClientWaitSync = (PTR_glClientWaitSync)dlsym(libGL, "glClientWaitSync");
/*PFNglWaitSync */    gles_glWaitSync = (PTR_glWaitSync)dlsym(libGL, "glWaitSync");
/*PFNglGetInteger64v */    gles_glGetInteger64v = (PTR_glGetInteger64v)dlsym(libGL, "glGetInteger64v");
/*PFNglGetSynciv */    gles_glGetSynciv = (PTR_glGetSynciv)dlsym(libGL, "glGetSynciv");
/*PFNglGetInteger64i_v */    gles_glGetInteger64i_v = (PTR_glGetInteger64i_v)dlsym(libGL, "glGetInteger64i_v");
/*PFNglGetBufferParameteri64v */    gles_glGetBufferParameteri64v = (PTR_glGetBufferParameteri64v)dlsym(libGL, "glGetBufferParameteri64v");
/*PFNglGenSamplers */    gles_glGenSamplers = (PTR_glGenSamplers)dlsym(libGL, "glGenSamplers");
/*PFNglDeleteSamplers */    gles_glDeleteSamplers = (PTR_glDeleteSamplers)dlsym(libGL, "glDeleteSamplers");
/*PFNglIsSampler */    gles_glIsSampler = (PTR_glIsSampler)dlsym(libGL, "glIsSampler");
/*PFNglBindSampler */    gles_glBindSampler = (PTR_glBindSampler)dlsym(libGL, "glBindSampler");
/*PFNglSamplerParameteri */    gles_glSamplerParameteri = (PTR_glSamplerParameteri)dlsym(libGL, "glSamplerParameteri");
/*PFNglSamplerParameteriv */    gles_glSamplerParameteriv = (PTR_glSamplerParameteriv)dlsym(libGL, "glSamplerParameteriv");
/*PFNglSamplerParameterf */    gles_glSamplerParameterf = (PTR_glSamplerParameterf)dlsym(libGL, "glSamplerParameterf");
/*PFNglSamplerParameterfv */    gles_glSamplerParameterfv = (PTR_glSamplerParameterfv)dlsym(libGL, "glSamplerParameterfv");
/*PFNglGetSamplerParameteriv */    gles_glGetSamplerParameteriv = (PTR_glGetSamplerParameteriv)dlsym(libGL, "glGetSamplerParameteriv");
/*PFNglGetSamplerParameterfv */    gles_glGetSamplerParameterfv = (PTR_glGetSamplerParameterfv)dlsym(libGL, "glGetSamplerParameterfv");
/*PFNglVertexAttribDivisor */    gles_glVertexAttribDivisor = (PTR_glVertexAttribDivisor)dlsym(libGL, "glVertexAttribDivisor");
/*PFNglBindTransformFeedback */    gles_glBindTransformFeedback = (PTR_glBindTransformFeedback)dlsym(libGL, "glBindTransformFeedback");
/*PFNglDeleteTransformFeedbacks */    gles_glDeleteTransformFeedbacks = (PTR_glDeleteTransformFeedbacks)dlsym(libGL, "glDeleteTransformFeedbacks");
/*PFNglGenTransformFeedbacks */    gles_glGenTransformFeedbacks = (PTR_glGenTransformFeedbacks)dlsym(libGL, "glGenTransformFeedbacks");
/*PFNglIsTransformFeedback */    gles_glIsTransformFeedback = (PTR_glIsTransformFeedback)dlsym(libGL, "glIsTransformFeedback");
/*PFNglPauseTransformFeedback */    gles_glPauseTransformFeedback = (PTR_glPauseTransformFeedback)dlsym(libGL, "glPauseTransformFeedback");
/*PFNglResumeTransformFeedback */    gles_glResumeTransformFeedback = (PTR_glResumeTransformFeedback)dlsym(libGL, "glResumeTransformFeedback");
/*PFNglGetProgramBinary */    gles_glGetProgramBinary = (PTR_glGetProgramBinary)dlsym(libGL, "glGetProgramBinary");
/*PFNglProgramBinary */    gles_glProgramBinary = (PTR_glProgramBinary)dlsym(libGL, "glProgramBinary");
/*PFNglProgramParameteri */    gles_glProgramParameteri = (PTR_glProgramParameteri)dlsym(libGL, "glProgramParameteri");
/*PFNglInvalidateFramebuffer */    gles_glInvalidateFramebuffer = (PTR_glInvalidateFramebuffer)dlsym(libGL, "glInvalidateFramebuffer");
/*PFNglInvalidateSubFramebuffer */    gles_glInvalidateSubFramebuffer = (PTR_glInvalidateSubFramebuffer)dlsym(libGL, "glInvalidateSubFramebuffer");
/*PFNglTexStorage2D */    gles_glTexStorage2D = (PTR_glTexStorage2D)dlsym(libGL, "glTexStorage2D");
/*PFNglTexStorage3D */    gles_glTexStorage3D = (PTR_glTexStorage3D)dlsym(libGL, "glTexStorage3D");
/*PFNglGetInternalformativ */    gles_glGetInternalformativ = (PTR_glGetInternalformativ)dlsym(libGL, "glGetInternalformativ");


// GL_ES_VERSION_3_1
/*PFNglDispatchCompute */    gles_glDispatchCompute = (PTR_glDispatchCompute)dlsym(libGL, "glDispatchCompute");
/*PFNglDispatchComputeIndirect */    gles_glDispatchComputeIndirect = (PTR_glDispatchComputeIndirect)dlsym(libGL, "glDispatchComputeIndirect");
/*PFNglDrawArraysIndirect */    gles_glDrawArraysIndirect = (PTR_glDrawArraysIndirect)dlsym(libGL, "glDrawArraysIndirect");
/*PFNglDrawElementsIndirect */    gles_glDrawElementsIndirect = (PTR_glDrawElementsIndirect)dlsym(libGL, "glDrawElementsIndirect");
/*PFNglFramebufferParameteri */    gles_glFramebufferParameteri = (PTR_glFramebufferParameteri)dlsym(libGL, "glFramebufferParameteri");
/*PFNglGetFramebufferParameteriv */    gles_glGetFramebufferParameteriv = (PTR_glGetFramebufferParameteriv)dlsym(libGL, "glGetFramebufferParameteriv");
/*PFNglGetProgramInterfaceiv */    gles_glGetProgramInterfaceiv = (PTR_glGetProgramInterfaceiv)dlsym(libGL, "glGetProgramInterfaceiv");
/*PFNglGetProgramResourceIndex */    gles_glGetProgramResourceIndex = (PTR_glGetProgramResourceIndex)dlsym(libGL, "glGetProgramResourceIndex");
/*PFNglGetProgramResourceName */    gles_glGetProgramResourceName = (PTR_glGetProgramResourceName)dlsym(libGL, "glGetProgramResourceName");
/*PFNglGetProgramResourceiv */    gles_glGetProgramResourceiv = (PTR_glGetProgramResourceiv)dlsym(libGL, "glGetProgramResourceiv");
/*PFNglGetProgramResourceLocation */    gles_glGetProgramResourceLocation = (PTR_glGetProgramResourceLocation)dlsym(libGL, "glGetProgramResourceLocation");
/*PFNglUseProgramStages */    gles_glUseProgramStages = (PTR_glUseProgramStages)dlsym(libGL, "glUseProgramStages");
/*PFNglActiveShaderProgram */    gles_glActiveShaderProgram = (PTR_glActiveShaderProgram)dlsym(libGL, "glActiveShaderProgram");
/*PFNglCreateShaderProgramv */    gles_glCreateShaderProgramv = (PTR_glCreateShaderProgramv)dlsym(libGL, "glCreateShaderProgramv");
/*PFNglBindProgramPipeline */    gles_glBindProgramPipeline = (PTR_glBindProgramPipeline)dlsym(libGL, "glBindProgramPipeline");
/*PFNglDeleteProgramPipelines */    gles_glDeleteProgramPipelines = (PTR_glDeleteProgramPipelines)dlsym(libGL, "glDeleteProgramPipelines");
/*PFNglGenProgramPipelines */    gles_glGenProgramPipelines = (PTR_glGenProgramPipelines)dlsym(libGL, "glGenProgramPipelines");
/*PFNglIsProgramPipeline */    gles_glIsProgramPipeline = (PTR_glIsProgramPipeline)dlsym(libGL, "glIsProgramPipeline");
/*PFNglGetProgramPipelineiv */    gles_glGetProgramPipelineiv = (PTR_glGetProgramPipelineiv)dlsym(libGL, "glGetProgramPipelineiv");
/*PFNglProgramUniform1i */    gles_glProgramUniform1i = (PTR_glProgramUniform1i)dlsym(libGL, "glProgramUniform1i");
/*PFNglProgramUniform2i */    gles_glProgramUniform2i = (PTR_glProgramUniform2i)dlsym(libGL, "glProgramUniform2i");
/*PFNglProgramUniform3i */    gles_glProgramUniform3i = (PTR_glProgramUniform3i)dlsym(libGL, "glProgramUniform3i");
/*PFNglProgramUniform4i */    gles_glProgramUniform4i = (PTR_glProgramUniform4i)dlsym(libGL, "glProgramUniform4i");
/*PFNglProgramUniform1ui */    gles_glProgramUniform1ui = (PTR_glProgramUniform1ui)dlsym(libGL, "glProgramUniform1ui");
/*PFNglProgramUniform2ui */    gles_glProgramUniform2ui = (PTR_glProgramUniform2ui)dlsym(libGL, "glProgramUniform2ui");
/*PFNglProgramUniform3ui */    gles_glProgramUniform3ui = (PTR_glProgramUniform3ui)dlsym(libGL, "glProgramUniform3ui");
/*PFNglProgramUniform4ui */    gles_glProgramUniform4ui = (PTR_glProgramUniform4ui)dlsym(libGL, "glProgramUniform4ui");
/*PFNglProgramUniform1f */    gles_glProgramUniform1f = (PTR_glProgramUniform1f)dlsym(libGL, "glProgramUniform1f");
/*PFNglProgramUniform2f */    gles_glProgramUniform2f = (PTR_glProgramUniform2f)dlsym(libGL, "glProgramUniform2f");
/*PFNglProgramUniform3f */    gles_glProgramUniform3f = (PTR_glProgramUniform3f)dlsym(libGL, "glProgramUniform3f");
/*PFNglProgramUniform4f */    gles_glProgramUniform4f = (PTR_glProgramUniform4f)dlsym(libGL, "glProgramUniform4f");
/*PFNglProgramUniform1iv */    gles_glProgramUniform1iv = (PTR_glProgramUniform1iv)dlsym(libGL, "glProgramUniform1iv");
/*PFNglProgramUniform2iv */    gles_glProgramUniform2iv = (PTR_glProgramUniform2iv)dlsym(libGL, "glProgramUniform2iv");
/*PFNglProgramUniform3iv */    gles_glProgramUniform3iv = (PTR_glProgramUniform3iv)dlsym(libGL, "glProgramUniform3iv");
/*PFNglProgramUniform4iv */    gles_glProgramUniform4iv = (PTR_glProgramUniform4iv)dlsym(libGL, "glProgramUniform4iv");
/*PFNglProgramUniform1uiv */    gles_glProgramUniform1uiv = (PTR_glProgramUniform1uiv)dlsym(libGL, "glProgramUniform1uiv");
/*PFNglProgramUniform2uiv */    gles_glProgramUniform2uiv = (PTR_glProgramUniform2uiv)dlsym(libGL, "glProgramUniform2uiv");
/*PFNglProgramUniform3uiv */    gles_glProgramUniform3uiv = (PTR_glProgramUniform3uiv)dlsym(libGL, "glProgramUniform3uiv");
/*PFNglProgramUniform4uiv */    gles_glProgramUniform4uiv = (PTR_glProgramUniform4uiv)dlsym(libGL, "glProgramUniform4uiv");
/*PFNglProgramUniform1fv */    gles_glProgramUniform1fv = (PTR_glProgramUniform1fv)dlsym(libGL, "glProgramUniform1fv");
/*PFNglProgramUniform2fv */    gles_glProgramUniform2fv = (PTR_glProgramUniform2fv)dlsym(libGL, "glProgramUniform2fv");
/*PFNglProgramUniform3fv */    gles_glProgramUniform3fv = (PTR_glProgramUniform3fv)dlsym(libGL, "glProgramUniform3fv");
/*PFNglProgramUniform4fv */    gles_glProgramUniform4fv = (PTR_glProgramUniform4fv)dlsym(libGL, "glProgramUniform4fv");
/*PFNglProgramUniformMatrix2fv */    gles_glProgramUniformMatrix2fv = (PTR_glProgramUniformMatrix2fv)dlsym(libGL, "glProgramUniformMatrix2fv");
/*PFNglProgramUniformMatrix3fv */    gles_glProgramUniformMatrix3fv = (PTR_glProgramUniformMatrix3fv)dlsym(libGL, "glProgramUniformMatrix3fv");
/*PFNglProgramUniformMatrix4fv */    gles_glProgramUniformMatrix4fv = (PTR_glProgramUniformMatrix4fv)dlsym(libGL, "glProgramUniformMatrix4fv");
/*PFNglProgramUniformMatrix2x3fv */    gles_glProgramUniformMatrix2x3fv = (PTR_glProgramUniformMatrix2x3fv)dlsym(libGL, "glProgramUniformMatrix2x3fv");
/*PFNglProgramUniformMatrix3x2fv */    gles_glProgramUniformMatrix3x2fv = (PTR_glProgramUniformMatrix3x2fv)dlsym(libGL, "glProgramUniformMatrix3x2fv");
/*PFNglProgramUniformMatrix2x4fv */    gles_glProgramUniformMatrix2x4fv = (PTR_glProgramUniformMatrix2x4fv)dlsym(libGL, "glProgramUniformMatrix2x4fv");
/*PFNglProgramUniformMatrix4x2fv */    gles_glProgramUniformMatrix4x2fv = (PTR_glProgramUniformMatrix4x2fv)dlsym(libGL, "glProgramUniformMatrix4x2fv");
/*PFNglProgramUniformMatrix3x4fv */    gles_glProgramUniformMatrix3x4fv = (PTR_glProgramUniformMatrix3x4fv)dlsym(libGL, "glProgramUniformMatrix3x4fv");
/*PFNglProgramUniformMatrix4x3fv */    gles_glProgramUniformMatrix4x3fv = (PTR_glProgramUniformMatrix4x3fv)dlsym(libGL, "glProgramUniformMatrix4x3fv");
/*PFNglValidateProgramPipeline */    gles_glValidateProgramPipeline = (PTR_glValidateProgramPipeline)dlsym(libGL, "glValidateProgramPipeline");
/*PFNglGetProgramPipelineInfoLog */    gles_glGetProgramPipelineInfoLog = (PTR_glGetProgramPipelineInfoLog)dlsym(libGL, "glGetProgramPipelineInfoLog");
/*PFNglBindImageTexture */    gles_glBindImageTexture = (PTR_glBindImageTexture)dlsym(libGL, "glBindImageTexture");
/*PFNglGetBooleani_v */    gles_glGetBooleani_v = (PTR_glGetBooleani_v)dlsym(libGL, "glGetBooleani_v");
/*PFNglMemoryBarrier */    gles_glMemoryBarrier = (PTR_glMemoryBarrier)dlsym(libGL, "glMemoryBarrier");
/*PFNglMemoryBarrierByRegion */    gles_glMemoryBarrierByRegion = (PTR_glMemoryBarrierByRegion)dlsym(libGL, "glMemoryBarrierByRegion");
/*PFNglTexStorage2DMultisample */    gles_glTexStorage2DMultisample = (PTR_glTexStorage2DMultisample)dlsym(libGL, "glTexStorage2DMultisample");
/*PFNglGetMultisamplefv */    gles_glGetMultisamplefv = (PTR_glGetMultisamplefv)dlsym(libGL, "glGetMultisamplefv");
/*PFNglSampleMaski */    gles_glSampleMaski = (PTR_glSampleMaski)dlsym(libGL, "glSampleMaski");
/*PFNglGetTexLevelParameteriv */    gles_glGetTexLevelParameteriv = (PTR_glGetTexLevelParameteriv)dlsym(libGL, "glGetTexLevelParameteriv");
/*PFNglGetTexLevelParameterfv */    gles_glGetTexLevelParameterfv = (PTR_glGetTexLevelParameterfv)dlsym(libGL, "glGetTexLevelParameterfv");
/*PFNglBindVertexBuffer */    gles_glBindVertexBuffer = (PTR_glBindVertexBuffer)dlsym(libGL, "glBindVertexBuffer");
/*PFNglVertexAttribFormat */    gles_glVertexAttribFormat = (PTR_glVertexAttribFormat)dlsym(libGL, "glVertexAttribFormat");
/*PFNglVertexAttribIFormat */    gles_glVertexAttribIFormat = (PTR_glVertexAttribIFormat)dlsym(libGL, "glVertexAttribIFormat");
/*PFNglVertexAttribBinding */    gles_glVertexAttribBinding = (PTR_glVertexAttribBinding)dlsym(libGL, "glVertexAttribBinding");
/*PFNglVertexBindingDivisor */    gles_glVertexBindingDivisor = (PTR_glVertexBindingDivisor)dlsym(libGL, "glVertexBindingDivisor");


// GL_ES_VERSION_3_2
/*PFNglBlendBarrier */    gles_glBlendBarrier = (PTR_glBlendBarrier)dlsym(libGL, "glBlendBarrier");
/*PFNglCopyImageSubData */    gles_glCopyImageSubData = (PTR_glCopyImageSubData)dlsym(libGL, "glCopyImageSubData");
/*PFNglDebugMessageControl */    gles_glDebugMessageControl = (PTR_glDebugMessageControl)dlsym(libGL, "glDebugMessageControl");
/*PFNglDebugMessageInsert */    gles_glDebugMessageInsert = (PTR_glDebugMessageInsert)dlsym(libGL, "glDebugMessageInsert");
///*PFNglDebugMessageCallback */    gles_glDebugMessageCallback = (PTR_glDebugMessageCallback)dlsym(libGL, "glDebugMessageCallback");
/*PFNglGetDebugMessageLog */    gles_glGetDebugMessageLog = (PTR_glGetDebugMessageLog)dlsym(libGL, "glGetDebugMessageLog");
/*PFNglPushDebugGroup */    gles_glPushDebugGroup = (PTR_glPushDebugGroup)dlsym(libGL, "glPushDebugGroup");
/*PFNglPopDebugGroup */    gles_glPopDebugGroup = (PTR_glPopDebugGroup)dlsym(libGL, "glPopDebugGroup");
/*PFNglObjectLabel */    gles_glObjectLabel = (PTR_glObjectLabel)dlsym(libGL, "glObjectLabel");
/*PFNglGetObjectLabel */    gles_glGetObjectLabel = (PTR_glGetObjectLabel)dlsym(libGL, "glGetObjectLabel");
/*PFNglObjectPtrLabel */    gles_glObjectPtrLabel = (PTR_glObjectPtrLabel)dlsym(libGL, "glObjectPtrLabel");
/*PFNglGetObjectPtrLabel */    gles_glGetObjectPtrLabel = (PTR_glGetObjectPtrLabel)dlsym(libGL, "glGetObjectPtrLabel");
/*PFNglGetPointerv */    gles_glGetPointerv = (PTR_glGetPointerv)dlsym(libGL, "glGetPointerv");
/*PFNglEnablei */    gles_glEnablei = (PTR_glEnablei)dlsym(libGL, "glEnablei");
/*PFNglDisablei */    gles_glDisablei = (PTR_glDisablei)dlsym(libGL, "glDisablei");
/*PFNglBlendEquationi */    gles_glBlendEquationi = (PTR_glBlendEquationi)dlsym(libGL, "glBlendEquationi");
/*PFNglBlendEquationSeparatei */    gles_glBlendEquationSeparatei = (PTR_glBlendEquationSeparatei)dlsym(libGL, "glBlendEquationSeparatei");
/*PFNglBlendFunci */    gles_glBlendFunci = (PTR_glBlendFunci)dlsym(libGL, "glBlendFunci");
/*PFNglBlendFuncSeparatei */    gles_glBlendFuncSeparatei = (PTR_glBlendFuncSeparatei)dlsym(libGL, "glBlendFuncSeparatei");
/*PFNglColorMaski */    gles_glColorMaski = (PTR_glColorMaski)dlsym(libGL, "glColorMaski");
/*PFNglIsEnabledi */    gles_glIsEnabledi = (PTR_glIsEnabledi)dlsym(libGL, "glIsEnabledi");
/*PFNglDrawElementsBaseVertex */    gles_glDrawElementsBaseVertex = (PTR_glDrawElementsBaseVertex)dlsym(libGL, "glDrawElementsBaseVertex");
/*PFNglDrawRangeElementsBaseVertex */    gles_glDrawRangeElementsBaseVertex = (PTR_glDrawRangeElementsBaseVertex)dlsym(libGL, "glDrawRangeElementsBaseVertex");
/*PFNglDrawElementsInstancedBaseVertex */    gles_glDrawElementsInstancedBaseVertex = (PTR_glDrawElementsInstancedBaseVertex)dlsym(libGL, "glDrawElementsInstancedBaseVertex");
/*PFNglFramebufferTexture */    gles_glFramebufferTexture = (PTR_glFramebufferTexture)dlsym(libGL, "glFramebufferTexture");
/*PFNglPrimitiveBoundingBox */    gles_glPrimitiveBoundingBox = (PTR_glPrimitiveBoundingBox)dlsym(libGL, "glPrimitiveBoundingBox");
/*PFNglGetGraphicsResetStatus */    gles_glGetGraphicsResetStatus = (PTR_glGetGraphicsResetStatus)dlsym(libGL, "glGetGraphicsResetStatus");
/*PFNglReadnPixels */    gles_glReadnPixels = (PTR_glReadnPixels)dlsym(libGL, "glReadnPixels");
/*PFNglGetnUniformfv */    gles_glGetnUniformfv = (PTR_glGetnUniformfv)dlsym(libGL, "glGetnUniformfv");
/*PFNglGetnUniformiv */    gles_glGetnUniformiv = (PTR_glGetnUniformiv)dlsym(libGL, "glGetnUniformiv");
/*PFNglGetnUniformuiv */    gles_glGetnUniformuiv = (PTR_glGetnUniformuiv)dlsym(libGL, "glGetnUniformuiv");
/*PFNglMinSampleShading */    gles_glMinSampleShading = (PTR_glMinSampleShading)dlsym(libGL, "glMinSampleShading");
/*PFNglPatchParameteri */    gles_glPatchParameteri = (PTR_glPatchParameteri)dlsym(libGL, "glPatchParameteri");
/*PFNglTexParameterIiv */    gles_glTexParameterIiv = (PTR_glTexParameterIiv)dlsym(libGL, "glTexParameterIiv");
/*PFNglTexParameterIuiv */    gles_glTexParameterIuiv = (PTR_glTexParameterIuiv)dlsym(libGL, "glTexParameterIuiv");
/*PFNglGetTexParameterIiv */    gles_glGetTexParameterIiv = (PTR_glGetTexParameterIiv)dlsym(libGL, "glGetTexParameterIiv");
/*PFNglGetTexParameterIuiv */    gles_glGetTexParameterIuiv = (PTR_glGetTexParameterIuiv)dlsym(libGL, "glGetTexParameterIuiv");
/*PFNglSamplerParameterIiv */    gles_glSamplerParameterIiv = (PTR_glSamplerParameterIiv)dlsym(libGL, "glSamplerParameterIiv");
/*PFNglSamplerParameterIuiv */    gles_glSamplerParameterIuiv = (PTR_glSamplerParameterIuiv)dlsym(libGL, "glSamplerParameterIuiv");
/*PFNglGetSamplerParameterIiv */    gles_glGetSamplerParameterIiv = (PTR_glGetSamplerParameterIiv)dlsym(libGL, "glGetSamplerParameterIiv");
/*PFNglGetSamplerParameterIuiv */    gles_glGetSamplerParameterIuiv = (PTR_glGetSamplerParameterIuiv)dlsym(libGL, "glGetSamplerParameterIuiv");
/*PFNglTexBuffer */    gles_glTexBuffer = (PTR_glTexBuffer)dlsym(libGL, "glTexBuffer");
/*PFNglTexBufferRange */    gles_glTexBufferRange = (PTR_glTexBufferRange)dlsym(libGL, "glTexBufferRange");
/*PFNglTexStorage3DMultisample */    gles_glTexStorage3DMultisample = (PTR_glTexStorage3DMultisample)dlsym(libGL, "glTexStorage3DMultisample");


	dlclose(libGL);
	
	Initialization_();
	
	return;
	
}

