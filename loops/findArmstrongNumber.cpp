#include <iostream>
#include <cmath>
using namespace std;

/*
An Armstrong number of three digits is an integer such that
the sum of the cubes of its digits is equal to the number itself.
For example, 371 is an Armstrong number since 3**3 + 7**3 + 1**3 = 371.
Write a program to find all Armstrong number in the range of 0 and 999
*/

//function declaration
bool isArmstrongNumber(int);
void checkArmstrongNumber(int);

//check if a number is an armstrong number
bool isArmstrongNumber(int number)
{
  int sum = 0, remainder = 0;
  int n = number;
  while (n != 0)
  {
    remainder = n % 10;
    n = n / 10;
    sum += pow(remainder, 3);
  }
  return sum == number;
}

//find all Armstrong number in the range of 0 and 999
void checkArmstrongNumber(int n)
{
  for (int i = 0; i <= n; i++)
  {
    if (isArmstrongNumber(i))
    {
      cout << i << endl;
    }
  }
}

int main()
{
  checkArmstrongNumber(999);
}