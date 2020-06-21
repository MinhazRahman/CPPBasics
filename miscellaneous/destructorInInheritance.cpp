#include <iostream>
using namespace std;

/*
In case of destructors, derived class destructors are called first and then base the
class destructors. For this to happen, we need to declare the base class constructor as virtual.

On the other hand, constructors are called according to the order of derivation, 
base class constructors are called first and then the derived class constructors.
*/

class Shape
{
private:
  int length;
  int width;

public:
  //constructor
  Shape()
  {
  }
  //destructor
  virtual ~Shape()
  {
    cout << "Shape Destructor" << endl;
  }
};

class Rectangle : public Shape
{
public:
  //constructor
  Rectangle() : Shape()
  {
  }
  //destructor
  ~Rectangle()
  {
    cout << "Rectangle Destructor" << endl;
  }
};

int main()
{
  //Shape class pointer, points to Rectangle class object
  Shape *shape = new Rectangle();

  //delete the object
  delete shape;

  return 0;
}