#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Shiness.h"
void Shiness::applyLight(float mat_shine[]){
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shine[0]);
}
