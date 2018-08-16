#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Camera2.h"
#define PROPORTION 100.0f
extern float xLocation;
void Camera2::applyProjection(int global_width, int global_height){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(90.0f, ((float) global_width)/global_height, PROPORTION/8, 10*PROPORTION); //fovy aspect znear zfar
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(xLocation, -77, 20, xLocation, 0, 0, 0, 0, 1); //CAMARA ATRAS DA NAVE    
}