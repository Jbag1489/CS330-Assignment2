//*************
// AIBoard.h
//*************

#include <vector>
#include "Supply.h"
#include "Player.h"
#pragma once
using namespace std;

class AIBoard {
	private:
		int gridRows;
		int gridColumns;
		
	public:
		AIBoard(int rows,int cols);
		~AIBoard();
		int getGridRows();
		int getGridColumns();
		vector<vector<char>> BuildBoard();
		void DisplayHeader(vector<Supply> supply, Player player);
		void DisplayBoard(vector<vector<char>>);
		void MaximizeOutputWindow(void);
		void SetColor(int);
};