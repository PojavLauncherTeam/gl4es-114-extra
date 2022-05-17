#include "Initialization.h"
#include "load.h"
//#include "pack.h"


int MaxDrawBuffers = 0;
int MaxColorAttachs = 0;

GLfloat ClearColorValue[4] = {0.0, 0.0, 0.0, 0.0};
GLfloat ClearDepthValue[4] = {0.0, 0.0, 0.0, 0.0};
GLint ClearStencilValue[4] = {0, 0, 0, 0};

GLenum Attachs[8] = {
	//GL_NONE,
	GL_COLOR_ATTACHMENT0,
	GL_COLOR_ATTACHMENT1,
	GL_COLOR_ATTACHMENT2,
	GL_COLOR_ATTACHMENT3,
	GL_COLOR_ATTACHMENT4,
	GL_COLOR_ATTACHMENT5,
	GL_COLOR_ATTACHMENT6,
	GL_COLOR_ATTACHMENT7,
};

int DrawBufs_Num = 0;
GLenum DrawBufs[8] = {
	//GL_NONE,
	GL_COLOR_ATTACHMENT0,
	GL_COLOR_ATTACHMENT1,
	GL_COLOR_ATTACHMENT2,
	GL_COLOR_ATTACHMENT3,
	GL_COLOR_ATTACHMENT4,
	GL_COLOR_ATTACHMENT5,
	GL_COLOR_ATTACHMENT6,
	GL_COLOR_ATTACHMENT7,
};



void Initialization_(void){
	_LOAD_GLES
	
	gles_glGetIntegerv(GL_MAX_DRAW_BUFFERS, &MaxDrawBuffers);
	gles_glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &MaxColorAttachs);
	
	return;
}