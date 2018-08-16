#ifndef __SpaceInvadersO__Ship__
#define __SpaceInvadersO__Ship__

#include <iostream>
#include "Light.h"
class Ship {
	float _xPos;
	float _yPos;
	double _radius;
	bool _dying;
public:
    Light* lightS;
    Light* lightD;
    Light* shine;
	Ship(float x_pos, float y_pos) : _xPos(x_pos), _yPos(y_pos) {
		setDying(false);
	} 
    
	float getX();
    float getY();
	double getRadius();
	bool getDying();
	void setDying(bool dying);
	void setRadius(double radius);
	virtual void drawShip(bool wire) = 0;									
	virtual void moveShipLeft(bool wire) = 0;
    virtual void moveShipRight(bool wire) = 0;
};

#endif 
