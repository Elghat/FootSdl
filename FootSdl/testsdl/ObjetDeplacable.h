#pragma once
#include "Header.h"
class ObjetDeplacable
{
protected:
	float x;
	float y;
	SDL_Surface sprite;
	SDL_Rect zoneOntheScreen;
public:
	virtual void MoveTo(float x,float y) = 0;
	//virtual void InitSprite(std::string Path) = 0;

};

