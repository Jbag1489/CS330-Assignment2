//*************
// Cell.h
//*************

#pragma once

class Cell {
	private:
		int row;
		int col;
		
	public:
		Cell(int, int);
		~Cell();
		void SetRow(int);
		void SetCol(int);
		int GetRow();
		int GetCol();
};