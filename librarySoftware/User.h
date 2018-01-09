//Ekrem Kalabak

#ifndef USER_H
#define USER_H

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class User {
private:
	string FirstName, LastName, *Books;
	unsigned int ID, BookNumber, ArraySize;
	bool ResizeArray();
public:
	User();
	User(unsigned int, string, string);
	User(const User&);
	const User& operator=(const User&);
	int GetIDNumber() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetFullName() const;
	void SetIDNumber(int);
	void SetFirstName(string);
	void SetLastName(string);
	int CheckoutCount() const;
	bool CheckOut(const string&);
	bool CheckIn(const string&);
	bool HasCheckedOut(const string&) const;
	void Clear();
	~User();

	friend istream& operator >> (istream&, User&);
	friend ostream& operator<<(ostream&, const User&);
	const friend User operator+(User&, const string);
	const friend void operator+=(User&, const string);

	const bool operator==(const User&);
	const bool operator!=(const User&);
};

#endif