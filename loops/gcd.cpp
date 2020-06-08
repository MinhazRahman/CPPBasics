#include <iostream>
using namespace std;

//function declaration
int findGCD(int, int);

//find greatest common divisor of two numbers
int findGCD(int m, int n)
{
  while (m != n)
  {
    if (m > n)
    {
      m -= n;
    }
    else
    {
      n -= m;
    }
  }
  return m;
}

int main()
{
  cout << findGCD(30, 21) << endl;
  cout << findGCD(30, 36) << endl;
  cout << findGCD(36, 24) << endl;
}