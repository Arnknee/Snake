#include "graphics.h"

Graphics::Graphics(int screenwidth, int screenheigth)
{
	_screenwidth = screenwidth;
	_screenheigth = screenheigth;

	SDL_CreateWindowAndRenderer(_screenwidth, _screenheigth, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Game");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer()
{
	return _renderer;
}

int Graphics::getScreenWidth()
{
	return _screenwidth;
}

int Graphics::getScreenHeigth()
{
	return _screenheigth;
}

void Graphics::renderScore(int score)
{
	SDL_Color Black = { 50,50,50,255 };
	TTF_Font* _font = TTF_OpenFont((char*)"OpenSans-Regular.ttf", 15);

	scoreSurface = TTF_RenderText_Solid(_font, (std::to_string(score)).c_str(), Black);
	scoreTexture = SDL_CreateTextureFromSurface(_renderer, scoreSurface);

	SDL_Rect surface;
	surface.x = 250;
	surface.y = 250;
	surface.w = 100;
	surface.h = 100;

	SDL_RenderCopy(_renderer, scoreTexture, NULL, &surface);

	//TTF_CloseFont(_font);
}