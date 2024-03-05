#include "Snake.h"
#include <iostream>



Snake::Snake(int x, int y)
{
	Pointscoords.push_back(Point{x/2,y/2});
	Pointscoords.push_back(Point{ x / 2,y / 2 + 1 });
}
Snake::Snake()
{
	
}

void Snake::changesnakecoord(Point applecoords) {
	switch (direction) {
	case 0:
		Pointscoords.push_front(Point{ Pointscoords.front().x - 1,Pointscoords.front().y });
		break;
	case 1:
		Pointscoords.push_front(Point{ Pointscoords.front().x,Pointscoords.front().y-1 });
		break;
	case 2:
		Pointscoords.push_front(Point{ Pointscoords.front().x+1,Pointscoords.front().y});
		break;
	case 3:
		Pointscoords.push_front(Point{ Pointscoords.front().x,Pointscoords.front().y + 1});
		break;
	}
	if (eat(applecoords)==0){ Pointscoords.pop_back(); }
}

int Snake::live()
{
	int c = 0;
	std::list<Point> CopyPoints;
	for (Point i : Pointscoords) {
		if ((Pointscoords.front().x == i.x && Pointscoords.front().y == i.y && c!=0) ) {
			return 0;
		}
		c += 1;
	}
	if ((Pointscoords.front().x == 0) || (Pointscoords.front().x == cst::board_size_x - 1) || (Pointscoords.front().y == cst::board_size_y - 1) || (Pointscoords.front().y == 0))
	{
		return 0;
	}
	return 1;
}


void Snake::move(Point applecoords)
{
	

	if (_kbhit()) {
		if (_getch() == 224) {

			const int left = 75;
			const int up = 72;
			const int right = 77;
			const int down = 80;
			switch (_getch()) {
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
			changesnakecoord(applecoords);
		}
	}
	else {
		changesnakecoord(applecoords);
	} 

}

int Snake::eat(Point applecoords) {
	if (Pointscoords.front().x ==applecoords.x && Pointscoords.front().y == applecoords.y)
	{
		return 1;
	}
	return 0;
}
