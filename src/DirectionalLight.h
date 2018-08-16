#ifndef __SpaceInvadersO__DirectionalLight__
#define __SpaceInvadersO__DirectionalLight__
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Light.h"
class DirectionalLight : public Light{
public:
	DirectionalLight(int number) : Light(number) {}
	int getNum();
    void setNum(int x);
    void applyLight(float direction[]);
    void applyLight3(float direction2[]);
    
};
#endif
