// COMP-SCI 201L (FS17) - Section 2
// Lab 7 - 10/24/17


#ifndef NATURAL_NUMBER_H
#define NATURAL_NUMBER_H

#include <sstream>

using namespace std;

class Natural_Number {
private:
	string expression;
	virtual int get_decimal_value() const = 0;
public:
	Natural_Number(const string& exp = "") { expression = exp; }
	string get_expression() const { return expression; }
	virtual string to_binary() const = 0;
	virtual string to_octal() const = 0;
	virtual string to_decimal() const = 0;
	virtual string to_hexadecimal() const = 0;
	virtual ~Natural_Number() { ; }  // A child class may have its own destructor.
};

#endif