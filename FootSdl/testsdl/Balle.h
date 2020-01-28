#pragma once
#include "ObjetDeplacable.h"
class Balle : public ObjetDeplacable
{
public:
	void MoveTo(float x,float y);
	virtual SDL_Rect getRect();
	virtual SDL_Texture* getSprite();
};

