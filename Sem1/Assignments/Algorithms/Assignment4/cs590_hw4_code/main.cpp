#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "dynprog.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[])
{ 
  random_generator rg;
  timer t;
  int n, m, no_ch, algo;

if (argc > 1)
    {
      n = atoi(argv[1]);
      n = (n < 0) ? 0 : n;
    }
  else
    n = 0;    
if (argc > 2)
{
    n = atoi(argv[1]);
    m = atoi(argv[2]);
}

if(argc > 3)
{

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    no_ch = atoi(argv[3]);

random_generator::seed();

int** H;
int** P;

char* str1;
char* str2;

str1 = rg.random_string_m(n, no_ch);
str2 = rg.random_string_m(m, no_ch);

int** ops = 0;

H = new int*[n];
P = new int*[m];

for(int k =0; k<=n; k++)
{
H[k] = new int[n+1];
P[k] = new int[m+1];
}

cout << str1 <<endl;
cout << str2 <<endl;

bottomupSW(str1, str2, n, m, H, P);
for(int i=0;i<5;i++)
{
  for(int j=0;j<5;j++)
  {
    cout << "H[" << i << "][" << j << "]" << H[i][j] << endl;
    //cout << "P[" << i << "][" << j << "]" << P[i][j] << endl;
  }
}
cout << "Minimum Penalty Value by BottomUp: " << H[n][m] << endl;
cout << endl;
cout << "X Sequence Alignment:" << endl;
printSeqAlignX(str1,P,n,m);
cout << "Y Sequence Alignment:" << endl;
printSeqAlignY(str2,P,n,m);

topdownSW(str1, str2, n, m, ops);
cout << "Minimum Penalty Value by TopDown: " << ops[n][m] << endl;


cout << endl;
}
  
    else
        {
        cout << "hw4: [n] [m] [no_ch]" << endl;
        cout << "[n]" << endl;
        cout << "[m]" << endl;
        cout << "[no_ch]" << endl;
        cout << endl;
        return 0;
        }

  return 0;
}