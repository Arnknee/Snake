#include <SDL.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "game.h"
#include "snake.h"
#include "item.h"

int screenwidth = 600;
int screenheigth = 600;

Snake snake;
Item food(255, 0, 0);

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	std::cout << "Game initalised!" << std::endl;
	loop();
}

Game::~Game()
{

}

void Game::loop()
{
	Graphics graphics(screenwidth, screenheigth);

	SDL_Event events;

	int startTicks;

	while (true)
	{
		startTicks = SDL_GetTicks();

		if (SDL_PollEvent(&events))
			if (events.type == SDL_QUIT)
				return;

		logic();

		draw(graphics);

		Uint32 frameTicks = SDL_GetTicks() - startTicks;
		if (1000 / 10 > frameTicks)
			SDL_Delay(1000 / 10 - frameTicks);

	}
}

void Game::logic()
{
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	if(_movetrigger != 2)
	if (keystates[SDL_SCANCODE_W])
		_movetrigger = 1;

	if (_movetrigger != 1)
	if (keystates[SDL_SCANCODE_S])
		_movetrigger = 2;

	if (_movetrigger != 4)
	if (keystates[SDL_SCANCODE_A])
		_movetrigger = 3;

	if (_movetrigger != 3)
	if (keystates[SDL_SCANCODE_D])
		_movetrigger = 4;

	snake.move(_movetrigger);

	snake.eat(food);

	snake.update();

	snake.death();
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();

	graphics.renderScore(snake.getScore());
	snake.draw(graphics);
	food.draw(graphics);

	SDL_SetRenderDrawColor(graphics.getRenderer(), 0, 0, 0, 255);


	graphics.flip();
}

