#include "Snake.h"
#include <iostream>

Snake::Snake(int x, int y)
{
	headcoord.x = x/2;
	headcoord.y = y/2;

	backcoord.x = x / 2;
	backcoord.y = y / 2 + 1;
	
	Pointscoords.push_back(headcoord);
	Pointscoords.push_back(backcoord);

}
Snake::Snake()
{
	
}

void Snake::changesnakecoord() {
	switch (direction) {
	case 0:
		headcoord.x -= 1;
		backcoord.x -= 1;
		break;
	case 1:
		headcoord.y -= 1;
		backcoord.y -= 1;
		break;
	case 2:
		headcoord.x += 1;
		backcoord.x += 1;
		break;
	case 3:
		headcoord.y += 1;
		backcoord.y += 1;
		break;
	}
}




void Snake::move()
{
	

	if (/*_kbhit()*/1) {
		if (/*_getch() == 224*/1) {

			const int left = 75;
			const int up = 72;
			const int right = 77;
			const int down = 80;
			switch (/*_getch()*/75) {
			case left:
				direction = 0;
				break;
			case up:
				direction = 1;
				break;
			case right:;
				direction = 2;
				break;
			case down:;
				direction = 3;
				break;

			}
			changesnakecoord();
		}
	}
	else {
		changesnakecoord();
	}
}

int Snake::eat(Point applecoords) {
	if (headcoord.x==applecoords.x && headcoord.y == applecoords.y)
	{
		return 1;
	}
	return 0;
}
