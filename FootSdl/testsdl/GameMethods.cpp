#include "Game.h"
#include "Object.h"
#define LENGHT 4
#define ROWS 4
using namespace std;


SDL_Rect Frame;
SDL_Rect Position;
int line = 0;
int column = -1;


Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(const char * title, int posx, int posy, int width, int height, bool fullscreen)
{
	m_cnt = 0;
	int flag = 0;
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "subsystem initialised" << endl;
		m_window = SDL_CreateWindow(title, posx, posy, width, height, flag);
		if (m_window)
		{
			cout << "window created" << endl;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
			cout << "renderer created" << endl;
		}
		m_isrunning = true;
	}
	else
	{
		m_isrunning = false;
	}

}
void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		m_isrunning = false;
		break;

	default:
		break;
	}
}
void Game::Update() // ici je vais calculer quelle frame découper
{
	if (column == (LENGHT-1))
	{
		column = -1;
		if (line == (ROWS - 1))
		{
			line = -1;
		}		
		line++;
		Frame.y = line*Frame.h;
	}
	column++;
	Frame.x = (this->m_objects[0]->GetWidth() / LENGHT) *column;
	SDL_Delay(40);

}
void Game::Render()
{
	SDL_RenderClear(m_renderer); 
	for (int i = 0; i < m_objects.size(); i++)
	{
		SDL_RenderCopy(this->m_renderer, this->m_objects[i]->GetTexture(),&Frame, &Position);
	}
	SDL_RenderPresent(m_renderer);

}
void Game::Clear()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}
bool Game::Running()
{
	return true;
}

void Game::addobject(std::string name, char * imagepath)
{
	this->m_objects.push_back(new Object(name,this->m_renderer,imagepath)); // J'ajoute un spritesheet
	Frame.h = this->m_objects[0]->GetHeight() / ROWS; // j'adapte la hauteur nécessaire pour le rect de découpage
	Frame.w = this->m_objects[0]->GetWidth() / LENGHT; // j'adapte la largeur nécessaire pour le rect de découpage
	Position.w = Frame.w; //Je scale le rect de destination à la même largeur que l'image découpée
	Position.h = Frame.h; //Je scale le rect de destination à la même hauteur que l'image découpée
	Position.x = (SDL_GetWindowSurface(m_window)->w/2) - ((this->m_objects[0]->GetHeight()/ROWS)/2);  //Je place le rect de destination au milieu Y de mon écran
	Position.y = (SDL_GetWindowSurface(m_window)->h/2) - ((this->m_objects[0]->GetWidth()/ LENGHT)/2); //Je place le rect de destination au milieu X de mon écran
}

