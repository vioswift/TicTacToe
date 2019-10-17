#include "stdafx.h"
#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(int playerType) : Player(playerType) {}

void RandomPlayer::move(Board _board, int &row, int &col) {
	cout << "Computer " << _board.getCurrentPlayer() << " Has Moved" << endl;

	do {
		row = _board.rndNum(_board.getBoardSize());
		col = _board.rndNum(_board.getBoardSize());
	} while (!_board.placeOnBoard(row - 1, col - 1, _board.getCurrentPlayer()));//checks for a valid move, if not try again
}