#ifndef __SpaceInvadersO__Camera1__
#define __SpaceInvadersO__Camera1__


#include "Camera.h"
class Camera1 : public Camera {
public:
	Camera1(int number) : Camera(number) {}
	int getNum();
    void setNum(int x);
    void applyProjection(int w, int h);
    
};
#endif
