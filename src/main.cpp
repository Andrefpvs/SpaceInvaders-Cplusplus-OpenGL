#include <cstdlib>
#include <string>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define TIMER 200.0f
#include <vector>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "functions.h"
#include "GlobalManager.h"
#include "BMPReader.h"


extern bool _texture2;
extern GlobalManager *_manager;

int main(int argc, char ** argv){
	printf("SPACE INVADERS\nLoading game... please wait.");
    _manager = new GlobalManager();
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (-1, -1);
    glutCreateWindow("- SPACE INVADERS -");
    glClearColor(0,0,0,0);
    glutDisplayFunc(displays);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(myKeyboardFunction);
    glutSpecialFunc(processSpecialKeys);
    glutTimerFunc(TIMER, ingameTimer, 1);
    _manager->createGameObjects();
	glutMainLoop();
    
}