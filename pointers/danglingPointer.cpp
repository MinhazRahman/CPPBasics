#include <iostream>
using namespace std;

/*
Dangling pointer problem occurs when a pointer allocated inside a code block
gets deallocated by a different code block.
For example a pointer p allocated inside main function gets deallocated by 
another function fun();

Delete doesn't delete anything -- it just marks the memory as "being free for reuse". 
Until some other allocation call reserves and fills that space it will have the old data. 
However, relying on that is a big no-no, basically if you delete something forget about it.
This is technically known as Undefined Behavior.
*/

void deallocate(int *arr);

//deallocates the memory
void deallocate(int *arr)
{

  delete[] arr;
  arr = nullptr;
}

int main()
{
  //create an array dynamically
  int *p = new int[5];

  //initialize the array using pointer
  for (int i = 0; i < 5; i++)
  {
    *(p + i) = i + 1; //*(p + i) = p[i]
  }

  //call the function
  deallocate(p);

  //the memory has already been deallocated by deallocate() function
  //trying to delete it again, will case run time error
  delete[] p;
  p = nullptr;

  //undefined behavior
  //The system does not clear the memory when you release it via delete().
  //The contents are therefore still accessible until the memory is assigned for reuse and overwritten.
  //cout << *p << endl;
  //cout << *(p + 2) << endl;
}