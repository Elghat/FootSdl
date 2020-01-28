#pragma once
#include "ObjetDeplacable.h"
class Balle : public ObjetDeplacable
{
public:
	Balle(SDL_Renderer* R);
	void MoveTo(float nextX,float nextY);
	virtual SDL_Rect getRect();
	virtual SDL_Texture* getSprite();
};

