//**************
//  Player.cpp
//**************

#include "Player.h"
#include "Definitions.h"
using namespace std;

Player::Player(int iRow, int iCol, int iState, int iFuel, char cId){
	row = iRow;
	col = iCol;
	state = iState;	// Not used yet by Player character
	fuel = iFuel;
	id = cId;
}

Player::~Player(){
}

vector<vector<char>> Player::Update(vector<vector<char>> board, int keyDirection){
	if(fuel <= 10){
		return board;
	}
	switch(keyDirection){
		case 52 :	// Go left
		case 75 :
			if((col > 0) && (board[row][col-1] == '-')){
				board[row][col] = '-';
				col--;
				board[row][col] = id;
				SetFuel(fuel-1);
			}
			break;
		case 54 :	// Go Right
		case 77 :
			if((col < BOARDCOLS-1) && (board[row][col+1] == '-')){
				board[row][col] = '-';
				col++;
				board[row][col] = id;
				SetFuel(fuel-1);
			}
			break;
		case 56 :	// Go Up
		case 72 :
			if((row > 0) && (board[row-1][col] == '-')){
				board[row][col] = '-';
				row--;
				board[row][col] = id;
				SetFuel(fuel-1);
			}
			break;
		case 50 :	// Go Down
		case 80 :
			if((row < BOARDROWS-1) && (board[row+1][col] == '-')){
				board[row][col] = '-';
				row++;
				board[row][col] = id;
				SetFuel(fuel-1);
			}
			break;
		default :
			board[row][col] = id;
			break;
	}
	return board;
}

int Player::GetFuel(){
	return fuel;
}

void Player::SetFuel(int iFuel){
	fuel = iFuel;
}

int Player::GetRow(){
	return row;
}

int Player::GetCol(){
	return col;
}

