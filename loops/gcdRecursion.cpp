#include <iostream>
using namespace std;

//function declaration
int findGCD(int, int);

//find greatest common divisor of two numbers
int findGCD(int m, int n)
{
  //base cases
  if (m == 0 || n == 0)
  {
    return 0;
  }
  if (m == n)
  {
    return m;
  }

  //recursive steps
  if (m > n)
  {
    return findGCD(m - n, n);
  }
  else
  {
    return findGCD(m, n - m);
  }
}

int main()
{
  cout << findGCD(30, 21) << endl;
  cout << findGCD(30, 36) << endl;
  cout << findGCD(36, 24) << endl;
}