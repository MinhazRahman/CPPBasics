#include <iostream>
#include "square.h"
using namespace std;

/*
Compile .cpp files: 
$ clang++ -c shape.cpp square.cpp shapeMain.cpp
Link object (.o) files into an executable file "main":
$ clang++ shape.o square.o shapeMain.o -o main  
Run "main" file:
$ ./main
*/

int main()
{
  //create objects
  Square sq(5, 5);

  //call methods
  cout << "Length: " << sq.getLength() << endl;
  cout << "Width: " << sq.getWidth() << endl;
  cout << "Area: " << sq.getArea() << endl;
  cout << "Perimeter: " << sq.getPerimeter() << endl;

  return 0;
}