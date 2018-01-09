// COMP-SCI 201L (FS17) - Section 2
// Lab 7 - 10/24/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Binary_Number.h"
#include "Decimal_Number.h"
#include "Hexadecimal_Number.h"
#include "Octal_Number.h"
#include <fstream>
#include <iostream>

int main() {
	// Input and output file streams
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	if (!fin.good()) {
		cout << "Error: input file does not exist." << endl;
		system("pause");
		return -1;
	}

	// The code reads in numbers (the type is specified in each line of the input file)
	// one-by-one from the input file, then output its binary, octal, decimal, and hexadecimal
	// formats to the output file.

	string type = "", expression = "";
	Natural_Number* p = nullptr;

	while (fin >> type >> expression)
	{

		//Create a new object with respect to type and make p point to it
		if (type == "Dec")
			p = new Decimal_Number(expression);
		else if (type == "Bin")
			p = new Binary_Number(expression);
		else if(type == "Oct")
			p = new Octal_Number(expression);
		else if(type == "Hex")
			p = new Hexadecimal_Number(expression);

		//Write the numbers in output file in a proper format
		fout << p->to_binary() << ' ';
		fout << p->to_octal() << ' ';
		fout << p->to_decimal() << ' ';
		fout << p->to_hexadecimal() << endl;

		delete p;
		p = nullptr;
	}

	// Close the files and end the program.
	fin.close();
	fout.close();
	return 0;
}