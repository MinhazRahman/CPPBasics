#include <iostream>
using namespace std;
#include "shape.h"

//implementations
Shape::Shape()
{
  cout << "inside Shape's constructor" << endl;
  this->length = 0;
  this->width = 0;
}

Shape::Shape(int length, int width)
{
  cout << "inside Shape's constructor" << endl;
  this->length = length;
  this->width = width;
}

void Shape::setLength(int length)
{
  if (length < 0)
  {
    return;
  }
  this->length = length;
}

void Shape::setWidth(int width)
{
  if (width < 0)
  {
    return;
  }
  this->width = width;
}

int Shape::getLength()
{
  return length;
}

int Shape::getWidth()
{
  return width;
}

Shape::~Shape()
{
  cout << "Deallocate the Shape" << endl;
}