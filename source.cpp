#pragma warning(disable:4996)
#include "puzzle.h"

#define NUM_ROWS		7		// should not be changed for this solution
#define NUM_COLS		7		// should not be changed for this soultion

#define PIVOT -1				// used to mark the pivot spot (blank area) on the puzzle
#define PIVOT_SYMBOL	'*'		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		8		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		4		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		6		// pass to slideTile() to trigger RIGHT movement

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define SCRAMBLE		1000000

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10

int main() {
	// Declarations
	puzzle sliding_puzzle;
	HANDLE currentConsole;
	currentConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int slidingBoard[NUM_ROWS][NUM_COLS];		// the board that holds the sliding tiles
	char keyStroke = ' ';						// holds the user's keystrokes as they come in
	int directionCode = UNSET;					// used to build a direction code to be sent to slideTile()

	sliding_puzzle.InitializeBoard(slidingBoard);				// initializes the board
	sliding_puzzle.PrintBoard(slidingBoard, currentConsole);					// prints the board

	cout << endl;
	cout << "Press any key to start!" << endl;	//start prompt
	_getch();

	sliding_puzzle.scrambleBoard(slidingBoard);				// scrambles the board

	system("cls");								 // clears screen
	sliding_puzzle.PrintBoard(slidingBoard, currentConsole);	//prints new board

	while (sliding_puzzle.isBoardSolved(slidingBoard) == false) { // while board is unsolved continue game
		cout << endl;
		cout << "Please use the numpad arrows to move." << endl;
		cout << "what direction would you like to move?: " << endl;
		cin >> directionCode;

		while (cin.fail() == true) { // if input wasn't a number clear input and reprompt
			cout << "That wasn't a number" << endl;
			cin.clear();
			rewind(stdin);
			cout << "Please use the numpad arrows to move." << endl;
			cout << "what direction would you like to move?: " << endl;
			cin >> directionCode;
		}
		system("cls");							//clears the screen

		sliding_puzzle.slideTile(slidingBoard, directionCode); // slides tile
		sliding_puzzle.PrintBoard(slidingBoard, currentConsole); // prints the board
	}

	system("cls"); //clears the screen
	sliding_puzzle.PrintBoard(slidingBoard, currentConsole);	// prints the solved board
	cout << endl;
	cout << "congrats you win!";				// win message
	_getch();									// Exit
	return 0;
}
