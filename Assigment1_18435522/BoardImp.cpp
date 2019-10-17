#include "stdafx.h"
#include "Board.h"

//initlizez the board
Board::Board(int bSize, int winLen){
	board = new int*[bSize];
	winningLength = winLen;
	boardSize = bSize;

	for (int col = 0; col < boardSize; col++) {
		board[col] = new int[boardSize];
		for (int row = 0; row < boardSize; row++) {
			board[col][row] = 0;
		}
	}
}

Board::~Board() {
	/*for (int count = 0; count < boardSize; count++) {
		delete[] board[count];
	}

	delete[] board;*/
}

int Board::getBoardSize() {
	return boardSize;
}

/* Displays the board */
void Board::displayBoard() {
	cout << setw(4);

	//adds a row of numbers
	for (int row = 0; row < boardSize; row++) {
		cout << row + 1 << setw(4);
	}

	cout << setw(2);

	//adds a a row of numbers and a secound row of | and the played board
	for (int row = 0; row < boardSize; row++) {
		cout << endl << row + 1 << setw(2);

		for (int col = 0; col < boardSize; col++) {
			cout << intInterpreter(board[row][col]) << (col == boardSize - 1 ? "" : "---");//this is where a a peice is placed
		}

		cout << "\n" << setw(6);

		//adds a secound row of |
		for (int row2 = 0; row2 < boardSize; row2++) {
			cout << (row == boardSize - 1 ? "" : " |  ") << setw(2);
		}
	}

	cout << "\n";
	cout << "\n";
}

/* places the piece on the board, if returns false it was an invalid move */
bool Board::placeOnBoard(int onRow, int onCol, char piece) {//need to add string input
	bool isSameSpot = board[onRow][onCol] == BLACK || board[onRow][onCol] == WHITE;//chekcs if there is a pice alreasy on the board

	if (isSameSpot) {//was it a valid move, was placed in same sport or is out of range
		return false;//was an invlid move
	}
	else {
		board[onRow][onCol] = charInterpreter(piece);

		return true;//was a valid move
	}
}

/* VALIDAATION checks if the user input meets the boundies */
bool Board::validRange(int range) {
	return range >= 1 && range <= boardSize;//was peice placed out side the row range
}

/* prints the winner or prints draw */
void Board::printWinState() {
	if (winningMove()) {
		cout << "\n** Winner Is " << getCurrentPlayer() << endl;
	}
	else if (!winningMove() && !isBoardFull()) {
		cout << "\n** Its a Draw " << endl;
	}
}

/* gets number of current moves */
int Board::getNumOfMoves() {
	return numberOfMoves;
}

/* adds another move and switches to next player */
void Board::addmove(int type) {
	currentPlaying = type == BLACK ? WHITE : BLACK;
	numberOfMoves++;
}

/* Gets the current player */
char Board::getCurrentPlayer() {
	return intInterpreter(currentPlaying);
}

/* checks if the board is full */
bool Board::isBoardFull() {
	bool notPlaced = false;//was a piece placed

	//checks if the board contains a 0, if it contains a 0 the board is not full
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < boardSize; col++) {
			if (board[row][col] == EMPTY) {
				notPlaced = true;
			}
		}
	}

	return notPlaced;
}

/* converts the number to what is seen on the board, 1=BLACK (X), -1=WHITE (O), 0=EMPTY, (num to char)   */
char Board::intInterpreter(int num) {
	switch (num) {
	case -1: return 'O';
		break;
	case 1: return 'X';
		break;
	default: return ' ';
	}
}

/* converts the integer to what is seen on the board, 1=BLACK (X), -1=WHITE (O), 0=EMPTY, (char to number)   */
int Board::charInterpreter(char piece) {
	switch (piece) {
	case 'O': return -1;
		break;
	case 'X': return 1;
		break;
	default: return 0;
	}
}

/* gives a random number between 0 and BOARD_SIZE */
int Board::rndNum(int bSize) {
	return (rand() % bSize + 1);
}

/* gets winning length number */
int Board::getWinLength() {
	return winningLength;
}

/* Did the move just taken allow the player to win */
bool Board::winningMove() {
	if (winRow() || winCol() || winPriDiag() || winSecDiag()) {
		return true;
	}
	else {
		return false;
	}
}

/* checks rows for wins  - */
bool Board::winRow() {
	int wincount = 0;

	for (int col = 0; col < boardSize; col++) {
		for (int row = 0; row < boardSize; row++) {
			wincount = 0;
			if (board[col][row] == board[col][row + 1] && board[col][row] != 0 && row <= boardSize - winningLength) {//the current row position to the next one, if they are the same 
				wincount++;//there is 2 the same
				for (int x = row + 1; x < boardSize; x++) {//this loops though the rest of the row
					if (board[col][row] == board[col][x] && board[col][row] != 0) {//comapires the first one that was found to the 
						wincount++;//counts how many in a row are the same
						if (wincount == winningLength) {//compaires the wincount to the wining amount
							return true;
						}
					}
					else {//if they are not the same reset the win count
						wincount = 0;
					}
				}
			}
		}
	}

	return false;
}

/* checks columns for wins |  */
bool Board::winCol() {
	int wincount = 0;

	for (int col = 0; col <= boardSize - winningLength; col++) {
		for (int row = 0; row < boardSize; row++) {
			wincount = 0;
			if (board[col][row] == board[col + 1][row] && board[col][row] != 0 && col <= boardSize - winningLength) {//the current column position to the next one, if they are the same 
				wincount++;//there is 2 the same
				for (int x = col + 1; x < boardSize; x++) {//this loops though the rest of the column
					if (board[col][row] == board[x][row] && board[col][row] != 0) {//comapires the first one that was found to the 
						wincount++;//counts how many in a column are the same
						if (wincount == winningLength) {//compaires the wincount to the wining amount
							return true;
						}
					}
					else {//if they are not the same reset the win count
						wincount = 0;
					}
				}
			}
		}
	}

	return false;
}

/* checks for win on Primary Diagonal ( \ ) */
bool Board::winPriDiag() {
	int wincount = 0;

	for (int col = 0; col <= boardSize - winningLength; col++) {
		for (int row = 0; row <= boardSize - winningLength; row++) {
			if (board[col][row] == board[col + 1][row + 1] && board[col][row] != EMPTY) {//the current row position to the next one, if they are the same 
				wincount++;//there is 2 the same
				for (int x = 1; x < winningLength; x++) {//this loops though the rest of the row
					if (board[col][row] == board[col + x][row + x] && board[col + x][row + x] != EMPTY) {//comapires the first one that was found to the 
						wincount++;//counts how many in a row are the same
						if (wincount == winningLength) {//compaires the wincount to the wining amount
							return true;
						}
					}
					else {//if they are not the same reset the win count
						wincount = 0;
					}
				}
			}
		}
	}

	return false;
}

/* checks for win on Secoundary Diagonal ( / ) */
bool Board::winSecDiag() {
	int wincount = 0;

	for (int col = 0; col <= boardSize - winningLength; col++) {
		for (int row = winningLength - 1; row <= boardSize - 1; row++) {
			
			if (board[col][row] == board[col + 1][row - 1] && board[col][row] != EMPTY) {//the current row position to the next one, if they are the same 
				wincount++;//there is 2 the same
				for (int x = 1; x <= winningLength - 1; x++) {//this loops though the rest of the row
					if (board[col][row] == board[col + x][row - x] && board[col + x][row - x] != EMPTY) {//comapires the first one that was found to the 
						wincount++;//counts how many in a row are the same
						if (wincount == winningLength) {//compares the wincount to the wining amount
							return true;
						}
					}
					else {//if they are not the same reset the win count
						wincount = 0;
					}
				}
			}
		}
	}

	return false;
}

/* cleans the board setting all values to 0 */
void Board::cleanBoard() {
	board[boardSize][boardSize] = {};
}

/* checks if the board spot is empty or not, 0 */
bool Board::isEmpty(int row, int col) {
	return board[row][col] == EMPTY;
}