// COMP-SCI 201L (FS17) - Section 2
// Lab 11 - 11/28/17

// Ekrem Kalabak

#ifndef TICKET_H
#define TICKET_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Ticket {
public:
	Ticket();	//Default Constructor
	Ticket(uint64_t);	//Overloaded Constructor
	int Prize(const vector<unsigned int>&, const unsigned int&, const unsigned int&);	//Function for prize calculation
	friend istream& operator>>(istream &, Ticket&);	//Overloaded ">>" operator
	friend ostream& operator<<(ostream &, const Ticket&);	//Overloaded ">>" operator

private:
	unsigned int id;	//variable for id
	vector<unsigned int> whiteballs;	//vector of numbers of whiteballs
	unsigned int redball;	//number of the redball if it exists
};

#endif