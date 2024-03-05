#include "Apple.h"

Apple::Apple(char** board){
	randompoint(board);
}

Apple::Apple() {
}
void Apple::randompoint(char** board) {
	while (1) {
		srand(time(NULL));
		curpointapple.x = rand()%(cst::board_size_x-3);
		curpointapple.y = rand() % (cst::board_size_y-3);

		if (curpointapple.x != lastpointapple.x && 
		    curpointapple.y != lastpointapple.y && 
		    board[curpointapple.y][curpointapple.x] == ' ' &&
		    curpointapple.x>3 && curpointapple.y > 3) {
			break;
		}
	}
}
void Apple::spawn(int checkeat, char** board) {
	if (checkeat == 1) {
		lastpointapple.x = curpointapple.x;
		lastpointapple.y = curpointapple.y;
		randompoint(board);
	}
};


