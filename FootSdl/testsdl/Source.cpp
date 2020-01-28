#include "Goal.h"
using namespace std;

void initBG(SDL_Renderer* r);
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
	initBG(r);
	Balle theBall = Balle(r);

	listeGoal.push_back(Goal(r, 0));
	listeGoal.push_back(Goal(r, 1));
	while (!endGame) {
		theBall.MoveTo(theBall.getRect().x + 1, theBall.getRect().y);
		// Verification Collision Avec le Goal
		for (int i = 0; i < listeGoal.size(); i++) {
			std::cout << i << listeGoal.at(i).OnColision(theBall) << "\n";
		}
		// redesssiner
		listeGoal.at(0).ShowGoalOnRendere();
		listeGoal.at(1).ShowGoalOnRendere();
		theBall.ShowInRenderer();
		SDL_RenderPresent(r);
		SDL_RenderClear(r);
	}
	SDL_Delay(3000); // window lasts 3 seconds
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void initBG(SDL_Renderer* r)
{
	SDL_Surface* srfc = IMG_Load("./assets/FootBallTerrain.png");
	SDL_Texture* bgTex = SDL_CreateTextureFromSurface(r, srfc);
	SDL_Rect bgRect;
	bgRect.x = 0;
	bgRect.y = 0;
	bgRect.w = 1366;
	bgRect.h = 768;
	SDL_RenderCopy(r, bgTex, NULL, &bgRect);
}