#include <iostream>
using namespace std;

/*
Read and write strings
*/

void readString()
{
  //declare a string
  char s1[20];
  cout << "Enter Name: " << endl;
  //read a string from keyboard
  //the following statement will read upto a white space
  cin >> s1;
  //write into the console
  cout << s1 << endl;
}

void getString()
{
  //using get() method to read string from keyboard
  char s2[20];
  cout << "Enter Name:" << endl;
  cin.get(s2, 20);
  cout << s2 << endl;
}

void readLine()
{
  //using get() method to read string from keyboard
  char s3[100];
  cout << "Enter Name:" << endl;
  cin.getline(s3, 100);
  cout << s3 << endl;
}
int main()
{
  readLine();

  return 0;
}