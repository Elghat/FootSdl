#pragma once
#include "ObjetDeplacable.h"
#include "Joueur.h"
class Balle : public ObjetDeplacable
{
private:
	int directionAngle;
	bool inMouvement;
public:
	Balle(SDL_Renderer* R);
	void MoveTo(float nextX,float nextY);
	virtual SDL_Rect getRect();
	virtual SDL_Texture* getSprite();
	bool getInMouvement();
	void rebond();
	void Forward();
	void CollisionWall();
	void CollisionJoueur(Joueur player);
};

