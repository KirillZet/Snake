#include "Board.h"
#include <iostream>
#include "Snake.h"
#include "Const.h"
Board::Board()
{
	
	this->size_y = cst::board_size_y;
	this->size_x = cst::board_size_x;
	
	snake = Snake( this->size_x, this->size_y );
	apple = Apple();

	board = new char* [this->size_y];

	for (int i = 0; i < this->size_y; i++) {

		board[i] = new char[this->size_x];
	}
	for (int i = 0; i < this->size_y; i++) {
		for (int j = 0; j < this->size_x;j++) {
			board[i][j] = ' ';

		}
	}

	board[snake.headcoord.y][snake.headcoord.x] = '@';
	board[snake.backcoord.y][snake.backcoord.x] = '@';

}


void Board::output() {
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x;j++) {
			std::cout<<board[i][j];
		}
		std::cout <<'\n';
	}

}


void Board::change() {
	
	
	if (/*snake.eat(apple.curpointapple) == 0*/1) {
		board[snake.backcoord.y][snake.backcoord.x] = ' ';
	}
	else {
		board[snake.backcoord.y][snake.backcoord.x] = '@';
	}
	snake.move();

	board[snake.headcoord.y][snake.headcoord.x] = '@';



}