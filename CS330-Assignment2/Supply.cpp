//**************
//  Supply.cpp
//**************

#include "Supply.h"
#include "Definitions.h"
#include <cmath>
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
/*
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

*/
	//
	// TODO - Needs to be fully implemented
	//
	////////////////////////////////////////////////////////////////
	// Diagonal movements - decided to allow supply ships to move diagonally

// Find distance to enemy in each possible movement location
		
	double enemyDistances[8];
	double bestMoveDistance = -100;
	int whereToMove = -1; // Integer to hold direction to move for greatest distance from enemy
		
//UP = 0
	if (row == 0){
		// Space does not exist on board
		enemyDistances[0] = -1;
	}
	else if(board[row-1][col] = '-'){
		enemyDistances[0] = EuclidDistance(row-1, col, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[0] = -1;
	}

//UPRIGHT = 1
	if (row == 0 || col == BOARDCOLS-1){
		// Space does not exist on board
		enemyDistances[1] = -1;
	}
	else if(board[row-1][col+1] = '-'){
		enemyDistances[1] = EuclidDistance(row-1, col+1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[1] = -1;
	}

//RIGHT = 2
	if (col == BOARDCOLS-1){
		// Space does not exist on board
		enemyDistances[2] = -1;
	}
	else if(board[row][col+1] = '-'){
		enemyDistances[2] = EuclidDistance(row, col+1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[2] = -1;
	}

//DOWNRIGHT = 3
	if (row == BOARDROWS-1 || col == BOARDCOLS-1){
		// Space does not exist on board
		enemyDistances[3] = -1;
	}
	else if(board[row+1][col+1] = '-'){
		enemyDistances[3] = EuclidDistance(row+1, col+1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[3] = -1;
	}

//DOWN = 4
	if (row == BOARDROWS-1){
		// Space does not exist on board
		enemyDistances[4] = -1;
	}
	else if(board[row+1][col] = '-'){
		enemyDistances[4] = EuclidDistance(row+1, col, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[4] = -1;
	}

//DOWNLEFT = 5
	if (row == BOARDROWS-1 || col == 0){
		// Space does not exist on board
		enemyDistances[5] = -1;
	}
	else if(board[row+1][col-1] = '-'){
		enemyDistances[5] = EuclidDistance(row+1, col-1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[5] = -1;
	}

//LEFT = 6
	if (col == 0){
		// Space does not exist on board
		enemyDistances[6] = -1;
	}
	else if(board[row][col-1] = '-'){
		enemyDistances[6] = EuclidDistance(row, col-1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[6] = -1;
	}

//UPLEFT = 7
	if (row == 0 || col == 0){
		// Space does not exist on board
		enemyDistances[7] = -1;
	}
	else if(board[row-1][col-1] = '-'){
		enemyDistances[7] = EuclidDistance(row-1, col-1, enemyRow, enemyCol);
	}
	else{
		//Not an available space to move
		enemyDistances[0] = -1;
	}

//Find greatest distance
	for(int i=0; i < 8; i++){
		if (enemyDistances[i] > bestMoveDistance){
			whereToMove = i;
			bestMoveDistance = enemyDistances[i];
		}
	}

	switch (whereToMove){
	case 0:
		board[row][col] = '-';
		row = row-1;
		col = col;
		board[row][col]= id;
		break;
	case 1:
		board[row][col] = '-';
		row = row-1;
		col = col+1;
		board[row][col]= id;
		break;
	case 2:
		board[row][col] = '-';
		row = row;
		col = col+1;
		board[row][col]= id;
		break;
	case 3:
		board[row][col] = '-';
		row = row+1;
		col = col+1;
		board[row][col]= id;
		break;
	case 4:
		board[row][col] = '-';
		row = row+1;
		col = col;
		board[row][col]= id;
		break;
	case 5:
		board[row][col] = '-';
		row = row+1;
		col = col-1;
		board[row][col]= id;
		break;
	case 6:
		board[row][col] = '-';
		row = row;
		col = col-1;
		board[row][col]= id;
		break;
	case 7:
		board[row][col] = '-';
		row = row-1;
		col = col-1;
		board[row][col]= id;
		break;
	default: // No movement made
		row = row;
		col = col;
	}
	
	// Update to new correct state
	UpdateState(board, playerRow, playerCol,playerFuel, enemyRow, enemyCol);
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

double Supply::EuclidDistance(int tempRow, int tempCol, int objRow, int objCol){
	
	double row = (tempRow - objRow);
	double col = (tempCol - objCol);

	double distance = sqrt( (row*row) + (col*col) );
	return distance;
}

void Supply::UpdateState(vector<vector<char>> board, int playerRow, int playerCol, int playerFuel, int enemyRow, int enemyCol){
	// If enemy within 10 units, flee from enemy.
	if (ManhattanDistance(enemyRow, enemyCol) <= 10) {
		state = 2;
	}

	// If fuel low, enter refuel state.
	else if(fuel < 10){
		state = 4;
	}

	// If player close and fuel low, rendezvous with player
	else if( (ManhattanDistance(playerRow, playerCol) <= 10) && (playerFuel < 40) ){
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