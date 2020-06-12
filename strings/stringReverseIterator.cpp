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
  string::reverse_iterator revIt;
  //iterate over the string
  for (revIt = str.rbegin(); revIt != str.rend(); revIt++)
  {
    cout << *revIt << endl;
  }

  return 0;
}