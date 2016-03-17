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

vector<vector<char>> Supply::Update(vector<vector<char>> board) {
	switch(state) {
		case 1 :	// Roam
			board = Roam(board);
			break;
		case 2 :	// Flee
			board = Flee(board);
			break;
		case 3 :	// Rendezvous
			board = Rendezvous(board);
			break;
		case 4 :	// Refuel
			board = ReFuel(board);
			break;
		default  :
			break;
	}
	return board;
}


// Roam() currently sends a supply ship straight down and to lower right corner.
// This is temporary code to cause supply ship to do something.

vector<vector<char>> Supply::Roam(vector<vector<char>> board){
	if(fuel < REFUELLEVEL){   // Is Fuel Low?
		state = 4;			  // Change state to ReFuel
		return board;
	}
	int distance = ManhattanDistance(board, 'E');
	if(distance < 10){  // Is distance to Enemy < 10?
		state = 2;		// Change state to Flee
		return board;
	}
	distance = ManhattanDistance(board, 'P');
	if(distance < 5){   // Is distance to Player < 5?
		state = 3;		// Change state to Rendezvous
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

vector<vector<char>> Supply::Flee(vector<vector<char>> board){
	if(board[0][0] == '-') {
		board[row][col] = '-';
		row = 0;
		col = 0;
		board[row][col]= id;
		state = 1;
		return board;
	}
	else if(board[BOARDROWS-1][0] == '-') {
		board[row][col] = '-';
		row = BOARDROWS-1;
		col = 0;
		board[row][col]= id;
		state = 1;
		return board;
	}
	else if(board[0][BOARDCOLS-1] == '-') {
		board[row][col] = '-';
		row = 0;
		col = BOARDCOLS-1;
		board[row][col]= id;
		state = 1;
		return board;
	}
	else if(board[BOARDROWS-1][BOARDCOLS-1] == '-') {
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

vector<vector<char>> Supply::Rendezvous(vector<vector<char>> board){
	//
	// TODO - Needs to be implemented
	//
	return board;
}

// Roam() just sends a supply ship next to a sun.
// This is temporary code to cause supply ship to do something.

vector<vector<char>> Supply::ReFuel(vector<vector<char>> board){
	board[row][col] = '-';
	row = 6;
	col = 90;
	board[row][col] = id;
	state = 1;
	fuel = 50;
	return board;
}

// Pass board and code of character searching for to get distance.
int Supply::ManhattanDistance(vector<vector<char>> board, char ch){
	int manDistance = 0;
	for(int rows = 0; rows < BOARDROWS - 1; rows++) {
		for(int columns = 0; columns < BOARDCOLS - 1; columns++) {
			if(board[rows][columns] == ch){
				manDistance = abs(row-rows)+abs(col-columns);
				return manDistance;
			}
		}
	}
}

int Supply::UpdateState(vector<vector<char>> board){
	// If enemy within 5 units, flee from enemy.
	if (ManhattanDistance(board, 'E') <= 5) {
		state = 2;
	}

	// If fuel low, enter refuel state.
	else if(fuel < 10){
		state = 4;
	}

	else if(ManhattanDistance(board, 'P') <= 10){
		state = 3;
	}

	// If all other states not true, roam
	else{
		state = 1;
	}
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