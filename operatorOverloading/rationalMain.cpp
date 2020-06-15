#include <iostream>
#include "rational.h"
using namespace std;
/*Client file
Compile, Link and Run multiple files:
1. compile the .cpp files into object files (.o files)first:
$ clang++ -c rational.cpp rationalMain.cpp 

2. Link object code files (.o files) into an executable called "rationalMain":
$ clang++ rational.o rationalMain.o -o rationalMain

3. Run the executable file "main":
$ ./rationalMain 
*/

int main()
{
  //create objects
  Rational r1(2, 3), r2(5, 7), r3, r4;
  //add two rational numbers
  r3 = r1 + r2;
  r4 = r1.add(r2);
  //print values
  cout << r3;
  cout << r4;

  return 0;
}
