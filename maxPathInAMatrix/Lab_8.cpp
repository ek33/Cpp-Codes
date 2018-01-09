// COMP-SCI 201L (FS17) - Section 2
// Lab 8 - 10/31/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Grid.h"
#include <ctime>
#include <fstream>

int main() {
	ifstream fin("input3.txt");  // You can change the input file name here.

	if (!fin.good()) {
		cout << "Error: input file does not exist." << endl;
		system("pause");
		return -1;
	}

	Grid G;
	fin >> G;
	fin.close();
	time_t t = time(0);

	cout << "MaxReward = " << G.MaxReward(G.numOfRows()-1, G.numOfCols()-1) << endl;

	cout << "Calculation Time = " << time(0) - t << " seconds" << endl;
	system("pause");
	return 0;
}