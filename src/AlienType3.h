#ifndef __SpaceInvadersO__AlienType3__
#define __SpaceInvadersO__AlienType3__

#include <iostream>
#include "Alien.h"
class AlienType3 : public Alien{
    
public:
	AlienType3(float x_pos, float y_pos, int row, int column) : Alien(x_pos, y_pos, row, column) {
		setRadius(6);
	}
	void drawAlien(bool wire);
    int awardPoints();
};

#endif