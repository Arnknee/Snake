#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <vector>
#include <iostream>
#include "graphics.h"
#include "item.h"

class Snake
{
public:
	Snake();
	~Snake();

	void move(int call);
	void draw(Graphics &graphics);
	void eat(Item &food);
	void update();
	bool death();

	SDL_Rect getRect();
	int getTotal();
	int getX();
	int getY();
	int getH();
	int getW();
	int getScore();

private:

	SDL_Rect snake;
	int _xPos = 0;
	int _yPos = 0;
	int xPrev = 0;
	int yPrev = 0;

	int _heigth = 20;
	int _width = 20;

	int _vel = 20;
	
	int _r = 255;
	int _g = 255;
	int _b = 255;

	int total = 0;
	int score = 0;

	std::vector <int> tailX;
	std::vector <int> tailY;

};
#endif 