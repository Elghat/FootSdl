#include "Goal.h"

SDL_Rect Goal::getRect() {
	return zoneOntheScreen;
}

SDL_Texture* Goal::getSprite() {
	return sprite;
}

int Goal::OnColisionPrivate(Balle theB) {
	int inCollisionX = -1;
	int inCollisionY = -1;
	SDL_Rect theBCollisionRect = theB.getRect();
	// collision Goal
	if (theBCollisionRect.x <= zoneOntheScreen.x && theBCollisionRect.w+theBCollisionRect.x > zoneOntheScreen.x) {
		inCollisionX = 0;
		// W
	}
	else if (theBCollisionRect.x > zoneOntheScreen.x && theBCollisionRect.x < zoneOntheScreen.w+zoneOntheScreen.x) {
		if (theBCollisionRect.w + theBCollisionRect.x <= zoneOntheScreen.w + zoneOntheScreen.x) {
			inCollisionX = 1;
			// C
		}
		else if (theBCollisionRect.w+theBCollisionRect.x > zoneOntheScreen.w + zoneOntheScreen.x) {
			inCollisionX = 2;
			// E
		}
	}
	if (theBCollisionRect.y <= zoneOntheScreen.y && theBCollisionRect.h + theBCollisionRect.y > zoneOntheScreen.y) {
		inCollisionY = 0;
		// N
	}
	else if (theBCollisionRect.y > zoneOntheScreen.y && theBCollisionRect.y < zoneOntheScreen.h + zoneOntheScreen.y) {
		if (theBCollisionRect.h+theBCollisionRect.y <= zoneOntheScreen.h + zoneOntheScreen.y) {
			inCollisionY = 3;
			// C
		}
		else if (theBCollisionRect.h+theBCollisionRect.y > zoneOntheScreen.h+zoneOntheScreen.y) {
			inCollisionY = 6;
			// S
		}
	}
	//std::cout <<  "colli" << inCollisionX << " et " << inCollisionY << "\n";
	if (inCollisionX != -1 && inCollisionY != -1) {
		return inCollisionX + inCollisionY;
	}
	return -1;


}

bool Goal::OnColision(Balle theBalle) {
	int collision = OnColisionPrivate(theBalle);
	bool inGoal = false;
	if (collision >= 0 && collision < 3 || collision >5 && collision <= 9) {
		theBalle.rebond();
	}
	else if (collision == 3 && zoneOntheScreen.x == 0 || collision == 5 && zoneOntheScreen.x != 0) {
		theBalle.rebond();
	}
	else if (collision == 4) {
		inGoal = true;
	}
	return inGoal;
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

