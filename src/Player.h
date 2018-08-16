#ifndef __SpaceInvadersO__Player__
#define __SpaceInvadersO__Player__


class Player {
	int _score;
	int _lives;
public:    
	Player() {_score=0; _lives=3;} 
    
	int getScore();    
	int getLives();
	void setScore(int score);									
	void setLives(int lives);
    void addScore(int score);

};

#endif 
