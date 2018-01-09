// COMP-SCI 201L - Section 2
// Lab 9 (11/07/17)

// Ekrem Kalabak

#include "stdafx.h"
#include "Sort.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
	// Input text file which contains the filenames of all input image files.
	ifstream fin("input_filenames.txt");
	ofstream fout("output.ppm");
	if (!fin.good()) {
		cout << "Error: input text file does not exist." << endl;
		system("pause");
		return -1;
	}

	/** Write some code to complete the following.
	1. Based on how many input image files, create the same number of ifstream(s), one for an image.
	2. Jump all the title information for all the input image files.
	3. Add the title information to you final output PPM file.
	4. In each iteration, read the color values from all image files and save in an array (vector).
	5. Sort the vector and get the median.  Write the median into your output PPM file.
	6. After finish everything, close all the input and output files.
	*/
	vector <ifstream> files(0);
	string inputFiles = "", magicConstant = "", width = "", height = "", colorRange = "", pixelData = "";

	while (fin >> inputFiles)
		files.push_back(ifstream(inputFiles));

	vector <int> img(files.size());

	for (unsigned int i = 0; i < files.size(); i++)
		files[i] >> magicConstant >> width >> height >> colorRange;
	fout << magicConstant << endl << width << ' ' << height << endl << colorRange << endl;

	for (int i = 0; i < (stoi(width)*stoi(height) * 3); i++)
	{
		for (unsigned int j = 0; j < files.size(); j++)
		{
			files[j] >> pixelData;
			img[j] = stoi(pixelData);
		}
		Sort(img);
		fout << Median(img) << endl;
	}	
		
	fin.close();
	fout.close();
	for (unsigned int i = 0; i < files.size(); i++)
		files[i].close();

	// End the program.
	return 0;
}