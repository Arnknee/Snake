#include "snake.h"

Snake::Snake()
{
snake.h = _heigth;
snake.w = _width;

}

Snake::~Snake()
{

}

void Snake::move(int call)
{
	xPrev = _xPos;
	yPrev = _yPos;

	if (call == 1)
		_yPos -= _vel;

	if (call == 2)
		_yPos += _vel;

	if (call == 3)
		_xPos -= _vel;

	if (call == 4)
	    _xPos += _vel;

	if (snake.y < 0)
		_yPos = 600 - snake.h;

	if (snake.y + snake.h > 600)
		_yPos = 0;

	if (snake.x < 0)
		_xPos = 600 - snake.w;

	if (snake.x + snake.w > 600)
		_xPos = 0;

}

void Snake::draw(Graphics &graphics)
{
	

	for (int i = 0; i < total; i++)
	{
		snake.x = tailX[i];
		snake.y = tailY[i];
		SDL_SetRenderDrawColor(graphics.getRenderer(), 255, 255, 255, 255);
		SDL_RenderFillRect(graphics.getRenderer(), &snake);
	}

	snake.x = _xPos;
	snake.y = _yPos;
	SDL_SetRenderDrawColor(graphics.getRenderer(), 200, 200, 200, 255);
	SDL_RenderFillRect(graphics.getRenderer(), &snake);
}


void Snake::eat(Item &food)
{
	if (food.checkCollision(snake) == true)
	{
		food.update(snake);
		total++;
		score += 10;
		std::cout << score << std::endl;
	}
}

void Snake::update()
{

	if (tailX.size() != total)
	{
		tailX.push_back(xPrev);
		tailY.push_back(yPrev);
		//if (total > 0)
			//std::cout << "Snake is growing..." << std::endl;
	}

	for (int i = 1; i < total; i++)
	{
		tailX[i - 1] = tailX[i];
		tailY[i - 1] = tailY[i];
	}

	if (total > 0)
	{
		tailX[total - 1] = xPrev;
		tailY[total - 1] = yPrev;
	}

	if (death() == true)
	{
		total = 0;
		_xPos = 0;
		_yPos = 0;
		xPrev = 0;
		yPrev = 0;
		score = 0;
	}

}

bool Snake::death()
{
	for (int i = 0; i < total; i++)
	{
		if ((_xPos == tailX[i]) && (_yPos == tailY[i]))
		{
			std::cout << "Snake has died! :(" << std::endl;
			return true;
		}
	}
	return false;
}

int Snake::getTotal()
{
	return total;
}

int Snake::getX()
{
	return snake.x;
}

int Snake::getY()
{
	return snake.y;
}

int Snake::getH()
{
	return snake.h;
}

int Snake::getW()
{
	return snake.w;
}

int Snake::getScore()
{
	return score;
}

SDL_Rect Snake::getRect()
{
	return snake;
}