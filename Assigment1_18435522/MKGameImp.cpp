#include "stdafx.h"
#include "MKGame.h"

void MKGame::playGame() {
	srand(time(NULL));

	Board board(boardSize, winLen);

	//player enters infomation and makes moves
	do {
		cout << "\nCurrent Player Is " << board.getCurrentPlayer() << endl;
		cout << "To win you must get " << board.getWinLength() << " In a row" << endl;

		board.displayBoard();

		if (board.getCurrentPlayer() == 'O') {//if O computer player make a move, else player moves X
			if (option == 1) {
				cp.move(board, row, col);
			}
			else if (option == 2) {
				rp.move(board, row, col);
			}
			else if (option == 3) {
				cp.move(board, row, col);
			}
			else {
				cp.move(board, row, col);
			}
		}
		else {
			if (option == 1) {
				player[0].move(board, row, col);
			}
			else if (option == 2) {
				cp.move(board, row, col);
			}
			else if (option == 3) {
				cp.move(board, row, col);
			}
			else {
				cp.move(board, row, col);
			}
		}

		board.printWinState();
		board.addmove(board.charInterpreter(board.getCurrentPlayer()));
	} while (board.isBoardFull() && !board.winningMove());

	board.displayBoard();

	system("pause");
}

MKGame::MKGame() {
	player[0] = HumanPlayer(-1);
	player[1] = HumanPlayer(1);
	cp = ComputerPlayer(-1);
	rp = RandomPlayer(1);

	cout << "#### Welcome to the TicTacToe game by Kyle Maurer 18435522 ####" << endl;
	cout << "#### Black (X) is the human player, White (O) is the computer player ####" << endl;

	cout << "Enter Board Size (M): " << endl;
	cin >> boardSize;
	cout << "Enter Winning Length (K): " << endl;
	cin >> winLen;

	cout << "Option 1: computer vs human: " << endl;
	cout << "Option 2: random vs computer " << endl;
	cout << "Option 3: computer vs computer " << endl;
	cin >> option;
}

