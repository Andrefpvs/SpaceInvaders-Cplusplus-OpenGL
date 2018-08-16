#include <cmath>
#include <stdlib.h>
#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "Particle.h"

#define frand()			((float)rand()/RAND_MAX)
#define M_PI 3.14159265
#define DELTA		0.02278 //original = 0.00278
#define F_FADING    84


Particle::Particle(float x, float y){

	_x = x; _y = y; _z = 0.0f;
	respawn();

}

void Particle::respawn(){

	double v = 10.8*frand()+1.0;
    double phi = frand()*M_PI;
    double theta = 2.0*frand()*M_PI;
    vx = v * cos(theta) * sin(phi);
    vy = v * cos(phi);
    vz = v * sin(theta) * sin(phi);
    ax =  0.10f; /* just a little wind */
    ay = -0.15f; /* gravity pull */
    az =  0.0f;
        
    _r = 1.3f;
    _g = 1.3;
    _b = 1.3f;
        
    _life = 1.0f;		                        /* life granted to particle */
	_fade = 0.0001515 + frand() * .000303;	    /* life decay */
	elapsed = glutGet(GLUT_ELAPSED_TIME);

}

void Particle::draw(){
	float dif[] = {_r, _g, _b, 1.0f};
	float spec[] = {_r, _g, _b, 1.0f};
	
	glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, 0.0);
		lightD = new DiffuseLight(1);
		lightS = new SpecularLight(2);
		lightD->applyLight(dif);
		lightS->applyLight(spec);
		

	glPushMatrix();
    glTranslatef( _x, _y, _z);
	glutSolidSphere(0.5f, 8, 8);
    glPopMatrix();
}

void Particle::update()
{
   
    if ( _life > 0. )
    {
        _x += (vx * DELTA);
        _y += (vy * DELTA);
        _z += (vz * DELTA);
        vx += (ax * DELTA);
        vy += (ay * DELTA);
        vz += (az * DELTA);
        _life -= (_fade * F_FADING);
		
		float passed = glutGet(GLUT_ELAPSED_TIME);

		if(passed - elapsed > 400){
		_r -= 0.03f;
		_g -= 0.05f;
		_b -= 0.1f;
	}else {_r -= 0.009f;
		_g -= 0.01f;
		_b -= 0.1f;}
		
    }	

}