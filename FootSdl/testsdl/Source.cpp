#include "Goal.h"
using namespace std;

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	vector<Goal> listeGoal;
	bool endGame = false;

	SDL_Window* window = SDL_CreateWindow
	("An SDL2 window", // window's title
		100, 100, // coordinates on the screen, in pixels, of the window's upper left corner
		WIDTH, HEIGHT, // window's length and height in pixels  
		SDL_WINDOW_OPENGL);
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface* surface;
	SDL_Rect properties;
	properties.x = 0;
	properties.y = 0;
	properties.w = 1366;
	properties.h = 768;
	surface = IMG_Load("Asset/FootBallTerrain.jpeg");
	if (surface == NULL)
	{
		SDL_TriggerBreakpoint();
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, &properties, &properties);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000); // window lasts 3 seconds
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}