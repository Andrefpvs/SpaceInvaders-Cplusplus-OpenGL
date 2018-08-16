#ifndef __SpaceInvadersO__Camera2__
#define __SpaceInvadersO__Camera2__


#include "Camera.h"
class Camera2 : public Camera{
public:
	Camera2(int number) : Camera(number) {}
	int getNum();
    void setNum(int x);
    void applyProjection(int w, int h);
    
};
#endif
