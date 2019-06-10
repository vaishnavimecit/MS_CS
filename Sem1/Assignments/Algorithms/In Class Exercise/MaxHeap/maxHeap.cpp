#include <iostream>
#include <climits>
#include "maxHeap.h"

using namespace std; 


// A utility function to swap two elements 
void maxHeap::swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Constructor: Builds a heap from a given array a[] of given size 
maxHeap::maxHeap(int cap) 
{ 
	heapSize = 0; 
	capacity = cap; 
	heapArray = new int[cap]; 
} 

// Inserts a new key 'k' 
void maxHeap::insertKey(int k) 
{ 
	if (heapSize == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

    // First insert the new key at the end 
	heapSize++; 
	int i = heapSize - 1; 
	heapArray[i] = k; 

    // Fix the max heap property if it is violated 
	while (i != 0 && heapArray[parent(i)] < heapArray[i]) 
	{ 
		swap(&heapArray[i], &heapArray[parent(i)]); 
		i = parent(i); 
	} 
} 

// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than heapArray[i]. 
void maxHeap::increaseKey(int i, int new_val) 
{ 
	heapArray[i] = new_val; 
	while (i != 0 && heapArray[parent(i)] < heapArray[i]) 
	{ 
		swap(&heapArray[i], &heapArray[parent(i)]); 
		i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
int maxHeap::extractMax() 
{ 
	if (heapSize <= 0) 
		return INT_MAX; 
	if (heapSize == 1) 
	{ 
		heapSize--; 
		return heapArray[0]; 
	} 

    // Store the minimum value, and remove it from heap 
	int root = heapArray[0]; 
	heapArray[0] = heapArray[heapSize-1]; 
	heapSize--; 
	maxHeapify(0); 

	return root; 
} 


// This function deletes key at index i. It first increases value to  
// infinite, then calls extractMax() 
void maxHeap::deleteKey(int i) 
{ 
	increaseKey(i, INT_MAX); 
	extractMax(); 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void maxHeap::maxHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int largest = i; 
	if (l < heapSize && heapArray[l] > heapArray[i]) 
		largest = l; 
	if (r < heapSize && heapArray[r] > heapArray[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(&heapArray[i], &heapArray[largest]); 
		maxHeapify(largest); 
	} 
} 