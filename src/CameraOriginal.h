#ifndef __SpaceInvadersO__CameraOriginal__
#define __SpaceInvadersO__CameraOriginal__


#include "Camera.h"
class CameraOriginal : public Camera{
public:
	CameraOriginal(int number) : Camera(number) {}
	int getNum();
    void setNum(int x);
    void applyProjection(int w, int h);
    
};
#endif 
