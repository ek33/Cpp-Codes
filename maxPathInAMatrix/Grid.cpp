// COMP-SCI 201L (FS17) - Section 2
// Lab 8 - 10/31/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Grid.h"


int Grid::MaxReward(unsigned int row, unsigned int column)
{
	if (row == 0 && column == 0)	//Base Case (At the top left corner, there is nowhere to go )
		return G[row][column];
	else if (row == 0)				//Subproblem (At the top lane, it can only go horizontal)
		return (MaxReward(row, column - 1) + G[row][column]);
	else if (column == 0)			//Subproblem (At the very left lane, it can only go vertical)
		return (MaxReward(row - 1, column) + G[row][column]);
	else							//The recursive part
		return (MaxReward(row - 1, column) < MaxReward(row, column - 1)) ? MaxReward(row, column - 1) + G[row][column] : MaxReward(row - 1, column) + G[row][column];//This lane means, return max(MaxReward(row, column - 1) , MaxReward(row - 1, column))+ G[row][column];
}

istream& operator>>(istream& in, Grid& M) {
	unsigned int m, n;
	in >> m >> n;
	M.G = vector<vector<unsigned int>>(m, vector<unsigned int>(n));
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = 0; j < n; j++)
			in >> M.G[i][j];
	return in;
}