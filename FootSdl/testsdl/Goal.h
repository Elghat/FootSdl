#pragma once
#include "Balle.h"
class Goal:public Objet
{
private:
	int OnColisionPrivate(Balle theBalle);
public:
	virtual SDL_Rect getRect();
	virtual SDL_Texture* getSprite();
	bool OnColision(Balle theBalle);
	Goal(SDL_Renderer* r);
	Goal(SDL_Renderer* r,int Camp);
	void ShowGoalOnRendere();
};

