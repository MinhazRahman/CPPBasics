#include <iostream>
#include <cstring>
using namespace std;
/*
String functions:
1. strlen()
2. strcat
3. strcpy
4. strncpy()
*/
int main()
{
  //create a string using char array
  char s1[50] = "Hello World ";
  char s2[] = "C++";
  char s3[10];
  char s4[20];
  cout << strlen(s1) << endl;
  //concatenate and assign to string s1
  strcat(s1, s2);
  cout << s1 << endl;

  //copy string s2 into s3
  strcpy(s3, s2);
  cout << s3 << endl;

  //copy specific number of character from s1 to s4
  strncpy(s4, s1, 5);
  cout << s4 << endl;

  return 0;
}