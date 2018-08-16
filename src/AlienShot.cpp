#include <iostream>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "AlienShot.h"
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
#define WINDOW_LIMIT 95
#define TOP_LIMIT 90 //valores ideais entre 90 e 100
#define VELOCITY 0.6f //4.5 e' o valor ideal para disparar tiros 'nao colados'
extern float xLocation;

float AlienShot::getX(){
    return _xPos;
}
float AlienShot::getY(){
    return _yPos;
}

double AlienShot::getRadius(){
	return _radius;
}

bool AlienShot::isFired(){
	return _fired;
}

void AlienShot::setX(float x){ //em principio este setter nunca sera usado, visto o movimento ser vertical
    _xPos = x;
}
void AlienShot::setY(float y){
    _yPos = y;
}

void AlienShot::setRadius(double radius){
	_radius = radius;
}

void AlienShot::setFired(bool fire){
	_fired = fire;
}
void AlienShot::drawShot(bool wire){
	if(wire){		
		glPushMatrix();
		GLfloat mat_diffuse[] = { 1.0f, 0.2f, 0.2f };
		GLfloat mat_specular[] = {  1.0f, 0.2f, 0.2f };
		GLfloat mat_shine[] = { 10.0f };
		lightD = new DiffuseLight(1);
		lightS = new SpecularLight(2);
		shine = new Shiness(0);
		lightD->applyLight(mat_diffuse);
		lightS->applyLight(mat_specular);
		shine->applyLight(mat_shine);
		glTranslatef(getX(), getY(), 0);	
		glutWireSphere(getRadius(), 8, 8);			
		glPopMatrix();
	}


	GLfloat mat_diffuse[] = { 0.6, 0.6, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_shine[] = { 10.0f };
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);
    
    glPushMatrix();
    glTranslatef(0,0,0);
    glPushMatrix();
    glTranslatef(getX(), getY(), 0); //desenha o tiro na nova posicao. Notar que o X inicial nunca se altera
    glScalef(2, 2, 3);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
}


void AlienShot::moveShotDown(){
    if (getY() > -TOP_LIMIT){
        setY(getY()-VELOCITY);
    }
    
    if (getY() <= -TOP_LIMIT){
        setFired(false);
    }
}