#pragma once

#include "Board.h"
#include "Player.h"

/* the computer plays random moves*/
class RandomPlayer : public Player {
public:
	RandomPlayer(int playerType = 0);
	void move(Board _board, int &row, int &col);
};