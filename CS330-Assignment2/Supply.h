//***********
// Supply.h
//***********

#include <vector>
#include "Player.h"
#include "Enemy.h"
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
		vector<vector<char>> Update(vector<vector<char>> board, Player player, Enemy enemy);
		vector<vector<char>> Roam(vector<vector<char>> board, int playerRow, int PlayerCol, int playerFuel, int EnemyRow, int EnemyCol);
		vector<vector<char>> Flee(vector<vector<char>> board, int playerRow, int PlayerCol, int playerFuel, int EnemyRow, int EnemyCol);
		vector<vector<char>> Rendezvous(vector<vector<char>> board, Player player, Enemy enemy);
		vector<vector<char>> ReFuel(vector<vector<char>> board, Player player, Enemy enemy);
		int ManhattanDistance(int row, int col);
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