#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "snake.h"

class Game
{
public:
	Game();
	~Game();

private:
	void loop();
	void draw(Graphics &graphics);
	void logic();

	int _movetrigger = 0;
	//functions for snake
	void fillvector(std::vector<Snake>&);
};
#endif