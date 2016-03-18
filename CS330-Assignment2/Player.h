//**********
// Player.h
//**********

#pragma once
#include <vector>
using namespace std;

class Player {
	private:
		int row;
		int col;
		int state;
		int fuel;
		int id;
		
	public:
		Player(int row, int col, int state, int fuel, char id);
		~Player();
		vector<vector<char>> Update(vector<vector<char>> board, int keyDirection);
		int GetFuel();
		void SetFuel(int);
		int GetColor();
		int GetRow();
		int GetCol();
};