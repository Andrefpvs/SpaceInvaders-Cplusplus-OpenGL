#ifndef __SpaceInvadersO__AlienBoss__
#define __SpaceInvadersO__AlienBoss__


#include "Alien.h"
class AlienBoss : public Alien{
    
public:
	AlienBoss(float x_pos, float y_pos) : Alien(x_pos, y_pos,0,0) {}
	void drawAlien();
    
};

#endif