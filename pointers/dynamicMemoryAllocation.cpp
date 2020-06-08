#include <iostream>
using namespace std;

//dynamic memory allocation
//we can create an array either in the stack or the heap
//we can access heap memory using pointer

int main()
{
  //creates an array in the stack by the name a
  int a[] = {1, 2, 3};

  //creates a pointer variable p in the stack
  int *p;
  //p points to an array created in the heap memory
  p = new int[3];

  //deallocate dynamically created array
  delete[] p;
  p = nullptr;

  //we can declare and initialize an array dynamically as follows
  int *arr = new int[4];
  //this time p points to a different array
  p = new int[5];

  //assigns values to the array created in the stack
  a[2] = 20;
  //assigns values to the array created dynamically in the heap
  p[4] = 12;

  cout << p[4] << endl;

  return 0;
}