//*************
// BaseShip.h
//*************

#include <vector>
using namespace std;
#pragma once

class BaseShip {
	private:
		int row;
		int col;
		int fuel;
		int state;	
		int id;
		
	public:
		BaseShip(int row, int col, int state, int fuel, char id);
		~BaseShip();
		vector<vector<char>> Update(vector<vector<char>> board, int keyDirection);
		vector<vector<char>> Roam(vector<vector<char>> board);
		void Flee();
		void Rendezvous();
		void ReFuel();
		int GetRow();
		void SetRow(int);
		int GetCol();
		void SetCol(int);
		char GetId();
		void SetId(char);
		int GetFuel();
		void SetFuel(int);
};