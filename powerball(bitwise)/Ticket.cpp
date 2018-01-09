// COMP-SCI 201L (FS17) - Section 2
// Lab 11 - 11/28/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Ticket.h"

Ticket::Ticket()	//Default Constructor
{
	id = 0;
	fill(whiteballs.begin(), whiteballs.end(), 0);
	redball = 0;
}

Ticket::Ticket(uint64_t data)	//Overloaded Constructor
{
	uint64_t data2 = data;	//make a copy of data to manipulate 
	unsigned int ballNumber = 0;
	for (int i = 0; i < 6; i++)	//Loop for six balls
	{
		ballNumber = data2 & 127;		//Extracting last 7 bits
		if (data2 & 128)						//If the bit number 8 is not 0
			redball = ballNumber;				//that ball is red
		else									//otherwise,
			whiteballs.push_back(ballNumber);	//it is white
		data2 >>= 8;	//Shift the data for new ball
	}
	id = data2;		//the remaining part is the id
}

int Ticket::Prize(const vector<unsigned int>& white, const unsigned int& red, const unsigned int& Grand_Prize)	//Calculating the prize
{
	int whiteMatch = 0, redMatch = red==redball ? 1 : 0;	//Initialize the redMatch variable as 1 if there is a redball otherwise make it 0

	for (unsigned int i = 0; i < white.size(); i++)		//Loops for searching whiteballs
		for (unsigned int j = 0; j < white.size(); j++)
			if (white[i] == whiteballs[j])
				whiteMatch++;

	switch (whiteMatch)		//The calculations according to the red and white ball matches
	{
	case 0:
		return redMatch ? 4 : 0;
	case 1:
		return redMatch ? 4 : 0;
	case 2:
		return redMatch ? 7 : 0;
	case 3:
		return redMatch ? 100 : 7;
	case 4:
		return redMatch ? 50000 : 100;
	case 5:
		return redMatch ? Grand_Prize : 1000000;
	}
}

istream& operator>>(istream &in, Ticket& _ticket)	//Overloaded "<<" operator
{
	uint64_t input;
	in >> input;	//Read the data into a variable
	_ticket = Ticket(input);	//Call the overloaded constructor with the input data
	return in;
}

ostream& operator<<(ostream &out, const Ticket& _ticket)	//Overloaded ">>" operator
{
	if (_ticket.id < 10)	out << 0;	//Putting 0(s) if necessary
	if (_ticket.id < 100)	out << 0;
	if (_ticket.id < 1000)	out << 0;
	if (_ticket.id < 10000)	out << 0;
	out << _ticket.id;	//Writing the id

	return out;
}