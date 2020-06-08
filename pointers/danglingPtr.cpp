#include <iostream>
using namespace std;

int main()
{
  //Declaring two pointer variables to int
  int *ptr1;
  int *ptr2;
  // Allocating dynamic memory in the heap
  ptr1 = new int;
  ptr2 = ptr1; // Having both pointers to point same dynamic memory location
  //deleting the dynamic memory location
  delete ptr1;
  ptr1 = nullptr;

  //ptr2 is still pointing the already deleted memory location
  //We call ptr2 is a dangling pointer
  //memory location has already been deallocated
  //trying to delete the memory location again will cause run time error
  delete[] ptr2;
  ptr2 = nullptr;

  return 0;
}