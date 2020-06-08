#include <iostream>
using namespace std;

//function declaration
int factorial(int);

//function definition, calculates the factorial of n
int factorial(int n)
{
  int fact = 1;

  for (int i = 0; i < n; i++)
  {
    fact *= (n - i);
  }

  return fact;
}

//calculate factorial of a number n
int main()
{
  cout << factorial(5) << endl;

  return 0;
}