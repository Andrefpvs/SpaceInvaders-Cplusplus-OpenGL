#ifndef __SpaceInvadersO__AlienShot__
#define __SpaceInvadersO__AlienShot__


#include "Light.h"
class AlienShot {
    float _xPos;
	float _yPos;
	double _radius;
	bool _fired; //'true' desde o periodo em que e' disparado ate ultrapassar o limite superior do jogo
public:
    Light* lightS;
    Light* lightD;
    Light* shine;
	AlienShot(float x_pos, float y_pos, bool fired) : _xPos(x_pos), _yPos(y_pos), _fired(fired) {
		setRadius(1.3);
	}
	void drawShot(bool wire);
    
	float getX();
	float getY();
	double getRadius();
	bool isFired();
    
    void setX(float x);
    void setY(float y);
	void setRadius(double radius);
	void setFired(bool fire);
    
	void moveShotDown();
    
};
#endif