#ifndef __SI__AmbientLight__
#define __SI__AmbientLight__
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Light.h"
class AmbientLight : public Light{
public:
	AmbientLight(int number) : Light(number) {}
    int getNum();
    void setNum(int x);
    void applyLight(float no_mat[]);
    
};

#endif