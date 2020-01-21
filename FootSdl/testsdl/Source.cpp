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

	SDL_Renderer* r = SDL_CreateRenderer(window, 1, NULL);


	listeGoal.push_back(Goal(r, 0));
	listeGoal.push_back(Goal(r, 1));
	listeGoal.at(0).ShowGoalOnRendere();
	listeGoal.at(1).ShowGoalOnRendere();
	SDL_RenderPresent(r);
	SDL_Delay(3000); // window lasts 3 seconds
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}