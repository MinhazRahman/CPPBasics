#include <iostream>
#include "square.h"
using namespace std;

/*Compile, Link and Run multiple files:
1. compile the .cpp files into object files (.o files)first:
$ clang++ -c square.cpp squareMain.cpp

2. Link object code files (.o files) into an executable called "main":
$ clang++ square.o squareMain.o -o main

3. Run the executable file "sample":
$ ./main
*/

int main()
{
  //create an object
  Square sq(10, 10);

  cout << sq.area() << endl;
  cout << sq.perimeter() << endl;

  return 0;
}