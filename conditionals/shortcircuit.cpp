#include <iostream>
using namespace std;

//example of short circuit
//for logical AND (&&) operation if the first condition is false
//then the compiler will not check the second condition
//for logical OR (||) is the first condition is true then the
//compiler will not check the second condition
//this is called short circuit
int main()
{
  int a = 5, b = 7, i = 3;
  //because of short circuit AND, i remains same
  if (a > b && ++i > b)
  {
  }
  // i will be 3
  cout << i << endl;

  //short circuit OR
  if (a < b || ++i < b)
  {
    cout << i << endl; // i is still 3
  }

  return 0;
}