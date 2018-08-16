#ifndef __SPACEINVADERS_PARTICLE_H__
#define __SPACEINVADERS_PARTICLE_H__
#include "DiffuseLight.h"
#include "SpecularLight.h"
#include "AmbientLight.h"
#include "Shiness.h"
#include "Light.h"


class Particle{
protected:
		float	_life;
		float	_fade;
		float	_r, _g, _b;
		float   _x,  _y,  _z; 
		float   vx, vy, vz; 
		float   ax, ay, az; 
		float   elapsed;

public:
		Light* lightS;
		Light* lightD;
		Light* lightA;
		Light* shine;
		Particle(float x, float y); 
		virtual void respawn();
		virtual void draw();
		virtual void update();

		inline bool alive(){ return _life > 0.f; }

};


#endif