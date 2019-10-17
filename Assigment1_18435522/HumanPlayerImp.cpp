#include "stdafx.h"
#include "HumanPlayer.h"
#include "Player.h"

HumanPlayer::HumanPlayer(int playerType) : Player(playerType) {}

void HumanPlayer::move(Board _board, int &row, int &col) {
	do {

		do {
			cout << "Enter Row: ";
			cin >> row;

			if (!_board.validRange(row)) {
				cout << "Number Outside Range Of Board." << endl;
			}
		} while (!_board.validRange(row));

		do {
			cout << "Enter Column: ";
			cin >> col;

			if (!_board.validRange(col)) {
				cout << "Number Outside Range Of Board." << endl;
			}
		} while (!_board.validRange(col));

		if (!_board.isEmpty(row - 1, col - 1)) {//checks if spot is empty and its not the first move
			cout << "** Spot Taken! **\n\n" << endl;
		}
	} while (!_board.placeOnBoard(row - 1, col - 1, _board.getCurrentPlayer()));
}