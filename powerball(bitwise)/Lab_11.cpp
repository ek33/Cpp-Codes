// COMP-SCI 201L (FS17) - Section 2
// Lab 11 - 11/28/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Ticket.h"
#include <fstream>

// Winning numbers as global constants.
const vector<unsigned int> WHITE = { 9, 14, 27, 35, 44 };
const unsigned int RED = 13;
const unsigned int GRAND_PRIZE = 163000000;  // 163 Million.

int main() {
	// Input and output file streams.
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	if (!fin.good()) {
		cout << "Error: input file does not exist." << endl;
		system("pause");
		return -1;
	}

	Ticket theTicket;	//Creating an object of "Ticket" class
	while (fin >> theTicket)	//Reading the file and storing the data into the object with the overloaded ">>" operator until the end of file
		fout << theTicket << " $" << theTicket.Prize(WHITE,RED,GRAND_PRIZE) << endl; //Generating output in the correct format with the overloaded "<<" operator


	// Close the files and end the program.
	fin.close();
	fout.close();
	return 0;
}