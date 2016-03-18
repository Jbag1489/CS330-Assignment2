//**************
//  Supply.cpp
//**************

#include "Supply.h"
#include "Definitions.h"
using namespace std;

Supply::Supply(int iRow, int iCol, int iState, int iFuel, char cId){
	row = iRow;
	col = iCol;
	fuel = iFuel;
	state = iState;
	id = cId;
}

Supply::~Supply(){
}

vector<vector<char>> Supply::Update(vector<vector<char>> board, Player player, Enemy enemy) {

	int playerRow = player.GetRow();
	int playerCol = player.GetCol();
	int playerFuel = player.GetFuel();
	int enemyRow = enemy.GetRow();
	int enemyCol = enemy.GetCol();

	switch(state) {
		case 1 :	// Roam
			board = Roam(board, playerRow, playerCol, playerFuel, enemyRow, enemyCol);
			break;
		case 2 :	// Flee
			board = Flee(board, playerRow, playerCol, playerFuel, enemyRow, enemyCol);
			break;
		case 3 :	// Rendezvous
			board = Rendezvous(board, player, enemy);
			break;
		case 4 :	// Refuel
			board = ReFuel(board, player, enemy);
			break;
		default  :
			break;
	}
	return board;
}


// Roam() currently sends a supply ship straight down and to lower right corner.
// This is temporary code to cause supply ship to do something.

vector<vector<char>> Supply::Roam(vector<vector<char>> board, int playerRow, int playerCol, int playerFuel, int enemyRow, int enemyCol){
	
	if(fuel < REFUELLEVEL){   // Is Supply Ship Fuel Low?
		state = 4;			  // Change state to ReFuel
		return board;
	}

	if(playerFuel < PLAYERREFUELLEVEL) {	// Is Player Fuel low?
		state = 3;							// Change state to Rendezvous
		return board;
	}

	int enemyDistance = ManhattanDistance(enemyRow, enemyCol);
	if(enemyDistance < ENEMYDISTANCE){		// Is distance to Enemy < 10?
		state = 2;							// Change state to Flee
		return board;
	}

	int playerDistance = ManhattanDistance(playerRow, playerCol);
	if(playerDistance < PLAYERDISTANCE){	// Is distance to Player < 5?
		state = 3;							// Change state to Rendezvous
		return board;
	}

	if( (row < BOARDROWS-1) && (board[row+1][col] == '-') ) {
		board[row][col] = '-';
		row++;
		board[row][col] = id;
		SetFuel(fuel-1);
	} else if((col < BOARDCOLS-1) && (board[row][col+1] == '-')) {
		board[row][col] = '-';
		col++;
		board[row][col] = id;
		SetFuel(fuel-1);
	}
	//
	// TODO - Needs to be fully implemented
	//
	return board;
}


// Flee() currently sends a supply ship to a corner.
// This is temporary code to cause supply ship to do something.
vector<vector<char>> Supply::Flee(vector<vector<char>> board, int playerRow, int playerCol, int playerFuel, int enemyRow, int enemyCol){

	int enemyDistance = ManhattanDistance(enemyRow, enemyCol);
	if(enemyDistance >= 10){	// Is distance to Enemy >= 10?
		state = 1;				// Change state to Roam
		return board;
	}

	if(board[0][0] == '-') {
		board[row][col] = '-';
		row = 0;
		col = 0;
		board[row][col]= id;
		state = 1;
		return board;
	}
	if(board[BOARDROWS-1][0] == '-') {
		board[row][col] = '-';
		row = BOARDROWS-1;
		col = 0;
		board[row][col]= id;
		state = 1;
		return board;
	}
	if(board[0][BOARDCOLS-1] == '-') {
		board[row][col] = '-';
		row = 0;
		col = BOARDCOLS-1;
		board[row][col]= id;
		state = 1;
		return board;
	}
	if(board[BOARDROWS-1][BOARDCOLS-1] == '-') {
		board[row][col] = '-';
		row = BOARDROWS-1;
		col = BOARDCOLS-1;
		board[row][col]= id;
		state = 1;
		return board;
	}
	//
	// TODO - Needs to be fully implemented
	//
	return board;
}

vector<vector<char>> Supply::Rendezvous(vector<vector<char>> board, Player player, Enemy enemy){
	//
	// TODO - Needs to be implemented
	//
	return board;
}

// ReFuel() sends a supply ship next to a sun.
// This is temporary code to cause supply ship to do something.
vector<vector<char>> Supply::ReFuel(vector<vector<char>> board, Player player, Enemy enemy){
	board[row][col] = '-';
	row = 6;
	col = 90;
	board[row][col] = id;
	state = 1;
	fuel = 50;
	return board;
}

// Pass row and col of desired character (player or enemy) and get distance to that character.
int Supply::ManhattanDistance(int objRow, int objCol){
	int manDistance = abs(row - objRow)+abs(col - objCol);
	return manDistance;
}

int Supply::GetRow(){
	return row;
}

void Supply::SetRow(int iRow){
	row = iRow;
}

int Supply::GetCol(){
	return col;
}

void Supply::SetCol(int iCol){
	col = iCol;
}

char Supply::GetId(){
	return id;
}

void Supply::SetId(char cId){
	id = cId;
}

int Supply::GetFuel(){
	return fuel;
}

void Supply::SetFuel(int iFuel){
	fuel = iFuel;
}

int Supply::GetState(){
	return state;
}

void Supply::SetState(int iState){
	state = iState;
}