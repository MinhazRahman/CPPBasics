#include <iostream>
using namespace std;
//function declaration
int reverseNumber(int);

//display the digits of a numbers
int reverseNumber(int number)
{
  int remainder = 0;
  int reverse = 0;
  while (number != 0)
  {
    remainder = number % 10;
    reverse = reverse * 10 + remainder;
    number = (number / 10);
  }
  return reverse;
}

int main()
{
  cout << reverseNumber(1234567) << endl;
}