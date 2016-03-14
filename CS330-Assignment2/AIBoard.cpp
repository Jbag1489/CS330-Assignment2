//**************
// AIBoard.cpp
//**************

#include "AIBoard.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;


AIBoard::AIBoard(int rows, int cols) { 
	gridRows = rows;
	gridColumns = cols;
}

AIBoard::~AIBoard() { 
}

vector< vector<char> > AIBoard::BuildBoard() {
	
	vector<vector<char>> board(gridRows, vector<char>(gridColumns));
	
	//Add empty board cells first
	for(int rows = 0; rows < gridRows; rows++) {
		for(int columns = 0; columns < gridColumns; columns++) {
			board[rows][columns] = '-';
		}
	}

	// Add Obstacle symbols
	board[6][12] = '#';	
	board[6][13] = '#';
	board[7][12] = '#';
	board[7][13] = '#';
	board[7][14] = '#';
	board[32][67] = '#';
	board[32][68] = '#';
	board[33][67] = '#';
	board[33][68] = '#';
	board[45][25] = '#';
	board[45][26] = '#';
	board[46][25] = '#';
	board[46][26] = '#';
	board[46][27] = '#';
	
	board[5][90] = 'S';		// Add Sun 1
	board[45][10] = 's';	// Add Sun 2

	return board;
}

void AIBoard::DisplayHeader(vector<Supply> supply, Player player) {
	system("cls");	// Clear screen
	cout << endl;	// Skip line

	// Display first row of character information
	SetColor(11);
	cout << " (P)layer    ";
	SetColor(10);
	cout << "Supply (1)    Supply (2)    Supply (3)    Supply (4)    ";
	SetColor(14);
	cout << "(S)un    ";
	SetColor(12);
	cout << "(E)nemy    ";
	SetColor(13);
	cout << "(#) Obstacle" << endl;
	
	// Display second row of character information
	SetColor(11);
	cout << " Fuel: " << setw(2) << player.GetFuel();
	SetColor(10);
	cout <<   "    Fuel: " << setw(2) << supply[0].GetFuel();
	cout << "      Fuel: " << setw(2) << supply[1].GetFuel();
	cout << "      Fuel: " << setw(2) << supply[2].GetFuel();
	cout << "      Fuel: " << setw(2) << supply[3].GetFuel();
	cout << endl << endl;
	SetColor(8);
}

void AIBoard::DisplayBoard(vector< vector<char> > myBoard) {
	char cellChar;
	for (int rows = 0; rows < getGridRows(); rows++) {
		cout << " ";
		for (int columns = 0; columns < getGridColumns(); columns++)  {

			// Set character color
			cellChar = myBoard[rows][columns];
			switch(cellChar) {
				case 'P' :		// Player
					SetColor(11);
					break;
				case '1' :		// Supply Ship 1
					SetColor(10);
					break;
				case '2' :		// Supply Ship 2
					SetColor(10);
					break;
				case '3' :		// Supply Ship 3
					SetColor(10);
					break;
				case '4' :		// Supply Ship 4
					SetColor(10);
					break;
				case 'S' :		// Sun
					SetColor(14);
					break;
				case 's' :		// Sun
					SetColor(14);
					break;
				case 'E' :		// Enemy Ship
					SetColor(12);
					break;
				case '#' :		// Obstacle
					SetColor(13);
					break;
				default  :		// Open Cell
					SetColor(8);
			}

			// Display cell character
			cout << myBoard[rows][columns];
		}
		cout << endl;
	}
	cout << endl;
	SetColor(8);
}

int AIBoard::getGridRows() {
	return gridRows;
}

int AIBoard::getGridColumns() {
	return gridColumns;
}

void AIBoard::MaximizeOutputWindow(void)		// Maximize console screen
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

void AIBoard::SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

/* color codes
1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Bright green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white
-Numbers after 15 are background colors-
*/