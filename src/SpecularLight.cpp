
#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "SpecularLight.h"
void SpecularLight::applyLight(float mat_specular[]){
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
}