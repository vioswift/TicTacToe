#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h> 
#include <iomanip>

using namespace std;

class Board {//assuming player X will always make for the first move and the human
private:
	const int WHITE = -1;//O
	const int BLACK = 1;//X
	const int EMPTY = 0;//empty
	int numberOfMoves = 0;
	int currentPlaying = BLACK;//the current player
	int boardSize;//row, column size on board
	int winningLength; //K, number of stone sin a row to win
	

public:
	int **board;//M, the size of the board, 1=BLACK, -1=WHITE, 0=EMPTY, bard elmeents are set to 0
	//initlizez the board
	Board(int bSize = 3, int winLen = 3);
	~Board();

	int getBoardSize();

	/* Displays the board */
	void displayBoard();

	/* places the piece on the board, if returns false it was an invalid move */
	bool placeOnBoard(int onRow, int onCol, char piece);

	/* VALIDAATION checks if the user input meets the boundies */
	bool validRange(int range);

	/* prints the winner or prints draw */
	void printWinState();

	/* gets number of current moves */
	int getNumOfMoves();

	/* adds another move and switches to next player */
	void addmove(int type);

	/* Gets the current player */
	char getCurrentPlayer();

	/* checks if the board is full */
	bool isBoardFull();

	/* converts the number to what is seen on the board, 1=BLACK (X), -1=WHITE (O), 0=EMPTY, (num to char)   */
	char intInterpreter(int num);

	/* converts the integer to what is seen on the board, 1=BLACK (X), -1=WHITE (O), 0=EMPTY, (char to number)   */
	int charInterpreter(char piece);

	/* gives a random number between 0 and BOARD_SIZE */
	int rndNum(int bSize);

	/* gets winning length number */
	int getWinLength();

	/* Did the move just taken allow the player to win */
	bool winningMove();

	/* checks rows for wins  - */
	bool winRow();

	/* checks columns for wins |  */
	bool winCol();

	/* checks for win on Primary Diagonal ( \ ) */
	bool winPriDiag();

	/* checks for win on Secoundary Diagonal ( / ) */
	bool winSecDiag();

	/* cleans the board setting all values to 0 */
	void cleanBoard();

	/* checks if the board spot is empty or not, 0 */
	bool isEmpty(int row, int col);
};