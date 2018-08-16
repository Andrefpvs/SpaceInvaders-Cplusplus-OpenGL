#ifndef __SI__HUD__
#define __SI__HUD__


#include "Light.h"
class HUD {
	float _xPos;
	float _yPos;

    
public:
    Light* lightS;
    Light* lightD;
    Light* shine;
	HUD(float x_pos, float y_pos) : _xPos(x_pos), _yPos(y_pos){}
	float getX();
	float getY();
    void setX(float x);
    void setY(float y);
	void drawHUD(int lives, int score, bool gameover, bool gamewon);
};

#endif 
