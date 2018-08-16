#define VELOCITY 1.9f
#define WINDOW_LIMIT 89
#include "ShipType1.h"
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
#define size 1

float xLocation = 0.7f;
void ShipType1::drawShip(bool wire){


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
		glTranslatef(xLocation, getY(), 0);	
		glutWireSphere(getRadius(), 8, 8);			
		glPopMatrix();
	}



	GLfloat mat_diffuse[] = { 0.2, 0.2, 1.0, 1.0 };
	GLfloat mat_specular[] = { 0.2, 0.2, 1.0, 1.0 };
	GLfloat mat_shine[] = { 200.0f };
    lightD = new DiffuseLight(1);
    lightS = new SpecularLight(2);
    shine = new Shiness(0);
    lightD->applyLight(mat_diffuse);
    lightS->applyLight(mat_specular);
    shine->applyLight(mat_shine);

    
	glColor3f(0.2f, 0.2f, 1.0f);
	
    glTranslatef(xLocation, 0.0f, 0.0f);
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    glTranslatef(getX(), 0, -getY()-2);
    glScalef(1.5, 2, 2.5);
    
    glPushMatrix();
    glBegin(GL_QUADS);
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3f(-size, -size, size);
    glVertex3f( size, -size, size);
    glVertex3f( size,  size, size);
    glVertex3f(-size,  size, size);
    glEnd();
    // face 3, back, x y plane
    glBegin(GL_QUADS);   // face 3
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3f( size,  size, -size);
    glVertex3f(-size,  size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f( size, -size, -size);
    glEnd();
    // face 2 right, y z plane
    glBegin(GL_QUADS);   // face 2
    glNormal3d(1.0, 0.0, 0.0);
    glVertex3f( size, -size,  size);
    glVertex3f( size, -size, -size);
    glVertex3f( size,  size, -size);
    glVertex3f( size,  size,  size);
    glEnd();
    // face 4, left, yz plane
    glBegin(GL_QUADS);   // face 4
    glNormal3d(-1.0, 0.0, 0.0);
    glVertex3f(-size,  size,  size);
    glVertex3f(-size,  size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, -size,  size);
    glEnd();
    // face 5 top xz plane
    glBegin(GL_QUADS);
    glNormal3d(0.0, 1.0, 0.0);
    glVertex3f( size, size,  size);
    glVertex3f( size, size, -size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size,  size);
    glEnd();
    // face 6, bottom, xz plane
    glBegin(GL_QUADS);   // face 6
    glNormal3d(0.0,-1.0, 0.0);
    glVertex3f( size, -size, -size);
    glVertex3f( size, -size,  size);
    glVertex3f(-size, -size,  size);
    glVertex3f(-size, -size, -size);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    glTranslatef(getX(), 0, -getY());
    glScalef(5, 2.5, 2.5);
    glPushMatrix();
    glPushMatrix();
    glBegin(GL_QUADS);
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3f(-size, -size, size);
    glVertex3f( size, -size, size);
    glVertex3f( size,  size, size);
    glVertex3f(-size,  size, size);
    glEnd();
    // face 3, back, x y plane
    glBegin(GL_QUADS);   // face 3
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3f( size,  size, -size);
    glVertex3f(-size,  size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f( size, -size, -size);
    glEnd();
    
    // face 2 right, y z plane
    glBegin(GL_QUADS);   // face 2
    glNormal3d(1.0, 0.0, 0.0);
    glVertex3f( size, -size,  size);
    glVertex3f( size, -size, -size);
    glVertex3f( size,  size, -size);
    glVertex3f( size,  size,  size);
    glEnd();

    // face 4, left, yz plane
    glBegin(GL_QUADS);   // face 4
    glNormal3d(-1.0, 0.0, 0.0);
    glVertex3f(-size,  size,  size);
    glVertex3f(-size,  size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, -size,  size);
    glEnd();
    // face 5 top xz plane
    glBegin(GL_QUADS);
    glNormal3d(0.0, 1.0, 0.0);
    glVertex3f( size, size,  size);
    glVertex3f( size, size, -size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size,  size);
    glEnd();
    // face 6, bottom, xz plane
    glBegin(GL_QUADS);   // face 6
    glNormal3d(0.0,-1.0, 0.0);
    glVertex3f( size, -size, -size);
    glVertex3f( size, -size,  size);
    glVertex3f(-size, -size,  size);
    glVertex3f(-size, -size, -size);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    float mat_speculars[] = { 1.0, 1.0, 1.0, 1.0 };
    float light_position[] = { getX(),getY()+5,5, 1.0 };
    float spotDir[] = { 0,100,0};
    spot = new SpotLight(1);
    spot->applyLight(mat_speculars, light_position, spotDir);
    

}

void ShipType1::moveShipLeft(bool wire){
    if (xLocation > -WINDOW_LIMIT){
        xLocation -= VELOCITY;
        drawShip(wire);
        
    //    glFlush();
        
    }
}
void ShipType1::moveShipRight(bool wire){
    if (xLocation <= WINDOW_LIMIT){
        xLocation += VELOCITY;
        drawShip(wire);
      //  glFlush();
    }
}