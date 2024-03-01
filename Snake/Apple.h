#pragma once
#include "Const.h"
#include <iostream>
#include <ctime>

class Apple {
public:
	Apple();

	void spawn(int, char**);


	void randompoint(char**);

	Point lastpointapple{};

	Point curpointapple{};


};