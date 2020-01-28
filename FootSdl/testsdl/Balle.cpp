#include "Balle.h"

void Balle::MoveTo(float x, float y) {
	
}

SDL_Rect Balle::getRect() {
	return zoneOntheScreen;
}

SDL_Texture* Balle::getSprite() {
	return sprite;
}