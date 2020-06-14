#include <iostream>
using namespace std;

class Rectangle
{
private:
  int length;
  int width;

public:
  //constructor
  Rectangle() //no-parameter
  {
    this->length = 0;
    this->width = 0;
  }

  Rectangle(int length = 0, int width = 0) //parametersized construcor with default values
  {
    setLength(length);
    setWidth(width);
  }

  Rectangle(Rectangle &rect) //copy constructor, shallow copy constructor
  {
    this->length = rect.length;
    this->width = rect.width;
  }

  //getters and setters, property functions
  void setLength(int length)
  {
    if (length < 0)
    {
      cout << "Length can't be negative" << endl;
      return;
    }
    this->length = length;
  }
  void setWidth(int width)
  {
    if (width < 0)
    {
      cout << "Width can't be negative" << endl;
      return;
    }
    this->width = width;
  }
  int getLength()
  {
    return length;
  }
  int getWidth()
  {
    return width;
  }

  //member methods
  int area()
  {
    return length * width;
  }

  int perimeter()
  {
    return 2 * (length * width);
  }
};

int main()
{
  //create an object on the stack memory
  Rectangle r(0, 0);

  //set length and width
  r.setLength(-5);
  r.setWidth(-10);

  //set area
  cout << r.area() << endl;
  cout << r.perimeter() << endl;

  return 0;
}