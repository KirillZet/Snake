#pragma once
#include "Const.h"
#include <vector>
#include <conio.h>

class Snake
{
public:
	Snake();

	Snake(int,int);

	void move();

	void changesnakecoord();

	int eat(Point);



	

	unsigned int size = 2;

	int direction = 1;

	std::vector<Point> Pointscoords;

	Point headcoord{};

	Point backcoord{};

};