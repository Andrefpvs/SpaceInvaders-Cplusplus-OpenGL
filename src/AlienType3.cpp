#include "AlienType3.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
void AlienType3::drawAlien(bool wire){

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

	GLfloat mat_diffuse[] = { 1.0f, 0.2f, 0.5f};
	GLfloat mat_specular[] = { 1.0f, 0.2f, 0.5f};
	GLfloat mat_shine[] = {10.0f};
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);
	    
    glColor3f(1.0f, 0.2f, 0.5f); //pink
    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_TWO, 0);
        glScalef(3, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_ONE, 0);
        glScalef(7, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY(), 0);
        glScalef(9, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_ONE, 0);
        glScalef(3, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_FOUR, getY()-DESLOC_ONE, 0);
        glScalef(UNIT, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_FOUR, getY()-DESLOC_ONE, 0);
        glScalef(UNIT, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_TWO, 0);
        glScalef(9, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_ONE_HALF, getY()-DESLOC_THREE, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_ONE_HALF, getY()-DESLOC_THREE, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_TWO_HALF, getY()-DESLOC_FOUR, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_TWO_HALF, getY()-DESLOC_FOUR, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_FOUR, 0);
        glScalef(UNIT, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_THREE_HALF, getY()-DESLOC_FIVE, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_THREE_HALF, getY()-DESLOC_FIVE, 0);
        glScalef(2, UNIT, ALIEN3Z);
        glutSolidCube(UNIT);
    glPopMatrix();


}
int AlienType3::awardPoints(){
	return 100;
}