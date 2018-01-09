//Ekrem Kalabak

#include "stdafx.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin1("users.txt");
	ifstream fin2("checkouts.txt");
	ifstream fin3("checkins.txt");
	ofstream fout("updated_Users.txt");

	if (!fin1.good() || !fin2.good() || !fin3.good()) {
		cout << "Error: input file does not exist!" << endl;
		system("pause");
		return -1;
	}
	string temp = "", tempBook;
	int userNumber = 0, counter = 0, tempID=0;
	while (fin1 >> temp >> temp >> temp >> counter)	//Reading data from "fin1" until the end of file
		for (userNumber++; counter > 0; counter--)
			getline(fin1, temp);
	
	fin1.clear();
	fin1.seekg(0, std::ios::beg);
	
	User* UserArray;
	UserArray = new User[userNumber];
	for (int i = 0; i < userNumber; ++i)
		fin1>>UserArray[i];

	while ( fin2 >> tempID >> tempBook)	//Reading data from "fin2" until the end of file
		for (int i = 0; i < userNumber; i++)
			if (UserArray[i].GetIDNumber() == tempID)
			{
				UserArray[i].CheckOut(tempBook);
				break;
			}
			else if (i == userNumber - 1)
				cerr << "No user can be found with this ID number: " << tempID<<endl;

	while ( fin3 >> tempBook)	//Reading data from "fin2" until the end of file
		for (int i = 0; i < userNumber; i++)
			if (UserArray[i].HasCheckedOut(tempBook) == 1)
			{
				UserArray[i].CheckIn(tempBook);
				break;
			}
			else if (i == userNumber - 1)
				cerr << "No user can be found with this item checked out: " << tempBook<<endl;

	for (int i = 0; i < userNumber; ++i)
		fout << UserArray[i];

	for (unsigned int i = 0; i < userNumber; i++)
		UserArray[i].Clear();

	fin1.close();
	fin2.close();
	fin3.close();
	fout.close();

    return 0;
}