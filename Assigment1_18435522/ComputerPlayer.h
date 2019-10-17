#pragma once

#include "Board.h"
#include "Cell.h"
#include "Player.h"

class ComputerPlayer : public Player {/*the order goes WIN, BLOCK, CENTER*/
private:
	int **priPosBoard;//prioritize board
	int priPosBoardSize;

public:
	ComputerPlayer(int playerType = 0);
	~ComputerPlayer();
	void cellBubbleSort(Cell *cells, int size);
	void move(Board board, int &row, int &col);
	bool goForSpot(int &_row, int &_col, Board board, char piece);
	void goForCent(int &_row, int &_col, Board board);

	/* sets the central positions, such as out side starts at 0 and going in, number gets higher,  [0[1[2[3]]]]*/
	void setCentralPos(Board &_board);
};