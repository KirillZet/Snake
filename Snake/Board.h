#pragma once
#include "Apple.h"
#include "Snake.h"
#include "Const.h"
static class Board
{
public:
	Board();
	void draw();
	void output();
	void change();


	int size_y;
	int size_x;
	char** board;
	Apple apple;
	Snake snake;


};
