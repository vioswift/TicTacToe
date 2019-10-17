#include "stdafx.h"
#include "ComputerPlayer.h"
#include "Cell.h"

ComputerPlayer::ComputerPlayer(int playerType) : Player(playerType) {}

ComputerPlayer::~ComputerPlayer() {
	/*for (int i = 0; i < priPosBoardSize; i++) {
		delete[] priPosBoard[i];
	}

	delete[] priPosBoard;*/
}

void ComputerPlayer::move(Board board, int &row, int &col) {
	setCentralPos(board);
	cout << "Computer " << board.getCurrentPlayer() << " Has Moved" << endl;

	do {
		if (board.getCurrentPlayer() == 'X') {
			if (!goForSpot(row, col, board, 'X')) {
				if (!goForSpot(row, col, board, 'O')) {
					goForCent(row, col, board);
				}
			}
		}

		if (board.getCurrentPlayer() == 'O') {
			if (!goForSpot(row, col, board, 'O')) {
				if (!goForSpot(row, col, board, 'X')) {
					goForCent(row, col, board);
				}
			}
		}
	} while (!board.placeOnBoard(row, col, board.getCurrentPlayer()));//checks for a valid move, if not try again
}

bool ComputerPlayer::goForSpot(int &_row, int &_col, Board board, char piece) {
	Board tempBoard = board;//tempoary board

	int setRow = 0;
	int setCol = 0;
	bool isPlaced = false;

	for (int row = 0; row < board.getBoardSize(); row++) {
		for (int col = 0; col < board.getBoardSize(); col++) {
			if (tempBoard.placeOnBoard(row, col, piece) && !isPlaced) {
				if (tempBoard.winningMove()) {
					setRow = row;
					setCol = col;
					isPlaced = true;

					_row = setRow;
					_col = setCol;

					board.board[row][col] = 0;

					return isPlaced;
				}
				else {
					tempBoard.board[row][col] = 0;//0 EMPTY
					isPlaced = false;
				}
			}
		}
	}

	if (isPlaced) {
		_row = setRow;
		_col = setCol;
	}

	return isPlaced;
}

/* sets the variable numbers */
void ComputerPlayer::goForCent(int &_row, int &_col, Board board) {
	Cell *cells = new Cell[board.getBoardSize() * board.getBoardSize()];
	bool isPlaced = false;
	int tempRow = 0;
	int tempCol = 0;

	for (int q = 0; q < board.getBoardSize(); q++)
	{
		for (int t = 0; t < board.getBoardSize(); t++)
		{
			cells[q * board.getBoardSize() + t] =  Cell(q, t, board.board[q][t], priPosBoard[q][t]);
		}
	}

	//sort cell by priority
	cellBubbleSort(cells, board.getBoardSize() * board.getBoardSize());

	//select highest cell
	for (int row = 0; row < board.getBoardSize() * board.getBoardSize(); row++) {
		if (cells[row].peice == 0) {
			tempRow = cells[row].row;
			tempCol = cells[row].col;

			if ((rand() % 2) != 0) {// 50/50 chance of being placed
				_row = cells[row].row;
				_col = cells[row].row;
				isPlaced = true;
			}

			if (!isPlaced) {
				_row = tempRow;
				_col = tempCol;
			}
			
			return;
		}
	}

	delete[] cells;

}

void ComputerPlayer::cellBubbleSort(Cell *cells, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = row + 1; col < size; col++) {
			if (cells[row].priority < cells[col].priority) {
				swap(cells[row], cells[col]);
			}
		}
	}
}

/* sets the central positions, such as out side starts at 0 and going in, number gets higher,  [1[2[3[4]]]]*/
void ComputerPlayer::setCentralPos(Board &_board) {
	priPosBoardSize = _board.getBoardSize();
	priPosBoard = new int*[priPosBoardSize];
	
	for (int i = 0; i < priPosBoardSize; i++) {
		priPosBoard[i] = new int[priPosBoardSize];
	}

	for (int count = 0; count < priPosBoardSize; count++) {//counts outside in
		for (int row = count; row < priPosBoardSize - count; row++) {
			for (int col = count; col < priPosBoardSize - count; col++) {
				if (row <= priPosBoardSize - count && col <= priPosBoardSize - count) {
					priPosBoard[row][col] = count + 1;
				}
			}
		}
	}
}