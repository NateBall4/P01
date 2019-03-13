#ifndef SLIDING_TILE
#define SLIDING_TILE

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

//class sliding puzzle
class puzzle {
private:
	int counter;
	int temp;
	int emptyRow;
	int emptyCol;
	int move;
	int winCount;
	bool solved;
public:
	puzzle();
	// puzzle() is for variable declarations
	void InitializeBoard(int**, int, int);		// initializes the board
	void PrintBoard(int**, int, int, HANDLE);	// prints the board
	bool slideTile(int**, int, int, int);		// slides the tile
	void scrambleBoard(int**, int, int);				// depends upon slideTile()
	bool isBoardSolved(int**, int, int);		// indicates if the board is in the SOLVED state
};

#endif
