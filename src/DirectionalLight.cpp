#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "DirectionalLight.h"
#define PROPORTION 100.0f
void DirectionalLight::applyLight(GLfloat direction[]){
	glLightfv(GL_LIGHT0, GL_POSITION, direction);
}

void DirectionalLight::applyLight3(GLfloat direction[]){
	glLightfv(GL_LIGHT3, GL_POSITION, direction);
}