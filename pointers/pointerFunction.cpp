#include <iostream>
using namespace std;

/*
Using pointer to a function we can achieve polymorphism
*/

int max(int m, int n)
{
  return m > n ? m : n;
}

int min(int m, int n)
{
  return m < n ? m : n;
}

int main()
{
  //declare a pointer to a function
  int (*fp)(int, int);
  //initialize pointer
  fp = max;
  //calling the function
  cout << "Maximum: " << (*fp)(10, 5) << endl;

  //this time, pointer fp refers to function min()
  fp = min;
  cout << "Minimum: " << (*fp)(10, 5) << endl;

  return 0;
}