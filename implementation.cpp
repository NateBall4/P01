#include "puzzle.h"

using namespace std;

#define PIVOT_SYMBOL	'*'		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		8		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		4		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		6		// pass to slideTile() to trigger RIGHT movement

#define SCRAMBLE		1000000 // scambles the board into oblivion

#define COLOR_DEFAULT	7 // default windows color
#define COLOR_RED		12 // windows api red 
#define COLOR_GREEN		10 // windows api green


puzzle::puzzle() {
	 counter = 0;
	 temp = 0;
	 emptyRow = 0;
	 emptyCol = 0;
	 move = 0;
	 winCount = 0;
	 solved= 0;
}

void puzzle::InitializeBoard(int** theBoard, int height, int width) {
	// YOUR IMPLEMENTATION GOES HERE...
	int counter = 1;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (counter == height * width) {
				theBoard[i][j] = PIVOT_SYMBOL; // at the last space print the pivot symbol
			}
			else {
				theBoard[i][j] = counter++;
			}
		}
	}
}

void puzzle::PrintBoard(int** theBoard, int height, int width, HANDLE CurrentConsole) {
	// YOUR IMPLEMENTATION GOES HERE...
	int counter = 1; // used to teast is the pieces are in the right space

	for (int i = 0; i < height; i++) {
		cout << endl;
		for (int j = 0; j < width; j++) {
			if (theBoard[i][j] == counter) {
				SetConsoleTextAttribute(CurrentConsole, COLOR_GREEN); // if number is in the right space make it green
			}
			else if (theBoard[i][j] == PIVOT_SYMBOL) { // makes the pivot symbol the default color
				SetConsoleTextAttribute(CurrentConsole, COLOR_DEFAULT);
			}
			else {
				SetConsoleTextAttribute(CurrentConsole, COLOR_RED); // else make it red
			}

			if (theBoard[i][j] == PIVOT_SYMBOL) { // if the board location is the pivot symbol print it as a char
				cout << setw(3) << (char)theBoard[i][j];
			}
			else { // prints the board
				cout << setw(3) << theBoard[i][j];
			}
			counter++;
		}
	}
	SetConsoleTextAttribute(CurrentConsole, COLOR_DEFAULT);
}

bool puzzle::slideTile(int** theBoard,int height, int width, int slideDirection) {
	// YOUR IMPLEMENTATION GOES HERE...
	int temp = 0;
	int emptyRow = 0;
	int emptyCol = 0;

	//find the position of the slider
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (theBoard[i][j] == PIVOT_SYMBOL) {
				emptyRow = i;
				emptyCol = j;

			}
		}
	}
	switch (slideDirection) {
	case SLIDE_UP: { // function for moving up
		if (emptyRow - 1 < NULL) {// if move up is OOB flag as a bad move
			slideDirection = false;
		}
		if (slideDirection != false) { // if move is good make it
			theBoard[emptyRow][emptyCol] = theBoard[emptyRow - 1][emptyCol];
			theBoard[emptyRow - 1][emptyCol] = PIVOT_SYMBOL;
		}
		else { //if not don't
			   //do nothing
		}
		break;
	}

	case SLIDE_DOWN: { // function for moving down
		if (emptyRow + 1 >= height) {// if move down is OOB flag as a bad move
			slideDirection = false;
		}
		if (slideDirection != false) {// if move is good make it
			theBoard[emptyRow][emptyCol] = theBoard[emptyRow + 1][emptyCol];
			theBoard[emptyRow + 1][emptyCol] = PIVOT_SYMBOL;
		}
		else {// if not don't
			  //do nothing
		}
		break;
	}

	case SLIDE_RIGHT: { // function for moving right
		if (emptyCol + 1 >= width) {// if move right is OOB flag as a bad move
			slideDirection = false;
		}
		if (slideDirection != false) {// if move is good make it
			theBoard[emptyRow][emptyCol] = theBoard[emptyRow][emptyCol + 1];
			theBoard[emptyRow][emptyCol + 1] = PIVOT_SYMBOL;
		}
		else {// if not don't
			  //do nothing
		}
		break;
	}

	case SLIDE_LEFT: { // function for moving left
		if (emptyCol - 1 < NULL) {// if move left is OOB flag as a bad move
			slideDirection = false;
		}
		if (slideDirection != false) {// if move is good make it
			theBoard[emptyRow][emptyCol] = theBoard[emptyRow][emptyCol - 1];
			theBoard[emptyRow][emptyCol - 1] = PIVOT_SYMBOL;
		}
		else {// if not don't
			  //do nothing
		}
		break;
	}
	}
	return false;
}

void puzzle::scrambleBoard(int** theBoard, int height, int width) {
	// YOUR IMPLEMENTATION GOES HERE...
	srand((unsigned int)time(NULL));
	int move;

	for (int i = 0; i < SCRAMBLE; i++) //Series of random moves
	{
		move = rand() % 8 + 1;
		slideTile(theBoard, height, width, move);
	}
}

bool puzzle::isBoardSolved(int** amISolved, int height,int width) {
	// YOUR IMPLEMENTATION GOES HERE...
	bool solved = false;
	int counter = 1;
	int winCount = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			if (amISolved[i][j] == counter) { // if the piece is in the right spot solved = true wincounter increases
				solved = true;
				winCount++; // used to measure if the player has won (E.X. a 3 x 3 board has a win count of 8 since there are 8 pieces)
			}
			else if (counter == (height * width) && winCount == ((height * width) - 1)) { // if all pieces are in the right spot and the wincount is complete you win
				solved = true;
			}
			else { // else the board is not solved
				solved = false;
				winCount = 0;
			}
			counter++;
		}
	}
	return solved;
}
