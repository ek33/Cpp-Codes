// COMP-SCI 201L (FS17) - Section 2
// Lab 7 - 10/24/17

// Ekrem Kalabak

#ifndef BINARY_NUMBER_H
#define BINARY_NUMBER_H

#include "Natural_Number.h"

// child class Binary_Number 
class Binary_Number : public Natural_Number
{
private:
	int decimal_value = 0;
	int get_decimal_value() const;
public:
	//Signatures of the virtual functions
	Binary_Number(const string&);
	string to_binary() const;
	string to_octal() const;
	string to_decimal() const;
	string to_hexadecimal() const;
};

#endif