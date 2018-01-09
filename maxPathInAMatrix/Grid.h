// COMP-SCI 201L (FS17) - Section 2
// Lab 8 - 10/31/17

// Ekrem Kalabak

#ifndef GRID_H
#define GRID_H

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Grid {
public:
	int MaxReward(unsigned int, unsigned int);		//	The first parameter is for number of rows, the second one is for number of columns,
													//	and the type is unsigned int since rows and columns are also unsigned int

	unsigned int numOfRows() const { return G.size(); }
	unsigned int numOfCols() const { return G.size() == 0 ? 0 : G[0].size(); }
private:
	vector<vector<unsigned int>> G;
	friend istream& operator>>(istream& in, Grid& M);
};

#endif