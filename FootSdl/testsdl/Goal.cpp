#include "Goal.h"

SDL_Rect Goal::getRect() {
	return zoneOntheScreen;
}

SDL_Texture* Goal::getSprite() {
	return sprite;
}

int Goal::OnColision(Balle theB) {
	int inCollisionX = -1;
	int inCollisionY = -1;
	SDL_Rect theBCollisionRect = theB.getRect();
	if (theBCollisionRect.x <= zoneOntheScreen.x && theBCollisionRect.w > zoneOntheScreen.x) {
		inCollisionX = 0;
		// E
	}
	else if (theBCollisionRect.x > zoneOntheScreen.x && theBCollisionRect.x < zoneOntheScreen.w) {
		if (theBCollisionRect.w <= zoneOntheScreen.w) {
			inCollisionX = 1;
			// C
		}
		else if (theBCollisionRect.w > zoneOntheScreen.w) {
			inCollisionX = 2;
			// W
		}
	}
	if (theBCollisionRect.y <= zoneOntheScreen.y && theBCollisionRect.h > zoneOntheScreen.y) {
		inCollisionY = 0;
		// N
	}
	else if (theBCollisionRect.y > zoneOntheScreen.y && theBCollisionRect.y < zoneOntheScreen.h) {
		if (theBCollisionRect.h <= zoneOntheScreen.h) {
			inCollisionY = 3;
			// C
		}
		else if (theBCollisionRect.h > zoneOntheScreen.h) {
			inCollisionY = 6;
			// S
		}
	}
	if (inCollisionX != -1 && inCollisionY != -1) {
		return inCollisionX + inCollisionY;
	}
	return -1;


}

bool Goal::InGoal(Balle theB) {
	bool Goal = false;
	int isIn = OnColision(theB);
	if (isIn == 4) {
		Goal = true;
	}
	return Goal;
}

Goal::Goal(SDL_Renderer *R):Goal(R,0){}

Goal::Goal(SDL_Renderer *R,int Camp) {
	renderer = R;
	this->zoneOntheScreen = SDL_Rect();
	this->zoneOntheScreen.h = HEIGHT/3;
	this->zoneOntheScreen.w = WIDTH/12;
	this->zoneOntheScreen.y = (HEIGHT/2)- zoneOntheScreen.h/2;
	if (Camp == 0) {
		sprite = SDL_CreateTextureFromSurface(renderer,IMG_Load("./assets/GoalGauche.png"));
		zoneOntheScreen.x = 0;
	}
	else {
		sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./assets/GoalDroite.png"));
		zoneOntheScreen.x = WIDTH- zoneOntheScreen.w;
	}
}

void Goal::ShowGoalOnRendere() {
	SDL_RenderCopy(renderer, sprite, NULL,&zoneOntheScreen);
}

