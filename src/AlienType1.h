#ifndef __SpaceInvadersO__AlienType1__
#define __SpaceInvadersO__AlienType1__


#include "Alien.h"
class AlienType1 : public Alien{
    
public:
	AlienType1(float x_pos, float y_pos, int row, int column) : Alien(x_pos, y_pos, row, column) {
		setRadius(6);
	}
	void drawAlien(bool wire);
	int awardPoints();
    
};

#endif 