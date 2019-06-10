//My First Program
#include<iostream> //precompiler directive
using namespace std; //compiler directive
//main function
int main(int, char*[])
{
cout<< "1) hello, world!" << endl;

int i=7;
int &r =i;
int *p = &i;
int k=i;

cout << "2) i="<<i<< endl;
cout << "2) r="<<r<< endl;
cout << "2) value of p="<<p<< endl;
cout << "2) k="<<k<< endl;

i++;

cout << "3) i="<<i<< endl;
cout << "3) address of r="<<&r<< endl;
cout << "3) value of p="<<*p<< endl;
cout << "3) k="<<k<< endl;

cout << "4) r="<<r<< endl;

return 0;
}