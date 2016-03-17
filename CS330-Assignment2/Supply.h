//***********
// Supply.h
//***********

#include <vector>
using namespace std;
#pragma once

class Supply {
	private:
		int row;
		int col;
		int fuel;
		int state;	
		int id;
		
	public:
		Supply(int row, int col, int state, int fuel, char id);
		~Supply();
		vector<vector<char>> Update(vector<vector<char>> board);
		vector<vector<char>> Roam(vector<vector<char>> board);
		vector<vector<char>> Flee(vector<vector<char>> board);
		vector<vector<char>> Rendezvous(vector<vector<char>> board);
		vector<vector<char>> ReFuel(vector<vector<char>> board);
		int ManhattanDistance(vector<vector<char>> board, char ch);
		void UpdateState(vector<vector<char>> board);
		int GetRow();
		void SetRow(int);
		int GetCol();
		void SetCol(int);
		char GetId();
		void SetId(char);
		int GetFuel();
		void SetFuel(int);
		int GetState();
		void SetState(int);
};