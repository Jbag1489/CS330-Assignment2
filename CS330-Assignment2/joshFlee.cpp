/*

// NOTE: THIS CODE IS NOT USED - stored for if I need to go back to this implementation

	// Enemy col and row both positive relative to supply ship
	if(enemyCol > col && enemyRow > row){
		if(board[row-1][col-1] == '-') {
			board[row][col] = '-';
			row = row-1;
			col = col-1;
			board[row][col]= id;
			UpdateState(board);
			return board;
		}
	}

	// Enemy col and row both negative relative to supply ship
	if(enemyCol < col && enemyRow < row){
		if(board[row+1][col+1] == '-') {
			board[row][col] = '-';
			row = row+1;
			col = col+1;
			board[row][col]= id;
			UpdateState(board);
			return board;
		}
	}
	
	// Enemy col is positive, row is negative relative to supply ship
	if(enemyCol > col && enemyRow < row){
		if(board[row-1][col+1] == '-') {
			board[row][col] = '-';
			row = row-1;
			col = col+1;
			board[row][col]= id;
			UpdateState(board);
			return board;
		}
	}
	
	// Enemy col is negative, row is positive relative to supply ship
	if(enemyCol < col && enemyRow > row){
		if(board[row+1][col-1] == '-') {
			board[row][col] = '-';
			row = row+1;
			col = col-1;
			board[row][col]= id;
			UpdateState(board);
			return board;
		}
	}

	// Enemy in same row
	if(enemyRow = row){
		// Enemy col > col
		if(enemyCol > col){
			
		}

		// Enemy col < col
		if(enemyCol < col){
			
		}
	}


	// Enemy in same column
	if(enemyCol = col){
		// Enemy row > row
		if(enemyRow > row){
			
		}

		// Enemy row < row
		if(enemyRow < row){
			
		}
	}


*/