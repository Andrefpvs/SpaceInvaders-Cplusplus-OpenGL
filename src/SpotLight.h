#ifndef __SpaceInvadersO__SpotLight__
#define __SpaceInvadersO__SpotLight__
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Light.h"
class SpotLight : public Light{
public:
	SpotLight(int number) : Light(number) {}
    int getNum();
    void setNum(int x);
    void applyLight(float light_position[]);
    void applyLight(float mat_specular[], float light_position[], float spotDir[]);
    
};

#endif