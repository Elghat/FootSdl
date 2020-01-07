//#include "Header.h"
#include "Game.h"
using namespace std;


int main(int argc, char *argv[])
{

	//EN C

	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	//{
	//	cout << "problem" << endl;
	//}
	//else
	//{
	//	SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	//	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	//	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//	SDL_RenderClear(renderer);
	//	SDL_RenderPresent(renderer);
	//	SDL_Delay(3000);
	//}

	//EN C++
	Game *game = NULL;
	game = new Game();
	game->Init("Titre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	game->addobject("player", "assets/player1.png");
	while (game->Running())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
	game->Clear();
	return 0;
}