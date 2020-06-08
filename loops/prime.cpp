#include <iostream>
#include <cmath>
using namespace std;

//function declaration
bool isPrime(int);

//check if a number is prime or not
bool isPrime(int n)
{
  bool prime = true;

  if (n == 1 || n == 2)
  {
    return prime;
  }

  for (int i = 2; i <= (int)sqrt(double(n)); i++)
  {
    if (n % i == 0)
    {
      prime = false;
      break;
    }
  }
  return prime;
}

int main()
{
  cout << isPrime(17) << endl;

  return 0;
}