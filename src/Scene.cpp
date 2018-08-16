#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "Shiness.h"
#include "Scene.h"
#include "BMPReader.h"
#define BACKGROUND_SIZE 500
#define size 20
using std::string;
using std::ostringstream;
using std::ios;
using std::ends;
using std::min;
using std::max;
bool    _texture2;
bool    _textureOn;
float Scene::getX(){
    return _xPos;
}
float Scene::getY(){
    return _yPos;
}
const bool Scene::LoadTexture( const string & textureFilename)
{
	BMPloader * bitmap = new BMPloader( textureFilename);
	if ( bitmap->Isvalid() )
	{
		glPixelStoref( GL_UNPACK_ALIGNMENT, 1);
		glEnable( GL_TEXTURE_2D);
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, bitmap->Width(), bitmap->Heigth(), 0, GL_RGB,
					 GL_UNSIGNED_BYTE, bitmap->Image());
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		_texture2 = _textureOn = true;
	}
	else
		_texture2 = _textureOn = false;
	delete bitmap;
	return _texture2;
}
void Scene::drawScene(){
	glEnable(GL_TEXTURE_2D);
    _texture2 = LoadTexture("x.bmp");
    
	glBindTexture(GL_TEXTURE_2D, _texture2);
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f };
	GLfloat mat_specular[] = {  0.0f, 1.0f, 1.0f };
	GLfloat mat_shine[] = { 10.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shine[0]);
   
   /* glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
    glNormal3d(0.0, 0.0, 1.0);
    glTexCoord2f(0, 0);
    glVertex3f(-BACKGROUND_SIZE, -BACKGROUND_SIZE, -20);
    glTexCoord2f(1, 0);
    glVertex3f( BACKGROUND_SIZE, -BACKGROUND_SIZE, -20);
    glTexCoord2f(1, 1);
    glVertex3f(BACKGROUND_SIZE,  BACKGROUND_SIZE, -20);
    glTexCoord2f(0, 1);
    glVertex3f(-BACKGROUND_SIZE,  BACKGROUND_SIZE, -20);*/

    // enable automatic texture coordinate generation glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP); glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
    // suppose that the texture has been loaded to d glBindTexture(GL_TEXTURE_2D, d);
    glPushMatrix();
    glTranslatef(0,140,50);
    glutSolidSphere(25.0,40,40);// draw a sphere with this sphere map glPopMatrix();
    glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    



    glEnd();
    
	glDisable(GL_TEXTURE_2D);
}