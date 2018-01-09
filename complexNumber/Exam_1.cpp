// COMP-SCI 201L (FS17) - Section 2
// Exam 1 - 10/10/17

// Ekrem Kalabak

#include "stdafx.h"
#include "ComplexNumber.h"
#include <fstream>


int main()
{
	//Opening files
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	//Checking the input file
	if (!fin.good()) {
		cout << "Error: the input file does not exist!" << endl;
		system("pause");
		return -1;
	}
	//Declaring two ComplexNumber objects (0+0i) to store the data coming from the file
	ComplexNumber theLeftNumber;
	ComplexNumber theRightNumber;

	while ( fin >> theLeftNumber >> theRightNumber)	//Reading the input file and store the numbers into the objects with the overloaded operators until the end of file
		fout << theLeftNumber + theRightNumber<<", "<<(theLeftNumber+theRightNumber).Magnitute()<<endl;	//Writing to the output file with overloaded operators line by line before reading another line
	
	// Closing files
	fin.close();
	fout.close();

	return 0;
}

