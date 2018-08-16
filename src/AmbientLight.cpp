#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "AmbientLight.h"
#define PROPORTION 100.0f
void AmbientLight::applyLight(float no_mat[]){
        glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
}
