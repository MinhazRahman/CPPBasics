#include <iostream>
using namespace std;
/*
a. data variable
b. pointer variable
1. pointer declaration
2. pointer initialization
3. pointer dereferencing
*/

int main()
{
  //declare a data variable
  int d;
  //initialize the data variable
  d = 20;
  //print value
  cout << d << endl;

  //declare a pointer variable using pointer sign (*)
  int *p;
  //initialize the pointer variable, assign the address of d to p, address operator (&)
  p = &d;
  //print the address of d
  cout << &d << endl;
  //print the value of p
  cout << p << endl;
  //print the value of d through p, using dereferencing syntax
  cout << *p << endl;

  return 0;
}