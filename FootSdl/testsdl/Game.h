#pragma once
#ifndef DEF_GAME
#define DEF_GAME
#include "Header.h"


class Game
{
public:
	Game();
	~Game();
	void Init(const char * title, int posx, int posy, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clear();
	bool Running();
	void addobject(std::string name, char * imagepath);


private:
	bool m_isrunning;
	SDL_Window * m_window;
	SDL_Renderer *m_renderer;
	int m_cnt;
	std::vector <Object*>m_objects;
	
};
#endif