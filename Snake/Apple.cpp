#include "Apple.h"

Apple::Apple(){

}
void Apple::randompoint(char** board) {
	while (1) {
		srand(time(NULL));
		curpointapple.x = rand()%cst::board_size_x;
		curpointapple.y = rand() % cst::board_size_y;

		if (curpointapple.x != lastpointapple.x and curpointapple.y != lastpointapple.y and board[curpointapple.y][curpointapple.x] == ' ') {
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


