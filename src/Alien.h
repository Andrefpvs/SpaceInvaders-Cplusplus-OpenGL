#ifndef __SpaceInvadersO__Alien__
#define __SpaceInvadersO__Alien__
#define ALIENBOSSZ 4
#define ALIEN1Z 4
#define ALIEN2Z 4
#define ALIEN3Z 4
#define UNIT 1
#define DESLOC_ONE 1
#define DESLOC_ONE_HALF 1.5
#define DESLOC_TWO 2
#define DESLOC_TWO_HALF 2.5
#define DESLOC_THREE 3
#define DESLOC_THREE_HALF 3.5
#define DESLOC_FOUR 4
#define DESLOC_FOUR_HALF 4.5
#define DESLOC_FIVE 5
#define INC_LR 0.2
#define INC_DOWN 3
#define BACK_TO_LIMIT 5
#include "AlienShot.h"
#include "Light.h"


class Alien {
	float _xPos;
	float _yPos;
	double _radius;
	int _counterY;
    int _counterX;
	bool _dead;
	bool _dying;
    AlienShot* alienshot;	
	int _row;
	int _column;
    
public:
    Light* lightS;
    Light* lightD;
    Light* shine;
	Alien(float x_pos, float y_pos, int row, int column) : _xPos(x_pos), _yPos(y_pos), _counterX(0), _row(row), _column(column) {
		alienshot = new AlienShot(getX(),getY(),false);
		_dead = _dying = false;
    }
	float getX();
	float getY();
	double getRadius();
    void setCounterX(int x);
    void setX(float x);
    void setY(float y);
	void setRadius(double radius);
    int getCounterX();
	bool isDead();
	bool isDying();
	void setDead(bool dead);
	void setDying(bool dying);
    void createShot();
	virtual void drawAlien(bool wire) = 0;
	virtual int awardPoints() = 0;
	int getRow();
	int getColumn();
	void setRow(int row);
	void setColumn(int column);
	
    void moveAlien();
    void moveRight();
    void moveLeft();
    void getDown();
    void backToRightLimit();
    void backToLeftLimit();
    void drawShot(bool wire);
    AlienShot* getShot();

};
#endif 
