#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
private:
  int length;
  int width;

public:
  Shape();
  Shape(int, int);
  void setLength(int);
  void setWidth(int);
  int getLength();
  int getWidth();
  int getArea();
  int getPerimeter();
  ~Shape();
};
#endif