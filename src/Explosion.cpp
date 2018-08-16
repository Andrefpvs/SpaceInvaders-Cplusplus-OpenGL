#include "Explosion.h"
#define MAX_PTCS	200


Explosion::Explosion(float x, float y){
	 for ( int i = 0; i < MAX_PTCS; i++)
        _activePtc.push_back( new Particle(x, y) );
	 exploding = true;
}

void Explosion::update(){

	std::list<Particle*>::iterator it = _activePtc.begin();
	if(_activePtc.empty())
		exploding = false;
	else
	while ( it != _activePtc.end() ) {
        (*it)->update();
		if ( (*it)->alive() )
			it++;
		else
		{
			_deadPtc.push_back( *it);
			it = _activePtc.erase( it); //após passar para a lista "dead particles", pode apagar com segurança
		}
    }
	
}

void Explosion::draw(){

    std::list<Particle*>::const_iterator it = _activePtc.begin();
    while ( it != _activePtc.end() ) {
        (*it)->draw();
        it++;
    }
}