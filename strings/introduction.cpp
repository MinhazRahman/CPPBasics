#include <iostream>
using namespace std;

/*
String using:
1. char array
2. string class
*/
int main()
{
  //create sting using char array
  char s1[] = "hello"; //creates string in the stack memory
  cout << s1 << endl;
  //calculate the length of s
  int count = 0;
  for (int i = 0; s1[i] != '\0'; i++)
  {
    ++count;
  }
  cout << count << endl;

  //refers string using pointer, conversion from string literal to 'char *' is deprecated
  const char *p = "hello world";
  cout << p << endl;

  return 0;
}