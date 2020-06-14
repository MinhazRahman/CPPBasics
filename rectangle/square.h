#ifndef SQUARE_H
#define SQUARE_H
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

#endif