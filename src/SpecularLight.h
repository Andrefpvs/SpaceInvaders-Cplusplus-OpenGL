#ifndef __SpaceInvadersO__SpecularLight__
#define __SpaceInvadersO__SpecularLight__

#include "Light.h"
class SpecularLight : public Light{
public:
	SpecularLight(int number) : Light(number) {}
	int getNum();
    void setNum(int x);
    void applyLight(float mat_specular[]);
    
};
#endif 
