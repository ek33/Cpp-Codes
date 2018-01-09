#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include"stdafx.h"
#include "vector"
using namespace std;

template <typename T>
int BinarySearch(T* theArray, unsigned int beginning, unsigned int end, T key)
{
	if (beginning > end)
		return -1;
	
	int middle = (end + beginning) / 2;

	if (key == theArray[middle])
		return (int)middle;

	if (theArray[middle] > key)
		return BinarySearch(theArray, beginning, middle - 1, key);

	return BinarySearch(theArray, middle + 1, end, key);
}

#endif
