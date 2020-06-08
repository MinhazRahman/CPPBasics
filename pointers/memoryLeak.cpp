#include <iostream>
using namespace std;

/*
Before making a pointer null we need to delete the pointer:
delete []p;
p = Null;
p = 0;
p = nullptr;
*/
int main()
{
  //dynamically create a pointer
  int *p = new int[5];

  cout << p << endl;

  //delete the pointer
  delete[] p;
  p = nullptr; // p points to null address

  cout << p << endl;

  return 0;
}