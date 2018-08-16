#ifndef __SpaceInvadersO__DiffuseLight__
#define __SpaceInvadersO__DiffuseLight__
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Light.h"
class DiffuseLight : public Light {
public:
	DiffuseLight(int number) : Light(number) {}
	int getNum();
    void setNum(int x);
    void applyLight(float mat_diffuse[]);
    
};
#endif
