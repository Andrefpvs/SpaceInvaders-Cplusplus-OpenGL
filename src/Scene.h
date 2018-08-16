#ifndef __SpaceInvadersO__Scene__
#define __SpaceInvadersO__Scene__

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Light.h"


class Scene {
    float _xPos;
	float _yPos;

    
public:
	Scene(float x_pos, float y_pos) : _xPos(x_pos), _yPos(y_pos) {
    //_texture2 = LoadTexture("x.bmp");
    }
	void drawScene();
    
	float getX();
    
	float getY();
    const bool LoadTexture( const std::string & textureFilename);
    
};
#endif 