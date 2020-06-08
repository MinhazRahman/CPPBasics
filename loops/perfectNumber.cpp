#include <iostream>
using namespace std;

//a number n, is perfect if, sum of factors of n == 2*n

//function declaration
bool isPerfect(int);

//returns true if a number is perfect otherwise false
bool isPerfect(int n)
{
  int sum = 0;

  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
    }
  }

  return 2 * n == sum;
}

int main()
{
  cout << isPerfect(12) << endl;
  cout << isPerfect(6) << endl;

  return 0;
}