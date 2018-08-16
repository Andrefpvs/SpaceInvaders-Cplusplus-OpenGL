#define PROPORTION 100.0f
#define TIMER 15.0f
#define MULTFACTOR_ALIENS 18
#define MULFACTOR_BARRIER 30
#define CONSTDESLOC_ALIEN 75
#define CONSTDESLOC_BARRIER 55
#define SHIPXPOS 0
#define SHIPZPOS 70
#define NUM_BARRIERS 4
#define WINDOW_LIMIT 90
#define BOTTOM_LIMIT 40
#define SPACE_BARRIERS 74
#define TOP_LIMIT 90
#define SHIP_RESPAWN 57
#include <vector>
#include <iostream>
#include <cstdio>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "GlobalManager.h"
float mat_speculars[] = { 1.0, 1.0, 1.0, 1.0 };
float spotDir[] = { 0,100,0};
int global_width, global_height;
extern float xLocation;
int camNum = 1;
extern int counterX;
bool isOnOne;
bool first;
int counter;

void GlobalManager::createGameObjects(){
	printf("\nGame loaded.");
	player = Player();
	counter = 0;
	hud_cam = new CameraOriginal(1);


	//Criacao dos aliens
	//Aliens sao dispostos numa matriz 5linhas*10colunas (**)
	//Primeira posicao = (1, 1) canto superior esquerdo
	//(**)Sao os aliens que guardam a informacao sobre a sua linha e coluna (nao existe matriz de estado de jogo)
    for (GLsizei i  = 0; i < 6; i++){
        Barrier *provisoria = new Barrier(i * MULFACTOR_BARRIER - SPACE_BARRIERS , -CONSTDESLOC_BARRIER);
        _barriers.push_back(provisoria);
    }
    for (GLsizei i  = 0; i < 10; i++){
        for (GLsizei j = 4; j > 2; j--){
            Alien* provisorio4 = new AlienType1(i * MULTFACTOR_ALIENS - CONSTDESLOC_ALIEN, j * MULTFACTOR_ALIENS - 5, 5-j, i+1);
            _aliens.push_back(provisorio4);
        }
        for (GLsizei j = 2; j > 0; j--){
            Alien* provisorio2 = new AlienType2(i * MULTFACTOR_ALIENS  - CONSTDESLOC_ALIEN, j * MULTFACTOR_ALIENS - 5, 5-j, i+1);
            _aliens.push_back(provisorio2);
        }
        Alien* provisorio = new AlienType3(i * MULTFACTOR_ALIENS  - CONSTDESLOC_ALIEN, 0 * MULTFACTOR_ALIENS - 5, 5, i+1);
        _aliens.push_back(provisorio);
    }
    
    //Alien* provisorio5 = new AlienBoss(0, 5 * MULTFACTOR_ALIENS  ); (RETIREI O BOSS)
    //_aliens.push_back(provisorio5);

    ship = new ShipType1(SHIPXPOS, -SHIPZPOS);
    cam = new CameraOriginal(1);
    bar = new Scene(0,0);
    displayBar();
    float direction [] = {0,0,-110,0};
    light = new DirectionalLight(0);
    light->applyLight(direction);
    spot = new SpotLight(1);
    first = true;
    glFlush();

}
void GlobalManager::reshape(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);
   	global_width = w;
	global_height = h;
    if(global_width/global_height >= 1){
        glOrtho(-PROPORTION*global_width/global_height, PROPORTION*global_width/global_height, -PROPORTION, PROPORTION, -PROPORTION, PROPORTION);
    }
    else if(global_height/global_width >= 1){
        glOrtho(-PROPORTION, PROPORTION, -PROPORTION*global_height/global_width, PROPORTION*global_height/global_width, -PROPORTION, PROPORTION);
    }
}

void GlobalManager::displayBarriers(){
    for (GLsizei i  = 0; i < _barriers.size(); i++){
		if (_barriers[i]->getLife() > 0)
        _barriers[i]->drawBarrier(wirespheres);
    }
}

void GlobalManager::displayAliens(){
    for (GLsizei i  = 0; i < _aliens.size(); i++){
		if(!_aliens[i]->isDead())
        _aliens[i]->drawAlien(wirespheres);
    }
}

void GlobalManager::displayShip(){
	if(player.getLives() != 0){
		if(ship->getDying() && shipDyingCounter < SHIP_RESPAWN){
			shipDyingCounter++;
			return;
		}
		else{
			ship->drawShip(wirespheres);
			ship->setDying(false);
			shipDyingCounter = 0;
		}
	}
	else ship->setDying(false);
}

void GlobalManager::displayBar(){
    bar->drawScene();
}

void GlobalManager::displayShot(Shot* shot){
    shot->drawShot(wirespheres);
}
void GlobalManager::displayAlienShot(AlienShot* shot){
    shot->drawShot(wirespheres);
}

void GlobalManager::displayHUD(){
	hud->drawHUD(player.getLives(), player.getScore(), gameover, gamewon);
}

void GlobalManager::displayExplosions(){

	std::list<Explosion*>::iterator it = _explosions.begin();
	 
	while(it != _explosions.end()){
		if((*it)->isExploding()){
			(*it)->update();
			(*it)->draw();
			it++;
		 }else{
			it = _explosions.erase(it);
		 }
	 }
 }

void GlobalManager::displays(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable( GL_DEPTH_TEST) ;
    glDepthMask(GL_TRUE);
    glEnable(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable( GL_TEXTURE_2D);

    float direction [] = {0,0,-110,0};
    light = new DirectionalLight(0);
    light->applyLight(direction);
    glPushMatrix();
	glViewport(0, 0, global_width, global_height);
	hud_cam->applyProjection(global_width, global_height);
	displayHUD();
	glPopMatrix();
	setCamera();		
	displayExplosions();
    displayBar();
    displayAliens();
    displayBarriers();
    displayShip();
	

    glFlush();
}
void GlobalManager::processSpecialKeys(int key, int _xPos, int _yPos){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glLoadIdentity();
    glPushMatrix();
	glViewport(0, 0, global_width, global_height);
	hud_cam->applyProjection(global_width, global_height);
	displayHUD();
	glPopMatrix();
	setCamera();
	displayExplosions();		
    displayBar();
    displayAliens();
    displayBarriers();
	

    switch (key) {
        case GLUT_KEY_LEFT :
			if(!gameover && !gamewon && !ship->getDying()){
				ship->moveShipLeft(wirespheres);
				glFlush();
			}
            
            break;
        case GLUT_KEY_RIGHT :
			if(!gameover && !gamewon && !ship->getDying()){
				ship->moveShipRight(wirespheres);
				glFlush();
			}
            break;
        
    }
    

}

void GlobalManager::myKeyboardFunction(unsigned char key, int x, int y){
           // float light_position[] = { xLocation,-70,5, 1.0 };

    switch(key){
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           // glLoadIdentity();

		case '1' :
            glEnable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            cam = new CameraOriginal(1);
            isOnOne = true;
			break;
		case '2' :
            cam = new Camera1(2);
           // spot = new SpotLight(1);
           // spot->applyLight(mat_speculars, light_position, spotDir);
            first = false;
            isOnOne = false;
			break;
		case '3' :
            cam = new Camera2(3);
           // spot = new SpotLight(1);
           // spot->applyLight(mat_speculars, light_position, spotDir);
            first = false;
            isOnOne = false;
			break;
        case ' ' :
			if(ship->getDying()) break;
            if (_shots.size() == 0){
			Shot *newshot = new Shot(xLocation, -SHIPZPOS + 4, true); 
			_shots.push_back(newshot);
            }
            else {
                if (_shots[0]->isFired())
                    break;
                if (!_shots[0]->isFired()){
                    _shots.pop_back();
                    Shot *newshot = new Shot(xLocation, -SHIPZPOS + 4, true); 
                    _shots.push_back(newshot);
                    break;
                }
            }
            break;
        case '4':
            if(isOnOne || first)
                break;
            else{
                glDisable(GL_LIGHT0);
                glEnable(GL_LIGHT1);
                break;
            }
            break;
        case '5':

            glDisable(GL_LIGHT1);
            glEnable(GL_LIGHT0);
            break;

		case '6':

            wirespheres = !wirespheres;
            break;

		case '9':
			//CHEAT (9 key = +1 life, +100 points)
			player.addScore(100);
			player.setLives(player.getLives()+1);
			break;
	}

    glFlush();

}

void GlobalManager::setCamera(){
    cam->applyProjection(global_width, global_height);
}

bool GlobalManager::alienCanShoot(Alien* alien){ //retorna 'true' se não ha aliens por baixo desse alien
	if (alien->isDead()) return false;

	bool canShoot = true;
	int column = alien->getColumn();
	int row = alien->getRow();

	for (GLsizei i  = 0; i < _aliens.size(); i++){
		if(_aliens[i]->getColumn() == column 
		   && _aliens[i]->getRow() > row
		   && !_aliens[i]->isDead())
		{
			canShoot = false;
		}
		
	}

	return canShoot;
}

bool GlobalManager::columnIsDead(int column){ //retorna 'true' se a coluna #column foi eliminada
	bool columnDead = true;

	for (GLsizei i  = 0; i < _aliens.size(); i++){
		if(_aliens[i]->getColumn() == column 
		   && !_aliens[i]->isDead())
		{
			columnDead = false;
		}
		
	}

	return columnDead;
}

void GlobalManager::processMoving(){
	if(gameover||gamewon) return;

	if (alienTimerCounter < 2){
		alienTimerCounter++;
		return;
	}

	else alienTimerCounter = 0;

	int rightLimit = WINDOW_LIMIT;
	int leftLimit = -WINDOW_LIMIT;

	for(int i = 1; i < 10; i++){
		if(columnIsDead(i)){
			leftLimit -= MULTFACTOR_ALIENS;
		}
		else break;
	}

	for(int i = 10; i > 1; i--){
		if(columnIsDead(i)){
			rightLimit += MULTFACTOR_ALIENS;
		}
		else break;
	}
    
    int x1 = _aliens[49]->getX();
    int x2 = _aliens[4]->getX();
    counterX = _aliens[0]->getCounterX();
    
    if(counterX % 2 == 0){
        if (x1 > rightLimit){
            for (int i = 0; i < _aliens.size(); i++){
                
                    _aliens[i]->getDown();
                    _aliens[i]->backToRightLimit();
                
            }
            return;
        }
        else{
            for (GLsizei i  = 0; i < _aliens.size(); i++){
                _aliens[i]->moveRight();
            }
            return;
        }
    }
    if(counterX % 2 != 0){
        if (x2 < leftLimit){
            for (int i = 0; i < _aliens.size(); i++){
                
                    _aliens[i]->getDown();
                    _aliens[i]->backToLeftLimit();
                
                
            }
            return;
        }
        else {
            for (GLsizei i  = 0; i < _aliens.size(); i++){
                _aliens[i]->moveLeft();
            }
            return;
        }
    }

}

void GlobalManager::processShot(){
	if(gameover||gamewon) return;

	//disparos da nave
   for (GLsizei i  = 0; i < _shots.size(); i++){
		if ( _shots[i]->isFired() == true ){
			_shots[i]->moveShotUp();
			displayShot(_shots[i]);
		}
	}


   //disparos dos aliens
	srand(xLocation + _aliens[rand()%_aliens.size()]->getX()); //seed fantasticamente aleatoria :)

	for (GLsizei i  = 0; i < _aliens.size(); i++){
		if(alienCanShoot(_aliens[i])
		   && rand()%40 == 0)
		{
		   _aliens[i]->getShot()->setFired(true);
		}


		if ( _aliens[i]->getShot()->isFired() == true){
			 _aliens[i]->getShot()->moveShotDown();
			displayAlienShot(_aliens[i]->getShot());
		}
		else {
			_aliens[i]->getShot()->setX(_aliens[i]->getX());
			_aliens[i]->getShot()->setY(_aliens[i]->getY());
		}
	}
 
}

bool GlobalManager::hasCollision(float x1, float y1, double r1, float x2, float y2, double r2){
	float dist2 = ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	double rad2 = ((r1+r2)*(r1+r2));
	if(dist2<=rad2){
		return true;
	}
	else return false;
}

void GlobalManager::processCollisions(){
    //Teste tiro jogador
	for (GLsizei j  = 0; j < _shots.size(); j++){
		if ( _shots[j]->isFired() == true ){

			for (GLsizei i  = 0; i < _aliens.size(); i++){
				if(_shots[j]->isFired() == true && !_aliens[i]->isDead()){

					if(hasCollision(_aliens[i]->getX(), _aliens[i]->getY(), _aliens[i]->getRadius(),
								_shots[j]->getX(), _shots[j]->getY(), _shots[j]->getRadius())){
						
						player.addScore(_aliens[i]->awardPoints());
						_aliens[i]->setDying(true);
						_aliens[i]->setDead(true);
						_shots[j]->setFired(false);
						_explosions.push_back(new Explosion(_aliens[i]->getX(), _aliens[i]->getY()));
										
					}
				}
		
			}

			for (GLsizei i  = 0; i < _barriers.size(); i++){
				if(_barriers[i]->getLife() > 0){
					if(hasCollision(_barriers[i]->getX(), _barriers[i]->getY(), _barriers[i]->getRadius(),
									_shots[j]->getX(), _shots[j]->getY(), _shots[j]->getRadius())){
				
							_barriers[i]->setLife(_barriers[i]->getLife()-10);
							_shots[j]->setFired(false);
					}
				}
			}
		}
	}
	
	//Teste tiros alien
	for (GLsizei j  = 0; j < _aliens.size(); j++){
		if ( _aliens[j]->getShot()->isFired() == true ){

			for (GLsizei i  = 0; i < _barriers.size(); i++){
				if(_barriers[i]->getLife() > 0){
					if(hasCollision(_barriers[i]->getX(), _barriers[i]->getY(), _barriers[i]->getRadius(),
									_aliens[j]->getShot()->getX(), _aliens[j]->getShot()->getY(), _aliens[j]->getShot()->getRadius())){
				
							_barriers[i]->setLife(_barriers[i]->getLife()-10);
							_aliens[j]->getShot()->setFired(false);
					}
				}
			}

			if ( _aliens[j]->getShot()->isFired() == true && !ship->getDying()){
				if(hasCollision(xLocation, ship->getY(), ship->getRadius(),
								_aliens[j]->getShot()->getX(), _aliens[j]->getShot()->getY(), _aliens[j]->getShot()->getRadius())){
					
					player.setLives(player.getLives()-1);
					ship->setDying(true);
					_aliens[j]->getShot()->setFired(false);
					_explosions.push_back(new Explosion(_aliens[j]->getShot()->getX(), _aliens[j]->getShot()->getY()));
					_explosions.push_back(new Explosion(xLocation, ship->getY()));
				}
			}

		}
	}

	//Teste aliens
		for (GLsizei j  = 0; j < _aliens.size(); j++){
			if (!_aliens[j]->isDead()){

				for (GLsizei i  = 0; i < _barriers.size(); i++){
					if(_barriers[i]->getLife() > 0){
						if(hasCollision(_barriers[i]->getX(), _barriers[i]->getY(), _barriers[i]->getRadius(),
										_aliens[j]->getX(), _aliens[j]->getY(), _aliens[j]->getRadius())){
				
								_barriers[i]->setLife(0);								
						}
					}
				}

				if ( _aliens[j]->getShot()->isFired() == true ){
					if(hasCollision(xLocation, ship->getY(), ship->getRadius(),
									_aliens[j]->getX(), _aliens[j]->getY(), _aliens[j]->getRadius())){

						if(player.getLives() != 0)
							_explosions.push_back(new Explosion(xLocation, ship->getY()));
						player.setLives(0);
						
					}
				}

			}
	}
}

void GlobalManager::checkGameOver(){
	if(player.getLives() <= 0) {
		gameover = true;
	}
	else gameover = false;	
}

void GlobalManager::checkGameWon(){
	gamewon = true;
	for (GLsizei j  = 0; j < _aliens.size(); j++){
		if (!_aliens[j]->isDead()){
			gamewon = false;
			break;
		}
	}
}

void GlobalManager::processTimedBehaviour(){
	checkGameOver();
	checkGameWon();
	processCollisions();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //  glLoadIdentity();
	glPushMatrix();
	glViewport(0, 0, global_width, global_height);
	hud_cam->applyProjection(global_width, global_height);
	displayHUD();
	glPopMatrix();		
	setCamera();
    displayBar();
	processShot();
	displayBarriers();
	displayExplosions();
    displayAliens();
    displayShip();
	
    processMoving();
    counter++;
	


    glFlush();
    
}
