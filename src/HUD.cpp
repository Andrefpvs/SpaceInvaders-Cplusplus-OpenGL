#include <iostream>
#include <string>
#include <sstream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "HUD.h"
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"

float HUD::getX(){
    return _xPos;
}
float HUD::getY(){
    return _yPos;
}
void HUD::setX(float x){
    _xPos = x;
}
void HUD::setY(float y){
    _yPos = y;
}


void HUD::drawHUD(int lives, int score, bool gameover, bool gamewon){
	
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glColor3d(1.0, 0, 0);

	std::string hud1 = "Lives: ";
	std::stringstream ss1;
	ss1 << lives;
	hud1 += ss1.str();
	const char* c_hud1 = hud1.c_str();
	glRasterPos2i(-80, -95);
	for(int i=0; i<hud1.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c_hud1[i]);

	std::string hud2 = "Score: ";
	std::stringstream ss2;
	ss2 << score;
	hud2 += ss2.str();
	const char* c_hud2 = hud2.c_str();
	glRasterPos2i(70, -95);
	for(int i=0; i<hud2.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c_hud2[i]);

	if(gameover){
		std::string hud3 = "GAME OVER";
		const char* c_hud3 = hud3.c_str();
		glRasterPos2i(-15, -83);
		for(int i=0; i<hud3.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c_hud3[i]);
	}

	if(gamewon && !gameover){
		glColor3d(0.1, 1.0, 0.0);
		std::string hud3 = "CONGRATULATIONS!";
		const char* c_hud3 = hud3.c_str();
		glRasterPos2i(-17, 10);
		for(int i=0; i<hud3.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c_hud3[i]);
		hud3 = "You saved the Universe!";
		c_hud3 = hud3.c_str();
		glRasterPos2i(-18, 3);
		for(int i=0; i<hud3.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c_hud3[i]);
	}

	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	
}