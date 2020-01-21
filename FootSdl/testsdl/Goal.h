#pragma once
#include "Balle.h"
class Goal
{
private:
	SDL_Rect zoneOnTheScreen;
	SDL_Texture* sprite;
	SDL_Renderer* renderer;
public:
	bool OnColision(Balle theBalle);
	bool InGoal(Balle theBalle);
	Goal(SDL_Renderer* r);
	Goal(SDL_Renderer* r,int Camp);
	void ShowGoalOnRendere();
};

