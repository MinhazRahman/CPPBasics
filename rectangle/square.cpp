#include <iostream>
#include "square.h"
using namespace std;
//implementations
Square::Square()
{
  this->length = 0;
  this->width = 0;
}

Square::Square(int length, int width)
{
  this->length = length;
  this->width = length;
}

Square::Square(Square &square)
{
  this->length = square.length;
  this->width = square.width;
}

int Square::getLength()
{
  return length;
}

int Square::getWidth()
{
  return width;
}

void Square::setLength(int length)
{
  if (length < 0)
  {
    cout << "Length can't be negative" << endl;
    return;
  }
  this->length = length;
}

void Square::setWidth(int width)
{
  if (width < 0)
  {
    cout << "Width can't be negative" << endl;
    return;
  }
  this->width = width;
}

int Square::area()
{
  return length * width;
}

int Square::perimeter()
{
  return 2 * (length * width);
}

bool Square::isSquare()
{
  return length == width;
}

Square::~Square()
{
  cout << "Deallocate the Square" << endl;
}