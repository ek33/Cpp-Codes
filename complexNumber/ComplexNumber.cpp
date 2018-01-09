// COMP-SCI 201L (FS17) - Section 2
// Exam 1 - 10/10/17

// Ekrem Kalabak

#include "stdafx.h"
#include "ComplexNumber.h"
#include "cmath"

// member/non-member functions of the ComplexNumber class

//Default Constructor
ComplexNumber::ComplexNumber()
{
	real = 0;
	imaginary = 0;
}

//Constructor
ComplexNumber::ComplexNumber(int re, int im)
{
	real = re;
	imaginary = im;
}

//Overloading '+' operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& right)
{
	return ComplexNumber (real + right.real, imaginary + right.imaginary);
}

//Magnitude function to calculate the magnitude of a ComplexNumber object
double ComplexNumber::Magnitute() const
{
	return sqrt(pow(real,2)+pow(imaginary,2));
}

//Overloading '>>' operator to read from a file into a ComplexNumber object
istream & operator >> (istream &in, ComplexNumber &theNumber)
{
	in >> theNumber.real >> theNumber.imaginary;
	return in;
}

//Overloading '<<' operator to write a ComplexNumber object to a file
ostream & operator << (ostream &out,const ComplexNumber &theNumber)
{
	if (theNumber.imaginary < 0)
		out << theNumber.real << " - " << -1*(theNumber.imaginary) << "i";
	else
		out << theNumber.real << " + " << theNumber.imaginary << "i";
	return out;
}