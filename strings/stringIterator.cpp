#include <iostream>
#include <string>
using namespace std;

/*
We can use iterator to loop through a collection that doesn't allow
random access to elements.
*/

int main()
{
  //declare and initialize a string
  string str = "hello world";
  //create a string iterator
  string::iterator it;
  //iterate over the string
  for (it = str.begin(); it != str.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}