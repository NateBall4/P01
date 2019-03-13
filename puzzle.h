
#ifndef SLIDING_TILE
#define SLIDING_TILE

#include <iostream>
#include <iomanip>				// for setw()
using namespace std;

#include <string.h>				// for strcpy()
#include <conio.h>				// for getch()

#include <windows.h>			// for COLOR!
#include <windows.h>

#define NUM_ROWS		7		// should not be changed for this solution
#define NUM_COLS		7		// should not be changed for this soultion

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
		void InitializeBoard(int[NUM_ROWS][NUM_COLS]);
		void PrintBoard(int[NUM_ROWS][NUM_COLS], HANDLE);
		bool slideTile(int[NUM_ROWS][NUM_COLS], int);
		void scrambleBoard(int[NUM_ROWS][NUM_COLS]);				// depends upon slideTile()
		bool isBoardSolved(int[NUM_ROWS][NUM_COLS]);		// indicates if the board is in the SOLVED state
};

#endif
