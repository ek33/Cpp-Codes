// COMP-SCI 201L (FS17) - Section 2
// Exam 1 - 10/10/17

// Ekrem Kalabak

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// ComplexNumber class 
class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int re, int im);
	ComplexNumber operator+(const ComplexNumber&);
	double Magnitute() const;
	friend istream & operator >> (istream &in, ComplexNumber &);
	friend ostream & operator << (ostream &out, const ComplexNumber &);
};

#endif