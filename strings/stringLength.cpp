#include <iostream>
#include <string>
using namespace std;

//find length using for loop
int findLength(string str)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    ++count;
  }

  return count;
}

//find length using iterator
int getLength(string str)
{
  string::iterator itr;
  int count = 0;
  for (itr = str.begin(); itr != str.end(); itr++)
  {
    ++count;
  }

  return count;
}

int main()
{
  string s = "hello world";
  cout << findLength(s) << endl;
  cout << getLength(s) << endl;

  return 0;
}