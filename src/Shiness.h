#ifndef __SpaceInvadersO__Shiness__
#define __SpaceInvadersO__Shiness__


#include "Light.h"
class Shiness : public Light{
public:
	Shiness(int number) : Light(number) {}
	int getNum();
    void setNum(int x);
    void applyLight(float shiness[]);   
};
#endif
