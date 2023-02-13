#include "complex.h"

// implementations
Complex::Complex()
{
  this->real = 0;
  this->img = 0;
}
Complex::Complex(int real, int img)
{
  this->real = real;
  this->img = img;
}

Complex Complex::add(Complex complex)
{
  Complex comp;
  comp.real = this->real + complex.real;
  comp.img = this->img + complex.img;

  return comp;
}
// addition (+) operator overloading
Complex Complex::operator+(Complex complex)
{
  Complex comp;
  comp.real = real + complex.real;
  comp.img = img + complex.img;

  return comp;
}
// operator overloading using friend functions
// friend functions don't belong to the class.
// friend function has to be written outside of the class
// without scope resolution operator
Complex operator-(Complex x, Complex y)
{
  Complex temp;
  temp.real = x.real - y.real;
  temp.img = x.img - y.img;

  return temp;
}

// overload stream insertion operator <<
ostream &operator<<(ostream &output, Complex &c)
{
  output << c.real << " + i" << c.img << endl;
  return output;
}

int Complex::getReal()
{
  return real;
}

int Complex::getImg()
{
  return img;
}