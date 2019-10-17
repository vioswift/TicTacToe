#pragma once

#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

class HumanPlayer : public Player {
public:
	HumanPlayer(int playerType = 0);
	void move(Board _board, int &row, int &col);
};