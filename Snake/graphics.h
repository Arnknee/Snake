#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>


class Graphics
{
public:

	Graphics(int screenwidth, int screenheigth);
	~Graphics();

	void flip();
	void clear();
	void renderScore(int score);

	SDL_Renderer * getRenderer();
	int getScreenHeigth();
	int getScreenWidth();

private:

	SDL_Window* _window = NULL;
	SDL_Renderer* _renderer = NULL;
	TTF_Font* _font = NULL;
	SDL_Surface* scoreSurface = NULL;
	SDL_Texture* scoreTexture = NULL;

	int _screenwidth, _screenheigth;
};
#endif