#include <iostream>
using namespace std;
//function declaration
int reverseNumber(int);
bool isPalindrome(int);

//palindrome number: reverse of a number is equal to the number

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

bool isPalindrome(int n)
{
  return reverseNumber(n) == n;
}

int main()
{
  cout << boolalpha << isPalindrome(123) << endl;
  cout << boolalpha << isPalindrome(242) << endl;
  cout << boolalpha << isPalindrome(343) << endl;

  return 0;
}