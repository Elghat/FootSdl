#pragma once
#include "Header.h"
class Objet
{
protected:
	SDL_Texture* sprite;
	SDL_Rect zoneOntheScreen;
public:
	SDL_Rect getRect();
	SDL_Texture* getSprite();

};

