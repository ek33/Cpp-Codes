// COMP-SCI 201L (FS17) - Section 2
// Lab 7 - 10/24/17

// Ekrem Kalabak

#include "stdafx.h"
#include "Hexadecimal_Number.h"

// member functions of class Hexadecimal_Number

int Hexadecimal_Number::get_decimal_value() const
{
	return decimal_value;
}

Hexadecimal_Number::Hexadecimal_Number(const string& exp = "") : Natural_Number(exp)
{
	decimal_value = stoi(get_expression(), NULL, 16);	//Initialize the decimal value when constructor is called
}

string Hexadecimal_Number::to_binary() const		//Binary-string conversation
{
	string str;
	int n = get_decimal_value();
	while (n != 0)
	{
		str = (char)(n % 2 + 48) + str;
		n /= 2;
	}
	return str;
}

string Hexadecimal_Number::to_octal() const		//Octal-string conversation
{
	stringstream ss;
	ss << oct << get_decimal_value();
	return ss.str();
}

string Hexadecimal_Number::to_decimal() const		//String conversation
{
	stringstream ss;
	ss << get_decimal_value();
	return ss.str();
}

string Hexadecimal_Number::to_hexadecimal() const		//Hexadecimal string conversation
{
	stringstream ss;
	ss << hex << get_decimal_value();
	return ss.str();
}