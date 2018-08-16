#ifndef __SpaceInvadersO__Camera__
#define __SpaceInvadersO__Camera__

class Camera {
    int _num;
public:
	Camera(int number) : _num(number){}
	int getNum();
    void setNum(int x);
    virtual void applyProjection(int w, int h) = 0;

};
#endif