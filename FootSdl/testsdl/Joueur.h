#pragma once
#include "ObjetDeplacable.h"
class Joueur :public ObjetDeplacable
{
private:
public:
	Joueur(SDL_Renderer* R);
	void WaitInput();
	void ShootBall();
	void TakeBall();
	void MoveTo(float x, float y);
	SDL_Rect getRect();
	SDL_Texture* getSprite();


};

