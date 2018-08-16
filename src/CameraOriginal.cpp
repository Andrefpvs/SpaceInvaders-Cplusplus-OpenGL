#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "CameraOriginal.h"
#define PROPORTION 100.0f
void CameraOriginal::applyProjection(int global_width, int global_height){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
        if(global_width/global_height >= 1){
            glOrtho(-PROPORTION*global_width/global_height, PROPORTION*global_width/global_height, -PROPORTION, PROPORTION, -PROPORTION, PROPORTION);
        }
        else if(global_height/global_width >= 1){
            glOrtho(-PROPORTION, PROPORTION, -PROPORTION*global_height/global_width, PROPORTION*global_height/global_width, -PROPORTION, PROPORTION);
        }
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}