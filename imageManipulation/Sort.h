// COMP-SCI 201L - Section 2
// Lab 9 (11/07/17)

// Ekrem Kalabak

#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

/** 
	1. The sorting algorithm - Heap Sort
	2. how the sorting algorithm works - It divides the input data in two pieces: the heap and the sorted part.
		Then, it moves the biggest element in the heap to the sorted part until only one element remains in the heap (smallest element).
	3. The Big-O notation of the sorting algorithm for the best, worst, and average cases
		Best O(n), Worst O(nlogn), Average O(nlogn) 
	4. The sorting algorithm is in-place sorting 
	5. The sorting algorithm is not stable sorting 
*/


void createMaxHeap(vector<int>& A, int n, int i)
{

	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && A[l] > A[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && A[r] > A[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(A[i], A[largest]);

		// Recursively heapify the affected sub-tree
		createMaxHeap(A, n, largest);
	}
}

// main function to do heap sort
void Sort(vector<int>& A) {
	// Implement your sorting algorithm here.
	// You may define more functions to help you.
	int n = A.size();
		// Build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--)
			createMaxHeap(A, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(A[0], A[i]);

		// call max heap on the reduced heap
		createMaxHeap(A, i, 0);
	}
}

int Median(const vector<int>& A) {
	// Write some code to return the median in a sorted array.

	if (A.size() % 2)
		return A[A.size() / 2];
	else
		return (A[A.size() / 2 - 1] + A[A.size() / 2]) / 2;
}

#endif