#pragma once

#include <iostream>
#include <time.h> 
#include "Board.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h"

using namespace std;

class MKGame {
private:
	Board board;//start a board
	HumanPlayer player[2];//2 human players
	ComputerPlayer cp;//computer player
	RandomPlayer rp;//random player, the computer places moves randomly
	int winLen;
	int boardSize;
	int option;
	int row;
	int col;

public:
	MKGame();
	void playGame();
};