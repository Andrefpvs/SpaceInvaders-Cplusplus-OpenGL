#include <iostream>
#include "DiffuseLight.h"

void DiffuseLight::applyLight(GLfloat mat_diffuse[]){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}