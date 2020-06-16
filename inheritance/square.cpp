#include <iostream>
#include "square.h"
#include "shape.h"
using namespace std;
//implementations
Square::Square() : Shape()
{
  cout << "inside Square's constructor" << endl;
}

Square::Square(int length, int width) : Shape(length, width)
{
  cout << "inside Square's constructor" << endl;
}
Square::Square(Square &square)
{
  cout << "inside Square's constructor" << endl;
  setLength(square.getLength());
  setLength(square.getWidth());
}
int Square::getArea()
{
  return getLength() * getWidth();
}

int Square::getPerimeter()
{
  return 2 * (getLength() * getWidth());
}

bool Square::isSquare()
{
  return getLength() == getWidth();
}

Square::~Square()
{
  cout << "Deallocate the Square" << endl;
}