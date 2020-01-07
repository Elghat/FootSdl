#pragma once
#ifndef DEF_PLAYER
#define DEF_PLAYER
#include "Header.h"

class Object
{
public:
	Object(std::string name, SDL_Renderer  *render,char * path);
	~Object();
	SDL_Texture* GetTexture();
	float GetWidth();
	float GetHeight();

private:
	std::string m_name;
	SDL_Texture* m_texture;
	SDL_Renderer *m_renderer;
	SDL_Rect m_rect;
	float m_height, m_width;
};


#endif