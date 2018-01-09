#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include"stdafx.h"


template <typename T>
void SelectionSort(T* theArray, unsigned int size)
{
	for (unsigned int i = 0; i < size-1; i++)
	{
		unsigned int minimumIndex=i;
		T temp;
		for (unsigned int j = i + 1; j < size; j++)
			if (theArray[j] < theArray[minimumIndex])
				minimumIndex = j;

		temp = theArray[minimumIndex];
		theArray[minimumIndex] = theArray[i];
		theArray[i] = temp;
	}
}

#endif
