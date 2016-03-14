//************
//  Cell.cpp
//************

#include "Cell.h"

Cell::Cell(int iRow, int iCol){
	row = iRow;
	col = iCol;
}

Cell::~Cell(){
}

void Cell::SetRow(int iRow){
	row = iRow;
}

void Cell::SetCol(int iCol){
	col = iCol;
}

int Cell::GetRow(){
	return row;
}

int Cell::GetCol(){
	return col;
}
