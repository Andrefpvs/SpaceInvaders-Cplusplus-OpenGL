#ifndef __SPACEINVADERS_EXPLOSION_H__
#define __SPACEINVADERS_EXPLOSION_H__

#include <list>
#include "Particle.h"
	
	class Explosion{

	protected:
		std::list<Particle*> _activePtc, _deadPtc;
		bool exploding;

	public:
		Explosion(float x, float y);
		virtual void update();
		virtual void draw();
		bool isExploding(){ return exploding; }
	};

#endif