#include "Object.h"


Object::Object(std::string name,SDL_Renderer *renderer, char * path)
{
	m_name = name;
	SDL_Surface* m_surface;
	m_surface = IMG_Load(path);
	m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
	m_height = m_surface->h;
	m_width = m_surface->w;
	SDL_FreeSurface(m_surface);
}
Object::~Object()
{

}

SDL_Texture* Object::GetTexture()
{
	return m_texture;
}

float Object::GetWidth()
{
	return m_width;
}

float Object::GetHeight()
{
	return m_height;
}
