#include <iostream>
#include <cstdlib>

#include "sort.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[])
{ 

/*
 * allocated and generate random strings
 * -> do not forget to store the length of the strings
 */
int length = 0;
int m;
int s;
timer t;

random_generator* rg = new random_generator();

if (argc > 1)
   {
     m = atoi(argv[1]);
     m = (m < 1) ? 1 : m;
     s = atoi(argv[2]);
     s = (s < 1) ? 1 : s;
   }
 else
   {
     cout << "hw2: [m] [s]" << endl;
     cout << "[m] 	    size of the string array" << endl;
     cout << "[s] 	    maximum size of the random string" << endl;
     cout << endl;
     return 0;
   }

char* my_char[m];
int A_len[m];

t.start();
for(int i=0;i<m;i++)
{
	my_char[i]= rg->random_string(s, length);
	A_len[i]=length;
}
t.stop();

cout << "Timer (generate): " << t << endl;

cout << "Running radix sort using insertion sort algorithm:\n " << endl;
t.start();
  radix_sort(my_char, 0, m-1, A_len);
t.stop();
cout << "Timer (sort): " << t << endl;

// check whether or not the algorithm sorted the array

  if (check_sorted(my_char, 0, m-1))
    cout << "The output is sorted! \n" << endl;
  else
    cout << "ERROR: The output is not sorted! \n" << endl;

  cout << endl;

  char* my_char2[m];
  char* output[m];
  int A_len2[m];

t.start();
  for(int i=0; i<m; i++)
  {
  my_char2[i]= rg->random_string(s, length);
  A_len2[i]=length;
  }
t.stop();

  cout << "Timer (generate): " << t << endl;

  cout << "Running counting sort algorithm:\n " << endl;
t.start();
  radix_sort_count(my_char2, output,0, m-1,A_len2);
t.stop();
  cout << "Timer (sort): " << t << endl;


//check sorted array
    if (check_sorted(output, 0, m-1))
      cout << "The output is sorted! \n" << endl;
    else
      cout << "ERROR: The output is not sorted! \n" << endl;

cout << endl;

  return 0;
}
