#pragma once
#include "Const.h"
#include <iostream>
#include <ctime>

class Apple {
public:
	Apple(char** board);

	Apple();

	void spawn(int, char**);


	void randompoint(char**);

	Point lastpointapple{-5,-5};

	Point curpointapple{};


};