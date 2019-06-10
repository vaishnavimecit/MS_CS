//C++ program to write and read text in/from file.
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   fstream file; //object of fstream class   
   //again open file in read mode
   string word, t, q, filename;
   filename="Fam2.ged";
   //file.open("Fam2.ged",ios::in);
   file.open(filename.c_str());
   
   //if(!filename)
   //{
   //  cout<<"Error in opening file!!!"<<endl;
   //  return 0;
   //}   

   //read untill end of file is not found.
   //char ch; //to read single character
   //cout<<"File content: ";
   //while(!file.eof())
   //{
   //  file>>ch; //read single character from file
   //  file << "";
   //  cout<<ch;
   //}
   //file.close(); //close file

   while(file >> word)
	{
	cout << word << endl;
	}
   return 0;
}