#pragma once

#include <iostream>
#include "Board.h"

using namespace std;

class Player {
protected:
	int playerType;
public:
	Player(int type = 0);
	int getType();
};