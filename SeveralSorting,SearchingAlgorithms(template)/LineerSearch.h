#ifndef LINEERSEARCH_H
#define LINEERSEARCH_H

#include"stdafx.h"


template <typename T>
int LineerSearch(T* theArray,unsigned int size, T key)
{
	for (unsigned int position = 0; position < size; position++)
		if (key == theArray[position])
			return (int)position;
	return -1;
}

#endif

