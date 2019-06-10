#include<iostream>
using namespace std;
// factTD(3) = 1*2*3=6
int factTD(int f)
{
if (f==0)
 return 0;
else if (f==1)
 return 1;
else
 return f*factTD(f-1);
}

int main(int, char*[])
{
int f;
cout<< "Enter the number:" << endl;
cin >> f;
//cout<< "f=" << f << endl;
cout<< "Factorial of " << f << "= " << factTD(f);
return 0;
}