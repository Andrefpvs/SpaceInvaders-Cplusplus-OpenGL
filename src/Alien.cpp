
#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Alien.h"
int counterX;

float Alien::getX(){
    return _xPos;
}
float Alien::getY(){
    return _yPos;
}

void Alien::setX(float x){
    _xPos = x;
}
void Alien::setY(float y){
    _yPos = y;
}

void Alien::setRadius(double radius){
	_radius = radius;
}

double Alien::getRadius(){
	return _radius;
}

void Alien::setCounterX(int x){
    _counterX = x;
}

int Alien::getCounterX(){
    return _counterX;
}

bool Alien::isDead(){
	return _dead;
}
bool Alien::isDying(){
	return _dying;
}
void Alien::setDead(bool dead){
	_dead = dead;
}
void Alien::setDying(bool dying){
	_dying = dying;
}

AlienShot* Alien::getShot(){
    return alienshot;
}


void Alien::moveRight(){
    setX(_xPos + INC_LR);
}

void Alien::moveLeft(){
    setX(_xPos - INC_LR);
}

void Alien::getDown(){
    setY(_yPos - INC_DOWN);
}

void Alien::backToRightLimit(){
    setX(_xPos - BACK_TO_LIMIT);
    counterX = counterX+1;
    setCounterX(counterX);    
}

void Alien::backToLeftLimit(){
    setX(_xPos + BACK_TO_LIMIT);
    counterX = counterX+1;
    setCounterX(counterX);
}

void Alien::drawShot(bool wire){
    alienshot->drawShot(wire);
}

void Alien::createShot(){
    alienshot = new AlienShot(getX(),getY(),true);
}

int Alien::getRow(){
	return _row;
}
int Alien::getColumn(){
	return _column;
}
void Alien::setRow(int row){
	_row = row;
}
void Alien::setColumn(int column){
	_column = column;
}

