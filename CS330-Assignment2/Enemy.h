//**********
// Enemy.h
//**********

#pragma once
#include <vector>
using namespace std;

class Enemy {
	private:
		int row;
		int col;
		int state;
		int id;
		
	public:
		Enemy(int row, int col, int state, char id);
		~Enemy();
		vector<vector<char>> Update(vector<vector<char>> board);
		vector<vector<char>> Roam(vector<vector<char>> board);
		vector<vector<char>> Attack(vector<vector<char>> board);
		int GetRow();
		int GetCol();
		char GetId();
		void SetId(char);
};