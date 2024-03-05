#pragma once
#include "Const.h"
#include <list>
#include <conio.h>


class Snake
{
public:
	Snake();

	Snake(int,int);

	void move(Point);

	void changesnakecoord(Point);

	int eat(Point);


	int live();
	

	unsigned int size = 2;

	int direction = 1;

	std::list<Point> Pointscoords;

	

};