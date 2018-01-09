// COMP-SCI 201L (FS17) - Section 2
// Lab 3 - 09/19/17

// Ekrem Kalabak

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

using namespace std;

class CaesarCipher
{
private:
	int key1, key2;
	char Encode(char);
	char Decode(char);
public:
	CaesarCipher() { key1 = initkey(); key2 = initkey(); }
	int initkey();
	string Encode(string);
	string Decode(string);

};


#endif