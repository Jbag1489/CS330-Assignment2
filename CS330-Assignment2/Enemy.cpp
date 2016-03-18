//**************
//  Enemy.cpp
//**************

#include "Enemy.h"
#include <iostream>
#include "Definitions.h"
#include <string>

using namespace std;

Enemy::Enemy(int iRow, int iCol, int iState, char cId){
	row = iRow;
	col = iCol;
	state = iState;
	id = cId;
}

Enemy::~Enemy(){
}

vector<vector<char>> Enemy::Update(vector<vector<char>> board) {
	switch(state) {
		case 1 :	// Roam
			board = Roam(board);
			break;
		case 2 :	// Attack
			board = Attack(board);
			break;
		default  :	
			break;			
	}
	return board;
}

vector<vector<char>> Enemy::Roam(vector<vector<char>> board){
	if((row < BOARDROWS-1) && (board[row+1][col] = '-')) {
		board[row][col] = '-';
		row++;
		board[row][col] = id;
	}
	if((col > 0) && (board[row][col-1] = '-')) {
		board[row][col] = '-';
		col--;
		board[row][col] = id;
	}
	return board;
}

vector<vector<char>> Enemy::Attack(vector<vector<char>> board){
	//
	// TODO - Needs to be implemented
	//
	return board;
}

int Enemy::GetRow(){
	return row;
}

int Enemy::GetCol(){
	return col;
}

char Enemy::GetId(){
	return id;
}

void Enemy::SetId(char cId){
	id = cId;
}