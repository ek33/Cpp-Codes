// In this project, it is aimed to show implementations of different searching and sorting algorithms
//In this project dynamic arrays are being used to represent data sets



#include "stdafx.h"
#include "LineerSearch.h"
#include "BinarySearch.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	unsigned int size = 10;	//Size is given as 10, this part can be edited easily

	int* integers;
	integers = new int[size];
	int intKey = 0;
	char* characters;
	characters = new char[size];
	char charKey = ' ';
	int index = 0;

	cout << "Randomly generated integers are:\t";
	for (unsigned int i = 0; i < size; i++)
	{
		int random = rand() % 100;
		integers[i] = random;
		cout << random << ' ';
	}

	cout << "\nRandomly generated characters are:\t";
	for (unsigned int i = 0; i < size; i++)
	{
		char random = (rand() % 26) + 97;
		characters[i] = random;
		cout << random << ' ';
	}

	SelectionSort(integers, size);
	cout << "\n\nIntegers after being sorted with Selection Sort are: \t";
	for (unsigned int i = 0; i < size; i++)
		cout <<  integers[i]<< ' ';

	InsertionSort(characters, size);
	cout << "\nCharacters after being sorted with Insertion Sort are: \t";
	for (unsigned int i = 0; i < size; i++)
		cout << characters[i] << ' ';

	cout << "\n\nEnter an integer value for searching with Lineer Search: ";
	cin >> intKey;
	index = LineerSearch(integers, size, intKey);
	if (index + 1)
		cout << "The value was found at index " << index;
	else
		cout << "Value couldn't be found";

	cout << "\n\nEnter a integer value for searching with Binary Search: ";
	cin >> intKey;
	index = BinarySearch(integers, 0, size-1, intKey);
	if (index + 1)
		cout << "The value was found at index " << index;
	else
		cout << "Value couldn't be found";

	cout << "\n\nEnter a caharacter (a-z) for searching with Lineer Search: ";
	cin >> charKey;
	index = LineerSearch(characters, size, charKey);
	if (index + 1)
		cout << "The value was found at index " << index;
	else
		cout << "Value couldn't be found";

	cout << "\n\nEnter a caharacter (a-z) for searching with Binary Search: ";
	cin >> charKey;
	index = BinarySearch(characters, 0, size - 1, charKey);
	if (index + 1)
		cout << "The value was found at index " << index << endl << endl;
	else
		cout << "Value couldn't be found\n\n";

    return 0;
}

