#ifndef __SpaceInvadersO__AlienType2__
#define __SpaceInvadersO__AlienType2__

#include <iostream>
#include "Alien.h"
class AlienType2 : public Alien{
    
public:
	AlienType2(float x_pos, float y_pos, int row, int column) : Alien(x_pos, y_pos, row, column) {
		setRadius(6);
	}
	void drawAlien(bool wire);
    int awardPoints();
};
#endif 
