#include <iostream>
using namespace std;

/*
Parameter passing:
We can pass a parameter to a function by.. 
1. value
2. address
3. reference

Return statement:
A function can return..
1. value
2. address
3. reference
*/

//write a function that returns a reference
int &returnReference(int &x);

int &returnReference(int &a)
{
  cout << a << endl;

  return a;
}

int main()
{
  int x = 10;
  cout << x << endl;
  //returnReference() returns a reference of x
  //and we are assigning 20 to the reference
  returnReference(x) = 20;
  cout << x << endl;

  return 0;
}