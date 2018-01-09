// COMP-SCI 201L (FS17) - Section 2
// Lab 7 - 10/24/17

// Ekrem Kalabak

#ifndef HEXADECIMAL_NUMBER_H
#define HEXADECIMAL_NUMBER_H

#include "Natural_Number.h"


class Hexadecimal_Number : public Natural_Number
{
private:
	int decimal_value = 0;
	int get_decimal_value() const;
public:
	//Signatures of the virtual functions
	Hexadecimal_Number(const string&);
	string to_binary() const;
	string to_octal() const;
	string to_decimal() const;
	string to_hexadecimal() const;
};

#endif