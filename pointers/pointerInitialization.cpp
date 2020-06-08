#include <iostream>
using namespace std;

/*
Problems using pointer:
1. uninitialized pointer
2. memory leak
3. dangling pointer
*/

int main()
{
  //declare and initialize a data variable
  int x = 20;
  //declare a pointer variable
  int *p;

  //initialize a pointer variable

  //1. assign the address of x to p
  p = &x;
  cout << p << endl;

  //2. assign a dynamically allocated address to p
  p = new int[5];
  cout << p << endl;

  //3. assign a valid hex address to pointer p,
  //in this case we have to type cast the address into int pointer
  p = (int *)0x7ffeeeab3690;
  cout << p << endl;

  return 0;
}