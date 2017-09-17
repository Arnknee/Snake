#include "item.h"
#include <cstdlib>
#include <ctime>

Item::Item(int r, int g, int b)
{
	srand(time(0));
	int _randomNum = (rand() % 30) * 20;
	int _randomNum2 = (rand() % 30) * 20;

	_xPos = _randomNum;
	_yPos = _randomNum2;

	_r = r;
	_g = g;
	_b = b;
	item.x = _xPos;
	item.y = _yPos;
	item.h = _heigth;
	item.w = _width;
}

Item::~Item()
{

}


void Item::draw(Graphics &graphics)
{
	SDL_SetRenderDrawColor(graphics.getRenderer(), _r, _g, _b, 255);
	SDL_RenderFillRect(graphics.getRenderer(), &item);

	graphics.flip();

}

void Item::update(SDL_Rect snake)
{
	srand(time(0));
	int _randomNum = (rand() % 30) * 20;
	int _randomNum2 = (rand() % 30) * 20;

	if (checkCollision(snake) == true)
	{
		//std::cout << "Collision!" << std::endl;
		item.x = _randomNum;
		item.y = _randomNum2;
	}
}

bool Item::checkCollision(SDL_Rect snake)
{
	//check x-axis collision
	if ((snake.x + snake.w == item.x + item.w) && (item.y == snake.y))
	{
		//std::cout << " X-axis true" << std::endl;
		return true;
	}
	//check y-axis collision
	if ((snake.y + snake.h == item.y + item.h) && (item.x == snake.x))
	{
		//std::cout << " Y-axis true" << std::endl;
		return true;
	}
}
