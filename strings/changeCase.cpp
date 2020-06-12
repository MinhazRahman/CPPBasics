#include <iostream>
#include <cctype>
#include <string>
using namespace std;

//find length using for loop
string toUpper(string str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    str[i] = toupper(str[i]);
  }

  return str;
}

int main()
{
  string s = "hello world";
  cout << toUpper(s) << endl;
  cout << s << endl;

  return 0;
}