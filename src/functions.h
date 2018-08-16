#ifndef SpaceInvadersO_functions_h
#define SpaceInvadersO_functions_h
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void reshape(GLsizei w, GLsizei h);
void displayBarriers();
void displayAliens();
void displayShip();
void displayBar();
void displays();
void processSpecialKeys(int key, int _xPos, int _yPos);
void setCamera();
void myKeyboardFunction(unsigned char key, int x, int y);
void ingameTimer(int value);

#endif
