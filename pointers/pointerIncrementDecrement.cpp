#include <iostream>
using namespace std;

int main()
{
  int a[6] = {2, 4, 6, 8, 10, 12};
  //p points to the address of first element of a
  int *p = a;

  //both p and q holds the same address
  cout << p << endl;

  cout << endl;
  //print the contents of p
  cout << p << endl; // int x = 10, after x + 10, x is still 10
  cout << (p + 1) << endl;
  cout << (p + 4) << endl;
  cout << p << endl
       << endl; //p didn't change

  //increments pointer p
  p++;
  cout << *p << endl;
  cout << p << endl;
  //decrements pointer p
  p--;
  cout << *p << endl;
  cout << p << endl;

  return 0;
}