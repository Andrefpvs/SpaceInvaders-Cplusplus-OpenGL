#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "GlobalManager.h"
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define TIMER 15.0f

#include "BMPReader.h"

GlobalManager *_manager;

void reshape(GLsizei w, GLsizei h){
    _manager->reshape(w,h);
}

void displayBarriers(){
    _manager->displayBarriers();
    
}

void displayAliens(){
    _manager->displayAliens();
}

void displayShip(){
    _manager->displayShip();
}

void displayBar(){
    _manager->displayBar();
}

void displays(){
    _manager->displays();

}
void processSpecialKeys(int key, int _xPos, int _yPos){

    _manager->processSpecialKeys(key, _xPos, _yPos);
}
void setCamera(){
    _manager->setCamera();
}
void myKeyboardFunction(unsigned char key, int x, int y){
    _manager->myKeyboardFunction(key, x, y);
}

void ingameTimer(int value){
	if(value != 0){
		_manager->processTimedBehaviour();
	}
	
    glutTimerFunc(TIMER, ingameTimer, 1);
}
