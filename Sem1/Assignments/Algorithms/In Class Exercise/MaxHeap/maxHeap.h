#ifndef __maxHeap_h__
#define __maxHeap_h__

// A class for Min Heap 
class maxHeap 
{ 
    int *heapArray; // pointer to array of elements in heap 
    int heapSize; // Current number of elements in min heap 
    int capacity; // maximum possible size of min heap 
    
public: 
    // Constructor 
    maxHeap(int capacity); 
  
    //heapify a subtree with the root at given index 
    void maxHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    //get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    //get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    //extract the root which is the minimum element 
    int extractMax(); 
  
    //increases key value of key at index i to new_val 
    void increaseKey(int i, int new_val); 
  
    //returns the minimum key (key at root) from min heap 
    int getMax() { return heapArray[0]; } 
  
    //deletes a key stored at index i 
    void deleteKey(int i); 
  
    //inserts a new key 'k' 
    void insertKey(int k); 

    //returns size of heap
    int size() { return heapSize; }

    void swap(int *x, int *y);
};

#endif // __maxHeap_h__