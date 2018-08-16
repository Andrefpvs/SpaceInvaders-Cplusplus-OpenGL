#ifndef __SpaceInvadersO__Barrier__
#define __SpaceInvadersO__Barrier__

#include <iostream>
#include "Light.h"
class Barrier {
	float _xPos;
	float _yPos;
	int _life;
	double _radius;
public:
    Light* lightS;
    Light* lightD;
    Light* shine;
	Barrier(float x_pos, float y_pos) : _xPos(x_pos), _yPos(y_pos) {
		_radius = 6;
		_life =100;
	}
    
	float getX();
	float getY();
	int getLife();
	void setLife(int life);
    double getRadius();
	void drawBarrier(bool wire);
};
#endif 
