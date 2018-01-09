// COMP-SCI 201L (FS17) - Section 2
// Lab 3 - 09/19/17

// Ekrem Kalabak

#include "stdafx.h"
#include "CaesarCipher.h"
#include <fstream>
#include <iostream>

int main() {
	// File streams
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int counter = 0;

	if (!fin.good()) {
		cout << "Error: file \"input.txt\" does not exist!" << endl;
		return -1;
	}
	
	string original[20], encrypted[20], decrypted[20];
	CaesarCipher en_de_cryption;

	// Read the sentences from the input file and save to original[20].
	for (counter = 0; getline(fin, original[counter]); counter++)
	{
		// Encrypt the sentences and save to encrypted[20].
		encrypted[counter] = en_de_cryption.Encode(original[counter]);

		// Decrypt the sentences and save to decrypted[20].
		decrypted[counter] = en_de_cryption.Decode(encrypted[counter]);
	}
	// Output 
	fout << "Encrypted sentences :" << endl;
	for (int i = 0; i < counter; i++)
		fout << encrypted[i] << endl;

	fout << endl << "Decrypted sentences :" << endl;
	for (int i = 0; i < counter; i++)
		fout << decrypted[i] << endl;


	// Close the files and end the program.
	fin.close();
	fout.close();

	return 0;
}