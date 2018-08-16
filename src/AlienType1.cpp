#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "AlienType1.h"
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"

void AlienType1::drawAlien(bool wire){
	

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

	GLfloat mat_diffuse[] = { 0.0f, 1.0f, 0.0f };
	GLfloat mat_specular[] = {  0.0f, 1.0f, 0.0f };
	GLfloat mat_shine[] = { 10.0f };
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);
    
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glPushMatrix();
		glTranslatef(getX(), getY(), 0);
        glScalef(2, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_THREE, getY(), 0);
        glScalef(2, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_THREE, getY(), 0);
        glScalef(2, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(getX(), getY()-1, 0);
    glScalef(10, UNIT, ALIEN1Z);
    glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()+1, 0);
        glScalef(7, UNIT, 4);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_THREE, getY()+DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_TWO, getY()+DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_THREE, getY()+DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_TWO, getY()+DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_TWO, 0);
        glScalef(6, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FOUR_HALF, getY()-DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FOUR_HALF, getY()-DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FOUR_HALF, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FOUR_HALF, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_TWO_HALF, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_TWO_HALF, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-1.5, getY()-DESLOC_FOUR, 0);
        glScalef(1.5, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+1.5, getY()-DESLOC_FOUR, 0);
        glScalef(1.5, UNIT, ALIEN1Z);
        glutSolidCube(UNIT);
    glPopMatrix();
 
}

int AlienType1::awardPoints(){
	return 300;
}