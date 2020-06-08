#include <iostream>
using namespace std;

int main()
{
  int a[] = {2, 4, 6, 8, 10, 12};
  //p points to the address of first element of a
  int *p = a;
  //assigns the address of first element of a to p
  int *q = &a[0];

  //both p and q holds the same address
  cout << p << endl;
  cout << q << endl;

  //print the contents of a using p
  cout << *p << endl;
  cout << *(p + 1) << endl;
  cout << *(p + 4) << endl;
  // p = p + 4;

  //use the address operator & to assign values to the pointer q
  q = &a[4];
  cout << *q << endl;

  //print the contents of p and q
  cout << p << endl;
  cout << q << endl;

  return 0;
}