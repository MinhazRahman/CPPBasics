#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

//class Square is inherited from class Shape
class Square : public Shape
{

public:
  //constructors
  Square();
  Square(int length, int width);
  Square(Square &square);
  //member functions
  int getArea();      //overrides Shape::getArea
  int getPerimeter(); //overrides Shape:getPerimeter
  //enquiry
  bool isSquare();

  //destructor, to deallocate an object
  ~Square();
};

#endif