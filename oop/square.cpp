#include <iostream>
using namespace std;

/* Skeleton of a class:
Data:
  1. instance variables
  2. class variables
  3. constants
Constructor:
  1. default constructor
  2. no parameter constructor
  3. parameterized constructor
  4. shallow copy constructor
  5. deep copy constructor
Property functions:
  1. setters: set properties
  2. getters: get properties
Member functions:
  1. class member functions
  2. object member functions
Deconstructors:
  1. destroyers

On terminal to run file using clang++ use the following commands:
$ clang++ -o square square.cpp 
OR 
$ clang++ square.cpp -o square 
$ ./square    
*/
class Square
{

private:
  //variables
  int length;
  int width;

public:
  //constructors
  Square();
  Square(int length, int width);
  Square(Square &square);

  //getters and setters
  int getLength();
  int getWidth();
  void setLength(int);
  void setWidth(int);

  //member functions
  int area();
  int perimeter();
  //enquiry
  bool isSquare();

  //destructor, to deallocate an object
  ~Square();
};

int main()
{
  //create an object
  Square sq(10, 10);

  cout << sq.area() << endl;
  cout << sq.perimeter() << endl;

  return 0;
}

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