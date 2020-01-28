#include "Balle.h"

void Balle::MoveTo(float nextX, float nextY) {
	x = nextX;
	y = nextY;
	zoneOntheScreen.x = x;
	zoneOntheScreen.y = y;
}

SDL_Rect Balle::getRect() {
	return zoneOntheScreen;
}

SDL_Texture* Balle::getSprite() {
	return sprite;
}

Balle::Balle(SDL_Renderer* R) {
	renderer = R;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	zoneOntheScreen.y = y;
	zoneOntheScreen.x = x;
	zoneOntheScreen.h = 40;
	zoneOntheScreen.w = 40;
	sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./assets/Balle.png"));
}
