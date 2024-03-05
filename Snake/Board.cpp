#include "Board.h"
#include <iostream>
#include "Snake.h"
#include "Const.h"
Board::Board()
{

	this->size_y = cst::board_size_y;
	this->size_x = cst::board_size_x;

	board = new char* [this->size_y];

	for (int i = 0; i < this->size_y; i++) {

		board[i] = new char[this->size_x];
	}

	draw();


	apple = Apple(board);
	snake = Snake(this->size_x, this->size_y);


	for (Point i : snake.Pointscoords) {
		board[i.y][i.x] = '@';
	}

	board[apple.curpointapple.y][apple.curpointapple.x] = '*';


}
void Board::draw() {
	for (int i = 0; i < this->size_y; i++) {
		for (int j = 0; j < this->size_x; j++) {
			board[i][j] = ' ';

		}
	}
	for (int i = 0; i < this->size_y; i++) {
		board[i][0] = '%';
		board[i][size_x - 1] = '%';
	}
	for (int i = 0; i < this->size_x; i++) {
		board[0][i] = '%';
		board[size_y - 1][i] = '%';
	}

}


void Board::output() {
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			std::cout << board[i][j];
		}
		std::cout << '\n';
	}

}


void Board::change() {

	draw();
	snake.move(apple.curpointapple);

	apple.spawn(snake.eat(apple.curpointapple), board);

	for (Point i : snake.Pointscoords) {
		board[i.y][i.x] = '@';
	}
	board[apple.curpointapple.y][apple.curpointapple.x] = '*';
}