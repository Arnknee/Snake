#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <SDL.h>
#include "graphics.h"

class Item
{
public:
	Item(int r, int g, int b);
	~Item();

	void draw(Graphics &graphics);
	void update(SDL_Rect snake);
	bool checkCollision(SDL_Rect snake);

private:
	SDL_Rect item;
	int _xPos;
	int _yPos;
	int _heigth = 20;
	int _width = 20;

	int _r;
	int _g;
	int _b;

	bool cornerInRect(int x, int y, SDL_Rect snake);

};

#endif