#pragma once
#include "Balle.h"
class Goal:public Objet
{

public:
	virtual SDL_Rect getRect();
	virtual SDL_Texture* getSprite();
	int OnColision(Balle theBalle);
	bool InGoal(Balle theBalle);
	Goal(SDL_Renderer* r);
	Goal(SDL_Renderer* r,int Camp);
	void ShowGoalOnRendere();
};

