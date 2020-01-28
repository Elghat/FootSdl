#include "Objet.h"

void Objet::ShowInRenderer() {
	SDL_RenderCopy(renderer, sprite, NULL, &zoneOntheScreen);
}