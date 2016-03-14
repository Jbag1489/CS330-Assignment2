//***************
//  BaseShip.cpp
//***************

#include "BaseShip.h"
using namespace std;

BaseShip::BaseShip(int iRow, int iCol, int iState, int iFuel, char cId){
	row = iRow;
	col = iCol;
	state = iState;
	fuel = iFuel;
	id = cId;
}

BaseShip::~BaseShip(){
}

vector<vector<char>> BaseShip::Update(vector<vector<char>> board, int keyDirection){
	return board;
}

void BaseShip::Flee(){
}

void BaseShip::Rendezvous(){
}

void BaseShip::ReFuel(){
}

int BaseShip::GetRow(){
	return row;
}

void BaseShip::SetRow(int){
}

int BaseShip::GetCol(){
	return col;
}

void BaseShip::SetCol(int){
}

char BaseShip::GetId(){
	return id;
}

void BaseShip::SetId(char){
}

int BaseShip::GetFuel(){
	return fuel;
}

void BaseShip::SetFuel(int iFuel){
	fuel = iFuel;
}