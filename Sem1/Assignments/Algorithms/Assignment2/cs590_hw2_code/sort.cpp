#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "random_generator.h"

/* 
 * HW 2
 */
int string_compare(char* s1, char *s2)
{ 
/*
 * We assume that s1 and s2 are non-null pointers
 */
  int i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else
    {
      if (s1[i] < s2[i])
	return -1;
      else
	return 1;
    }
}

void insertion_sort(char** A, int l, int r, int d, int* A_len)
{ 
  int i;
  char* key;
  int temp_len;
  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      temp_len=A_len[j];
      i = j - 1;
      int ascii1=0;
      int ascii2=0;

      if(d < A_len[i])
       ascii1= (int)(A[i][d]);
      if(d < A_len[j])
       ascii2= (int)key[d];

      while ((i >= l) && (ascii1 > ascii2))
        {
       A[i+1] = A[i];
       A_len[i+1]=A_len[i];

       i = i - 1;
       ascii1 = 0;

       if(d < A_len[i] && i >= l)
       ascii1= (int)(A[i][d]);
        }

      A[i+1] = key;
      A_len[i+1]=temp_len;
    }
}

void insertion_sort_ori(char** A, int l, int r)
{ 
  int i;
  char* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (string_compare(A[i], key) > 0))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}

void radix_sort(char** A, int l, int r, int* A_len)
{
int k = 0;

for(int i = 0;i <= r;i++)
	{
	if(A_len[i] > k)
		{
			k = A_len[i];
		}
	}
for(int i=k-1;i>=0;i--)
	{
	int d=i;
	insertion_sort(A,l,r,d,A_len);
	}
}

void radix_sort_count(char** A,char** D, int l, int r,int* A_len)
{

int max = 0;
for(int i = 0;i <= r;i++)
	{
	if(A_len[i] > max)
		{
		max = A_len[i];
		}
	}	

for(int i=max-1;i>=0;i--)
	{
	int d=i;
	int k=256;
	counting_sort(A,D,k,r,d,A_len);
	}
D = A;
}

void counting_sort(char** A, char** B, int k, int n, int d, int* A_len)
{
int c[k];
int newLen[n+1];
	for(int i=0;i<=k;i++)
	{
		c[i]=0;
	}
	for(int j=0;j<=n;j++)
	{
		int asc=48;
		if(d<A_len[j])
		asc=int(A[j][d]);
		c[asc]=c[asc]+1;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(int j = n;j >= 0;j--)
	{
		int asc=48;
		if(d < A_len[j])
			asc=(int)(A[j][d]);
		B[c[asc]-1] = A[j];
		newLen[c[asc]-1]=A_len[j];
		c[asc] = c[asc] - 1;
	}
	for(int c=0;c<=n;c++)
		{
		A[c] = B[c];
		A_len[c]=newLen[c];
		}
}


/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(char** A, int l, int r)
{
  for (int i = l+1; i < r; i++)
    if (string_compare(A[i-1],A[i]) > 0)
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