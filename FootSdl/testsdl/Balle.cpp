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
	if (playerRect.x < zoneOntheScreen.x && playerRect.x + playerRect.w < zoneOntheScreen.x+zoneOntheScreen.w && playerRect.x + playerRect.w > zoneOntheScreen.x) {
		numbers++;
		lieuCollision = 0;
	}
	else {
		if (playerRect.x >= zoneOntheScreen.x + 2*zoneOntheScreen.w/4 && playerRect.x < zoneOntheScreen.w +zoneOntheScreen.x) {
			numbers++;
			lieuCollision = 2;
		}
		else if (zoneOntheScreen.x + zoneOntheScreen.w < playerRect.x + playerRect.w && playerRect.x < zoneOntheScreen.x + zoneOntheScreen.w) {
			numbers++;
			lieuCollision = 1;
		}
	}
	if (playerRect.y < zoneOntheScreen.y && playerRect.y + playerRect.h < zoneOntheScreen.y + zoneOntheScreen.h && playerRect.y + playerRect.h > zoneOntheScreen.y) {
		numbers++;
		lieuCollision += 0;
	}
	else {
		if (playerRect.y >= zoneOntheScreen.y + 2 * zoneOntheScreen.h / 4 && playerRect.y < zoneOntheScreen.h + zoneOntheScreen.y) {
			numbers++;
			lieuCollision += 6;
		}
		else if (zoneOntheScreen.y + zoneOntheScreen.h < playerRect.y + playerRect.h && playerRect.y < zoneOntheScreen.y + zoneOntheScreen.h) {
			numbers++;
			lieuCollision += 3;
		}
	}


	if (numbers == 2) {
		if (!inMouvement) {
			switch (lieuCollision) {
			case 0:
				directionAngle = 315;
				break;
			case 1:
				directionAngle = 270;
				break;
			case 2:
				directionAngle = 225;
				break;
			case 3:
				directionAngle = 180;
				break;
			case 4:
				directionAngle = 0;
				break;
			case 5:
				directionAngle = 0;
				break;
			case 6:
				directionAngle = 45;
				break;
			case 7:
				directionAngle = 90;
				break;
			case 8:
				directionAngle = 135;
				break;
			default:
				rebond();
				break;
			}
			inMouvement = true;
		}
		else {
			rebond();
		}
	}
}

