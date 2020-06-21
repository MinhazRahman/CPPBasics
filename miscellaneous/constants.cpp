#include <iostream>
using namespace std;

/*There are various usage of constants in c++. Some of them are listed below.
1. constant identifier: const int x = 10;
2. using preprocessor directive: #define x 10

3. pointer to a (int) constant: 
  const int *ptr = &x;  //OR
  int const *p = &x
  Here, the value is constant, not the pointer. We can write as below:
  int y = 20;
  ptr = &y;

4. constant pointer of type integer: 
    int x = 10;
    int *const ptr = &x;
  
5. constant pointer to a interger constant:
    int x = 10;
    const int *const ptr = &x;

*/

void constantIdentifier()
{
  //constant identifier
  const int x = 10;
  //contants can't be incremented
  //x++;
}

void constPointer()
{
  int x = 10;
  int *ptr = &x;
  const int *constPtr = &x;
  //increment the value of x using pointer
  ++*ptr;
  //we can't increment the value using constant pointer
  //++*constPtr;
  cout << *ptr << endl;
  cout << *constPtr << endl;
}

int main()
{
  constPointer();

  return 0;
}