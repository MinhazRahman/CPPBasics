#include <iostream>
#include <cmath>
using namespace std;

//function declaration
bool isPrime(int);
void checkPrimeNumbers(int);

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

void checkPrimeNumbers(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (isPrime(i))
    {
      cout << i << endl;
    }
  }
}

int main()
{
  //check prime numbers
  checkPrimeNumbers(20);
  return 0;
}