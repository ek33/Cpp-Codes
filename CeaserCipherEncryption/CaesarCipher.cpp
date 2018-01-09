// COMP-SCI 201L (FS17) - Section 2
// Lab 3 - 09/19/17

// Ekrem Kalabak
#include "stdafx.h"
#include "CaesarCipher.h"
#include <ctime>


// member functions of class CaesarCipher

int CaesarCipher::initkey()
{
	srand(time(0));
	return (rand() % 19) - 9;
}

char CaesarCipher::Encode(char letter)
{
	
	if (letter == ' ')
		return ' ';
	else if ((letter + (key1 + key2)) > 122)
		return (letter + (key1 + key2) - 26);
	else if ((letter + (key1 + key2)) < 97)
		return (letter + (key1 + key2) + 26);
	return (letter + (key1 + key2));
}

char CaesarCipher::Decode(char letter)
{
	if (letter == ' ')
		return ' ';
	else if ((letter - (key1 + key2)) > 122)
		return (letter - (key1 + key2) - 26);
	else if ((letter - (key1 + key2)) < 97)
		return (letter - (key1 + key2) + 26);
	return (letter - (key1 + key2));
}

string CaesarCipher::Encode(string sentence)
{
	string encoded;
	int length = (int)sentence.size();
	encoded.resize(length);
	for (int i = 0; i < length;i++)
		encoded[i] = Encode(sentence[i]);
	return encoded;
}

string CaesarCipher::Decode(string sentence)
{
	string decoded;
	int length = (int)sentence.size();
	decoded.resize(length);
	for (int i = 0; i<length;i++)
		decoded[i] = Decode(sentence[i]);
	
	return decoded;
}