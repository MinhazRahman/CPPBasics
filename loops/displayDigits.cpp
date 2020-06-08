#include <iostream>
using namespace std;
//function declaration
void displayDigits(int);

//display the digits of a numbers
void displayDigits(int n)
{
  int remainder = 0;
  while (n != 0)
  {
    remainder = n % 10;
    n = (n / 10);
    cout << remainder << endl;
  }
}

int main()
{
  displayDigits(1234567);
}