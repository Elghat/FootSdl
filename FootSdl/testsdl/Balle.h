#pragma once
#include "ObjetDeplacable.h"
class Balle : public ObjetDeplacable
{
public:
	void MoveTo(float x,float y);
	SDL_Rect getRect();
	SDL_Texture* getSprite();
};
