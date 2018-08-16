#ifndef __SpaceInvadersO__GlobalManager__
#define __SpaceInvadersO__GlobalManager__
#include <list>
#include "Alien.h"
#include "AlienType1.h"
#include "AlienType2.h"
#include "AlienType3.h"
#include "AlienBoss.h"
#include "Ship.h"
#include "ShipType1.h"
#include "Barrier.h"
#include "Player.h"
#include "Scene.h"
#include "Shot.h"
#include "Camera.h"
#include "CameraOriginal.h"
#include "Camera1.h"
#include "Camera2.h"
#include "HUD.h"
#include "Light.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "AmbientLight.h"
#include "Explosion.h"
#include "Particle.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class GlobalManager {
    std::vector<Barrier*> _barriers;
    std::vector<Alien*> _aliens;
	std::vector<Shot*> _shots;
	std::list<Explosion*> _explosions;
	Player player;
    ShipType1* ship;
    Camera* cam;
	Camera* hud_cam;
	SpotLight* spot;
	HUD* hud;
    DirectionalLight* light;
	int alienTimerCounter;
	int shipDyingCounter;
	bool wirespheres;
	bool gameover;
	bool gamewon;
	    
    
public:
    Scene* bar;
	GlobalManager() : alienTimerCounter(0), shipDyingCounter(0), wirespheres(false), gameover(false), gamewon(false) {}
    void createGameObjects();
    void reshape(GLsizei w, GLsizei h);
    void displayBarriers();
    void displayAliens();
    void displayShip();
    void displayBar();
	void displayExplosions();
    void displays();
    void processSpecialKeys(int key, int _xPos, int _yPos);
    void setCamera();
    void myKeyboardFunction(unsigned char key, int x, int y);
	void processTimedBehaviour();
    void processMoving();
    void displayShot(Shot* shot);
	void processShot();
    void displayAlienShot(AlienShot* shot);
	bool hasCollision(float x1, float y1, double r1, float x2, float y2, double r2);
	void processCollisions();
	void displayHUD();
	void checkGameOver();
	void checkGameWon();
	bool alienCanShoot(Alien* alien);
	bool columnIsDead(int column);
};
#endif