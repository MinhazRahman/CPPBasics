#include <iostream>
using namespace std;

//declare the classes
class Rectangle;
class Demo;
/*
In a file, a class can access only the public members of another class on the object of that class.
But if we declare a class as a friend of another class, then the friend class can access all the private, protected
and public members of that class.
*/

class Shape
{
private:
  int a;

protected:
  int b;

public:
  Shape(){};
  int c;
  friend class Rectangle;
};

//friend class Rectangle can access all the private, protected and public members of Shape class
class Rectangle
{
public:
  Shape shape;
  void show()
  {
    shape.a = 10;
    shape.b = 20;
    shape.c = 30;

    cout << shape.a << " " << shape.b << " " << shape.c << endl;
  }
};

//non friend class Demo can only access the public members of class Shape
class Demo
{
public:
  Shape shape;
  void show()
  {
    //shape.a = 10; //Error: can't access the private members
    //shape.b = 20; //Error: can't access the protected members
    shape.c = 30;

    cout << shape.c << endl;
  }
};

int main()
{
  //create objects
  Rectangle r;
  Demo d;
  //call the methods
  r.show();
  d.show();

  return 0;
}