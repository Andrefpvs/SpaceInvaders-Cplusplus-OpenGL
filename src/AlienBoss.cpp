#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "AlienBoss.h"
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"

void AlienBoss::drawAlien(){
	GLfloat mat_diffuse[] = { 1.0f, 0.0f, 0.0f };
	GLfloat mat_specular[] = { 1.0f, 0.0f, 0.0f };
	GLfloat mat_shine[] = { 10.0f };
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);

    
    glColor3f(1.0f, 0.0f, 0.0f); //red

    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_TWO, 0);
        glScalef(6, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_ONE, 0);
        glScalef(10, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY(), 0);
        glScalef(2, 2, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_TWO_HALF, getY(), 0);
        glScalef(UNIT, 2, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FIVE, getY(), 0);
        glScalef(2.5, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FIVE, getY(), 0);
        glScalef(2.5, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_TWO_HALF, getY(), 0);
        glScalef(UNIT, 2, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_ONE, 0);
        glScalef(14, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_TWO, 0);
        glScalef(2, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FOUR, getY()-DESLOC_TWO, 0);
        glScalef(3, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FOUR, getY()-DESLOC_TWO, 0);
        glScalef(3, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FOUR, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FOUR, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIENBOSSZ);
        glutSolidCube(UNIT);
    glPopMatrix();


}