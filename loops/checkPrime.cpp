#include <iostream>
#include <cmath>
using namespace std;

//function declaration
bool isPrime(int);
int checkPrimeNumbers(int);

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

//checks how many prime numbers are there from 1 to n
int checkPrimeNumbers(int n)
{
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (isPrime(i))
    {
      ++count;
    }
  }
  return count;
}

int main()
{
  //check prime numbers
  cout << "Total number of prime numbers: " << checkPrimeNumbers(20) << endl;
  ;
  return 0;
}