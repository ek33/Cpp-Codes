#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include"stdafx.h"


template <typename T>
void InsertionSort(T* theArray, unsigned int size)
{
	unsigned int i,j;
	for (i = 1; i < size ; i++)
	{
		T tracker = theArray[i];
		for (j = i - 1; theArray[j] > tracker && j >= 0; j--)
			theArray[j + 1] = theArray[j];
		theArray[j + 1] = tracker;
	}
}

#endif
