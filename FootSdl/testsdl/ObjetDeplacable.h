#pragma once
#include "Objet.h"
class ObjetDeplacable : public Objet
{
protected:
	float x;
	float y;
public:
	virtual void MoveTo(float x,float y) = 0;
	//virtual void InitSprite(std::string Path) = 0;

};

