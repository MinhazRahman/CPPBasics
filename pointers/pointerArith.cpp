#include <iostream>
using namespace std;

int main()
{
  int a[6] = {2, 4, 6, 8, 10, 12};
  //p points to the address of first element of a
  int *p = a;
  //assigns the address of first element of a to p
  int *q = &a[0];

  //both p and q holds the same address
  cout << p << endl;
  cout << q << endl;

  cout << endl;
  //print the contents of p
  cout << p << endl; // int x = 10, after x + 10, x is still 10
  cout << (p + 1) << endl;
  cout << (p + 4) << endl;
  cout << p << endl
       << endl; //p didn't change

  //if we assign p + 4 to p as follows then, the value of p will be changed too
  p = p + 4;
  cout << p << endl;

  return 0;
}