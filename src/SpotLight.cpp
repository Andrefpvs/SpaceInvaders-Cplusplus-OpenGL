#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "SpotLight.h"
#define PROPORTION 100.0f
void SpotLight::applyLight(float mat_specular[], float light_position[], float spotDir[]){
    glLightfv(GL_LIGHT1,GL_SPECULAR,mat_specular);
    glLightfv(GL_LIGHT1,GL_POSITION,light_position);
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,60.0);
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,102.0);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotDir);
}
void SpotLight::applyLight(float light_position[]){
    glLightfv(GL_LIGHT1,GL_POSITION,light_position);
}