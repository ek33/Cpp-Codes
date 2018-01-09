//Ekrem Kalabak

#include "stdafx.h"
#include "User.h"
#include <iostream>

bool User::ResizeArray()
{
	if (ArraySize == 0)		//If the capacity is 0, make it 1 and finish the function
	{
		ArraySize=5;
		Books = new string[ArraySize];
		return true;
	}
	ArraySize *= 2;		//If the capacity is not 0, double it
	string* temp = new string[ArraySize];	//Create new dynamic array and fill it up with the original values
	for (unsigned int i = 0; i < BookNumber; i++)
		temp[i] = Books[i];
	delete[] Books;					//Delete the old array
	Books = temp;						//Make pointer point to the new array}
	return true;
}

User::User()
{
	FirstName = LastName = "";
	ID = 0;
}

User::User(unsigned int id, string name, string lastname)
{
	FirstName = name;
	LastName = lastname;
	ID = id;
}

User::User(const User& other)
{
	Books = nullptr;
	*this = other;
}

const User& User::operator=(const User& rhs)
{
	if (&rhs != this)	//Step 1-Avoid self assignment
	{
		if (Books != nullptr)	//Step 2-Release memory
		{
			delete[] Books;
			Books = nullptr;
		}
		//Step 3-Copy static data
		FirstName = rhs.FirstName;
		LastName = rhs.LastName;
		ID = rhs.ID;
		BookNumber = rhs.BookNumber;
		ArraySize = rhs.ArraySize;

		//Step 4-Copy dynamic data
		if (ArraySize > 0)
		{
			Books = new string[ArraySize];
			for (unsigned int i = 0; i<BookNumber; i++)
				Books[i] = rhs.Books[i];
		}
	}
	return *this;	//Step 5-return
}

int User::GetIDNumber() const
{
	return ID;
}

string User::GetFirstName() const
{
	return FirstName;
}

string User::GetLastName() const
{
	return LastName;
}

string User::GetFullName() const
{
	string fullname = FirstName;
	fullname += ' ';
	fullname += LastName;
	return fullname;
}

void User::SetIDNumber(int NewNumber)
{
	if(NewNumber>=100 && NewNumber<1000000)
		ID = NewNumber;
	return;
}

void User::SetFirstName(string newName)
{
	FirstName = newName;
}

void User::SetLastName(string newLastName)
{
	LastName = newLastName;
}

int User::CheckoutCount() const
{
	return BookNumber;
}

bool User::CheckOut(const string& BookIDCode)
{
	if (BookNumber >= ArraySize)
		if (!(ResizeArray()))
			return false;

	for (unsigned int i = 0; i < BookNumber; i++)
		if (Books[i] == BookIDCode)
		{
			cerr << "User IDNum has already checked out item " << BookIDCode << endl;
			return false;
		}

	Books[BookNumber] = BookIDCode;
	BookNumber++;
	return true;
}

bool User::CheckIn(const string& BookIDCode)
{
	unsigned int i = 0;
	for ( ; i < BookNumber; i++)
		if (Books[i] == BookIDCode)
			if (BookNumber == 1)
			{
				BookNumber--;
				delete[] Books;
				Books = nullptr;
				return true;
			}
			else
			{
				for (; i < BookNumber - 1; i++)
					Books[i] = Books[i + 1];
				BookNumber--;
				return true;
			}
	return false;
}

bool User::HasCheckedOut(const string& BookIDCode) const
{
	for (unsigned int i = 0; i < BookNumber; i++)
		if (Books[i] == BookIDCode)
			return true;
	return false;
}

void User::Clear()
{
	ID = 0;
	FirstName = LastName = ""; 
	ArraySize = 0;
	if (BookNumber == 0)
		delete[] Books;
	Books = nullptr;
	BookNumber = 0;
}

User::~User()
{
	Clear();
}

istream& operator >> (istream& in, User& item)
{
	item.Clear();
	string temp = "";
	int tempNum=0;

	in >> item.ID >> item.FirstName >> item.LastName >> tempNum;
	
	for (unsigned int i = 0; i < tempNum; i++)
	{
		in >> temp;
		item += temp;

	}
	return in;
}

ostream& operator << (ostream &out,const User& item)
{
	out << item.ID << ' ' << item.GetFullName() << endl << item.BookNumber << endl;
	for (unsigned int i = 0; i < item.BookNumber; i++)
		out <<  item.Books[i] << ' ' ;
	if (item.BookNumber != 0)
		out << endl;
	return out;
}

const User operator+(User& item, const string theBook)
{
	item.CheckOut(theBook);
	return item;
}

const void operator+=(User& item, const string theBook)
{
	item.CheckOut(theBook);
}

const bool User::operator==(const User& rhs)
{
	if (ID == rhs.ID)
		return true;
	return false;
}

const bool User::operator!=(const User& rhs)
{
	if (!(ID == rhs.ID))
		return true;
	return false;
}