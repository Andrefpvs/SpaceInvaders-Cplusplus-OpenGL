#ifndef __SpaceInvadersO__Light__
#define __SpaceInvadersO__Light__

class Light {
    int _num;
public:
	Light(int number) : _num(number){}
	int getNum();
    void setNum(int x);
    virtual void applyLight(float vector[]) = 0;
    
};
#endif