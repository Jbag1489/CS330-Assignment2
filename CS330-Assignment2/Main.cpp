//***************
// TestMain.cpp
//***************

#include <iostream>
#include <vector>
#include <conio.h>
#include "Definitions.h"
#include <Windows.h>
#include "BaseShip.h"
#include "AIBoard.h"
#include "Supply.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;

int main()
{
	AIBoard aiBoard(BOARDROWS, BOARDCOLS);	// Set size of board
	vector<vector<char>> myBoard;			// Create board array
	myBoard = aiBoard.BuildBoard();			// Fill starting contents of board array cells
		
	vector<Supply> supply;
	supply.push_back(Supply(12,20,1,50,'1'));	// Create Supply Ship 1 (index 0)
	supply.push_back(Supply(12,70,1,45,'2'));	// Create Supply Ship 2 (index 1)
	supply.push_back(Supply(37,20,1,40,'3'));	// Create Supply Ship 3 (index 2)
	supply.push_back(Supply(37,70,1,35,'4'));	// Create Supply Ship 4 (index 3)
	Enemy enemy(25,50,1,'E');					// Create Enemy Ship
	Player player(0,0,1,50,'P');				// Create Player Character

	aiBoard.MaximizeOutputWindow();		// Maximize console window
	char a;
	bool gameLoop = true;
	int keyDirection;

	cout << "\n Press <Enter> to begin game";
	
	while(gameLoop) {
		a = _getch();	// Wait for user direction key movement
		keyDirection = (int)a;
		for(int loop = 0; loop < 4 ; loop++){
			myBoard = supply[loop].Update(myBoard);			// Update Supply Ship locations
		}
		myBoard = enemy.Update(myBoard);					// Update Enemy Ship location
		myBoard = player.Update(myBoard, keyDirection);		// Update Player location

		aiBoard.DisplayHeader(supply, player);				// Display board header each time in loop
		aiBoard.DisplayBoard(myBoard);						// Display board cells each time in loop

		cout << " Press <Enter> or Arrow Key to continue";
	}
	return 0;
} 
