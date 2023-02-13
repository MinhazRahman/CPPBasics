#include <iostream>
#include "complex.h"
using namespace std;

/*Compile, Link and Run multiple files:
1. compile the .cpp files into object files (.o files)first:
$ clang++ -c complex.cpp complexMain.cpp

2. Link object code files (.o files) into an executable called "main":
$ clang++ complex.o complexMain.o -o main

3. Run the executable file "main":
$ ./main
*/
int main()
{
  // create complex numbers
  Complex c1(4, 5);
  Complex c2(3, 3);
  Complex c3;
  Complex c4;
  Complex c5;

  // add complex numbers
  c3 = c1.add(c2);
  c4 = c1 + c2;
  c5 = c1 - c2;

  // print values
  cout << c3.getReal() << " + i" << c3.getImg() << endl;
  cout << c4.getReal() << " + i" << c4.getImg() << endl;
  // output complex number using overloaded stream insertion operator <<
  cout << c5 << endl;
  operator<<(cout, c5); // same as cout << c5

  return 0;
}