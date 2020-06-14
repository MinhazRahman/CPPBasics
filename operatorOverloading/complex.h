#include <iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
private:
  int real;
  int img;

public:
  Complex();
  Complex(int, int);
  Complex add(Complex);
  Complex operator+(Complex);                       //addition (+) operator overloading
  friend Complex operator-(Complex, Complex);       // operator overloading using friend functions
  friend ostream &operator<<(ostream &, Complex &); //overload stream insertion operator <<
  int getReal();
  int getImg();
};

#endif