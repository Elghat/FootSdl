#include "Goal.h"

Goal::Goal(SDL_Renderer *R):Goal(R,0){}

Goal::Goal(SDL_Renderer *R,int Camp) {
	renderer = R;
	zoneOnTheScreen = SDL_Rect();
	zoneOnTheScreen.h = 50;
	zoneOnTheScreen.w = 50;
	zoneOnTheScreen.y = 200;
	if (Camp == 0) {
		sprite = SDL_CreateTextureFromSurface(renderer,IMG_Load("./asset/GoalGauche.png"));
		zoneOnTheScreen.x = 0;
	}
	else {
		sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./asset/GoalDroite.png"));
		zoneOnTheScreen.x = 1000;
	}
}

void Goal::ShowGoalOnRendere(SDL_Renderer* r) {
	SDL_RenderCopy(renderer, sprite, NULL,&zoneOnTheScreen);
}