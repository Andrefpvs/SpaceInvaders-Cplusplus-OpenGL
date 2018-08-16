#define BARRIERZ 3
#define UNIT 1
#include "Barrier.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
float Barrier::getX(){
    return _xPos;
}

float Barrier::getY(){
    return _yPos;
}

double Barrier::getRadius(){
	return _radius;
}

int Barrier::getLife(){
	return _life;
}

void Barrier::setLife(int life){
	_life = life;
}

void Barrier::drawBarrier(bool wire){
	if(wire){		
		glPushMatrix();
		GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f };
		GLfloat mat_specular[] = {  1.0f, 1.0f, 1.0f };
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

	float color_factor = getLife()*0.01f;
	GLfloat mat_diffuse[] = { 1.0f*color_factor, 0.5f*color_factor, 0.0f };
	GLfloat mat_specular[] = { 1.0f*color_factor, 0.5f*color_factor, 0.0f };
	GLfloat mat_shine[] = { 10.0f };

    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);

    glPushMatrix();
        glTranslatef(getX(), getY()+3, 0);
        glScalef(8, 2, BARRIERZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(getX(), getY()+2, 0);
    glScalef(10, 2, BARRIERZ);
    glutSolidCube(UNIT);
    glPopMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); //orange
    glPushMatrix();
    glTranslatef(getX(), getY(), 0);
    glScalef(11, 6, BARRIERZ);
    glutSolidCube(UNIT);
    glPopMatrix();
}
