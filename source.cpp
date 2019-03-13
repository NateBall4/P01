#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <windows.h>
#include "puzzle.h"

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

int main() {
	// Declarations
	puzzle sliding_puzzle;

	HANDLE currentConsole;
	currentConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int height = 0;
	int width = 0;
	int** pointer = NULL;
	char keyStroke = ' ';						// holds the user's keystrokes as they come in
	int directionCode = UNSET;					// used to build a direction code to be sent to slideTile()

	//prompts for height
	cout << "please enter a height: ";
	cin >> height;
	cout << endl;

	//if input fails reprompt
	while (cin.fail() == true) {
		cin.clear();
		rewind(stdin);
		cout << "invalid input" << endl;
		cout << "please enter a height: ";
		cin >> height;
		cout << endl;
	}
	//prompts for width
	cout << "please enter a width: ";
	cin >> width;
	cout << endl;

	//if input fails reprompt
	while (cin.fail() == true) {
		cin.clear();
		rewind(stdin);
		cout << "invalid input" << endl;
		cout << "please enter a width: ";
		cin >> width;
		cout << endl;
	}

	//initialize pointer for the dynamic size
	pointer = new(int*[height]);
	//make it a 2d array
	for(int i = 0; i < height; i++){
		pointer[i] = new(int[width]);
	 }

	sliding_puzzle.InitializeBoard(pointer, height, width);				// initializes the board
	sliding_puzzle.PrintBoard(pointer, height, width, currentConsole);					// prints the board

	cout << endl;
	cout << "Press any key to start!" << endl;	//start prompt
	_getch();

	sliding_puzzle.scrambleBoard(pointer, height, width);				// scrambles the board

	system("cls");								 // clears screen
	sliding_puzzle.PrintBoard(pointer, height, width, currentConsole);	//prints new board

	while (sliding_puzzle.isBoardSolved(pointer, height, width) == false) { // while board is unsolved continue game
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

		sliding_puzzle.slideTile(pointer, height, width, directionCode); // slides tile
		sliding_puzzle.PrintBoard(pointer, height, width, currentConsole); // prints the board
	}

	system("cls"); //clears the screen
	sliding_puzzle.PrintBoard(pointer, height, width, currentConsole);	// prints the solved board
	cout << endl;
	cout << "congrats you win!";				// win message

		//deallocates the memory given to the pointer
	for (int i = 0; i < height; i++) {
		delete[] pointer[i];
	}
	delete[] pointer;

	_getch();									// Exit
	return 0;
}
