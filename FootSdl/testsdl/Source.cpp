#include "Goal.h"
#include "Joueur.h"
using namespace std;

SDL_Rect initBG();
int main(int argc, char *argv[])
{
	//TODO augmenter la vitesse de la balle 
	//TODO faire rebondir la balle
	SDL_Init(SDL_INIT_VIDEO);
	vector<Goal> listeGoal;
	vector<int> Score;
	bool endGame = false;
	int collisionID;
	SDL_Window* window = SDL_CreateWindow
	("An SDL2 window", // window's title
		100, 100, // coordinates on the screen, in pixels, of the window's upper left corner
		WIDTH, HEIGHT, // window's length and height in pixels  
		SDL_WINDOW_OPENGL);

	SDL_Renderer* r = SDL_CreateRenderer(window, 1, NULL);
	SDL_Texture* bgTex = SDL_CreateTextureFromSurface(r, IMG_Load("./assets/FootBallTerrain.png"));
	SDL_Rect bgRect = initBG();
	Balle theBall = Balle(r);
	Score.push_back(0);
	Score.push_back(0);
	Joueur player1 = Joueur(r,0);
	Joueur player2 = Joueur(r, 1);
	listeGoal.push_back(Goal(r, 0));
	listeGoal.push_back(Goal(r, 1));
	while (!endGame) {
		// Verification Collision
		theBall.CollisionWall();
		theBall.CollisionJoueur(player1);
		theBall.CollisionJoueur(player2);
		for (int i = 0; i < listeGoal.size(); i++) {
			if (listeGoal.at(i).OnColision(theBall)) {
				Score.at(i) += 1;
				theBall.rebond();
				theBall.MoveTo(((i*2*WIDTH) + WIDTH)  / 4, HEIGHT / 2);

			}
		}
		// playersInput
		player1.WaitInput();
		// Mouvement Balle
		if (theBall.getInMouvement()) {
			theBall.Forward();
		}
		// redesssiner
		SDL_RenderCopy(r, bgTex, NULL, &bgRect);
		listeGoal.at(0).ShowGoalOnRendere();
		listeGoal.at(1).ShowGoalOnRendere();
		theBall.ShowInRenderer();
		player1.ShowInRenderer();
		player2.ShowInRenderer();
		SDL_RenderPresent(r);
		SDL_RenderClear(r);
		if (theBall.getRect().x >= WIDTH) {
			endGame = true;
		}
	}
	SDL_Delay(3000); // window lasts 3 seconds
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

SDL_Rect initBG()
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 1366;
	rect.h = 768;
	return rect;
}