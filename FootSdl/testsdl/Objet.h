#pragma once
#include "Header.h"
class Objet
{
protected:
	SDL_Texture* sprite;
	SDL_Rect zoneOntheScreen;
	SDL_Renderer* renderer;
public:
	virtual SDL_Rect getRect() = 0;
	virtual SDL_Texture* getSprite() = 0;

};

