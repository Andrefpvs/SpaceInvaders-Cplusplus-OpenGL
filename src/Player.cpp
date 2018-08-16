#include <iostream>
#include "Player.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

int Player::getScore(){
	return _score;
}
int Player::getLives(){
	return _lives;
}

void Player::setScore(int score){
	_score = score;
}							
void Player::setLives(int lives){
	_lives = lives;
}

void Player::addScore(int score){
	_score = _score + score;
}