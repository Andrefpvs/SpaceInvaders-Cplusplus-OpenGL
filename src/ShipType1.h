#ifndef __SpaceInvadersO__ShipType1__
#define __SpaceInvadersO__ShipType1__

#include <iostream>
#include "Ship.h"
#include "SpotLight.h"
class ShipType1 : public Ship{
    SpotLight* spot;
public:
	ShipType1(float x_pos, float y_pos) : Ship(x_pos, y_pos) {
		setRadius(5.5);
	}
    
	void drawShip(bool wire);
	void moveShipLeft(bool wire);
    void moveShipRight(bool wire);
};

#endif
