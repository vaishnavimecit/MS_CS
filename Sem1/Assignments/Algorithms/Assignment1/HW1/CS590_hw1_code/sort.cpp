#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "sort.h"


int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

//insertion sort

void insertion_sort(int** A, int n, int l, int r)
{ 
  int i;
  int key;
  int* vect_len;
  int arr[r];
  for (int k = 0; k <= r; k++)
	{
	arr[k] = ivector_length(A[k], n);
	}

  for (int j = l+1; j <= r; j++)
    {
      key = arr[j];
      vect_len = A[j];
      i = j - 1;

      while ((i >= l) && arr[i] > key)
        {
	  arr[i+1] = arr[i];
	  A[i+1] = A[i];
	  i = i - 1;
	}

      arr[i+1] = key;
      A[i+1] = vect_len;
    }
}

//naive insertion sort
void insertion_sort_original(int** A, int n, int l, int r)
{ 
  int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}


//Merge Sort

void merge(int** A, int p, int q, int r) 
{ 
    int i, j, k; 
    int l, n;    
    int* vector_len;
    int array[r];
    for (int l = p; l <= r; l++)
	{
	array[l] = ivector_length(A[l], n);
	}
    i=p;
    j=q+1;
    k=p;

    int n1 = q - p + 1; 
    int n2 =  r - q; 
  
    int L[n1];
    int R[n2]; 
  
    for (i = 1; i <= n1; i++) 
        L[i] = array[p+i]; 
    for (j = 1; j <= n2; j++) 
        R[j] = array[q + 1 + j];
    i = 1; 
    j = 1; 
        while(i<=q &&j<=r)
	{
        	if (L[i] <= R[j]) 
        	{ 
            	array[k] = L[i]; 
            	i++; 
        	} 
        	else
        	{ 
            	array[k] = R[j]; 
            	j++; 
        	}
	k++;
	}
	while(i<=q)
	{
	array[k] = L[i];
	k++;
	i++;
	}
}

void mergeSort(int** A, int p, int r)
{ 
    if (p < r) 
    { 
        int q = p+r/2; 
        mergeSort(A, p, q); 
        mergeSort(A, q+1, r); 
        merge(A, p, q, r); 
    } 
} 


//Simple function to check that our sorting algorithm did work

bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


//generate sorted/reverse/random arrays of type hw1type

int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

