#include "Goal.h"

Goal::Goal(SDL_Renderer *R):Goal(R,0){}

Goal::Goal(SDL_Renderer *R,int Camp) {
	renderer = R;
	zoneOnTheScreen = SDL_Rect();
	zoneOnTheScreen.h = HEIGHT/3;
	zoneOnTheScreen.w = WIDTH/12;
	zoneOnTheScreen.y = (HEIGHT/2)-zoneOnTheScreen.h/2;
	if (Camp == 0) {
		sprite = SDL_CreateTextureFromSurface(renderer,IMG_Load("./assets/GoalGauche.png"));
		zoneOnTheScreen.x = 0;
	}
	else {
		sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./assets/GoalDroite.png"));
		zoneOnTheScreen.x = WIDTH-zoneOnTheScreen.w;
	}
}

void Goal::ShowGoalOnRendere() {
	SDL_RenderCopy(renderer, sprite, NULL,&zoneOnTheScreen);
}