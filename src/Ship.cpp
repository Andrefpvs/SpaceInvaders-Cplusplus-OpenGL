#include "Ship.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
float Ship::getX(){
    return _xPos;
}

float Ship::getY(){
    return _yPos;
}

double Ship::getRadius(){
	return _radius;
}

bool Ship::getDying(){
	return _dying;
}

void Ship::setRadius(double radius){
	_radius = radius;
}

void Ship::setDying(bool dying){
	_dying = dying;
}