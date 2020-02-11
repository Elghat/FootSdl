#include "Balle.h"

void Balle::MoveTo(float nextX, float nextY) {
	x = nextX;
	y = nextY;
	zoneOntheScreen.x = x;
	zoneOntheScreen.y = y;
}

void Balle::Forward() {
	float tempX = cos(directionAngle*PI/180);
	float tempY = sin(directionAngle*PI/180);
	MoveTo(x + tempX, y + tempY);
}

SDL_Rect Balle::getRect() {
	return zoneOntheScreen;
}

SDL_Texture* Balle::getSprite() {
	return sprite;
}

bool Balle::getInMouvement() {
	return inMouvement;
}

Balle::Balle(SDL_Renderer* R) {
	renderer = R;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	zoneOntheScreen.y = y;
	zoneOntheScreen.x = x;
	zoneOntheScreen.h = 40;
	zoneOntheScreen.w = 40;
	directionAngle = 0;
	inMouvement = false;
	sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./assets/Balle.png"));
}

void Balle::rebond() {
	directionAngle += 170 + rand()%20;
	directionAngle %= 360;
}

void Balle::CollisionWall() {
	if (zoneOntheScreen.x < 0 && zoneOntheScreen.x + zoneOntheScreen.w < WIDTH) {
		rebond();
	}
	else if (zoneOntheScreen.y < 0 && zoneOntheScreen.y + zoneOntheScreen.h < HEIGHT) {
		rebond();
	}
	else if(zoneOntheScreen.x + zoneOntheScreen.w > WIDTH){
		rebond();
	}
	else if (zoneOntheScreen.y + zoneOntheScreen.h > HEIGHT) {
		rebond();
	}
	
}

void Balle::CollisionJoueur(Joueur player) {
	SDL_Rect playerRect = player.getRect();
	int lieuCollision = -1;
	int numbers = 0;
	if (playerRect.x <= zoneOntheScreen.x && playerRect.w + playerRect.x > zoneOntheScreen.x) {
		lieuCollision = 0;
		numbers++;
	}
	else if (playerRect.x > zoneOntheScreen.x&& playerRect.x < zoneOntheScreen.w + zoneOntheScreen.x) {
		if (playerRect.w + playerRect.x <= zoneOntheScreen.w + zoneOntheScreen.x) {
			numbers++;
			std::cout << "OKBOOMER";
			lieuCollision = 1;
			// C
		}
		else if (playerRect.w + playerRect.x > zoneOntheScreen.w + zoneOntheScreen.x) {
			numbers++;
			lieuCollision = 2;
			// E
		}
	}
	if (playerRect.y <= zoneOntheScreen.y && playerRect.h + playerRect.y > zoneOntheScreen.y) {
		numbers++;
		lieuCollision += 0;
		// S
	}
	else if (playerRect.y > zoneOntheScreen.y&& playerRect.y < zoneOntheScreen.h + zoneOntheScreen.y) {
		if (playerRect.h + playerRect.y <= zoneOntheScreen.h + zoneOntheScreen.y) {
			numbers++;
			lieuCollision += 3;
			// C
		}
		else if (playerRect.h + playerRect.y > zoneOntheScreen.h + zoneOntheScreen.y) {
			numbers++;
			lieuCollision += 6;
			// N		
		}
	}
	if (numbers == 2) {
		if (!inMouvement) {
			std::cout << lieuCollision;
		}
		else {
			rebond();
		}
	}
}

