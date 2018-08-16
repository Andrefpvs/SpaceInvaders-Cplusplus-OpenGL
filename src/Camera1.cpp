#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Camera1.h"
#define PROPORTION 100.0f
extern float xLocation;
void Camera1::applyProjection(int global_width, int global_height){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(100.0f, ((float) global_width)/global_height, PROPORTION/4, 10*PROPORTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(xLocation, -110, 40, 0, 0, 0, 0, 0, 1); //VISTA EM PRIMEIRA PESSOA eye,lookat, up

}