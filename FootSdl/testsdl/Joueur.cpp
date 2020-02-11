#include "Joueur.h"


SDL_Rect Joueur::getRect() {
	return this->zoneOntheScreen;
}

SDL_Texture* Joueur::getSprite() {
	return this->sprite;
}

void Joueur::MoveTo(float x, float y) {
	this->x = x;
	this->y = y;
	zoneOntheScreen.x = x;
	zoneOntheScreen.y = y;
}

void Joueur::WaitInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			MoveTo(x - 10, y);
			break;
		case SDLK_RIGHT:
			MoveTo(x + 10, y);
			break;
		case SDLK_UP:
			MoveTo(x, y - 10);
			break;
		case SDLK_DOWN:
			MoveTo(x, y + 10);
			break;
		default:
			break;
		}
		break;
	}
}

Joueur::Joueur(SDL_Renderer* R,int identifiant) {
	this->renderer = R;
	this->id = identifiant;
	x = ((id*2)*WIDTH + WIDTH) / 4;
	y = HEIGHT / 2;
	zoneOntheScreen.y = y;
	zoneOntheScreen.x = x;
	zoneOntheScreen.h = 80;
	zoneOntheScreen.w = 80;
	sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("./assets/Balle.png"));
}