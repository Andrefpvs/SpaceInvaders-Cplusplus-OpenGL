#include "AlienType2.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
void AlienType2::drawAlien(bool wire){
	
	
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
	
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 0.0f, 0.0f, 1.0f };
	GLfloat mat_shine[]= { 10.0f };
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);
    
    
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glPushMatrix();
        glTranslatef(getX(), getY(), 0);
		glScalef(6, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_ONE, 0);
        glScalef(4, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()+DESLOC_TWO, 0);
        glScalef(2, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_ONE, 0);
        glScalef(UNIT, 1.5, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_THREE, getY()-DESLOC_ONE, 0);
        glScalef(2.5, 1.5, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_THREE, getY()-DESLOC_ONE, 0);
        glScalef(2.5, 1.5, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-1.5, 0);
        glScalef(8, 0.5, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_ONE, getY()-DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_ONE, getY()-DESLOC_TWO, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_TWO, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_TWO, getY()-DESLOC_THREE, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX(), getY()-DESLOC_THREE, 0);
        glScalef(2, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_ONE, getY()-DESLOC_FOUR, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()-DESLOC_THREE, getY()-DESLOC_FOUR, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_ONE, getY()-DESLOC_FOUR, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(getX()+DESLOC_THREE, getY()-DESLOC_FOUR, 0);
        glScalef(UNIT, UNIT, ALIEN2Z);
        glutSolidCube(UNIT);
    glPopMatrix();


}

int AlienType2::awardPoints(){
	return 200;
}
