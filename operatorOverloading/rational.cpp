#include <iostream>
using namespace std;
#include "rational.h"
/*
Implementations of the class and instance members
*/

Rational::Rational()
{
  this->p = 1;
  this->q = 1;
}
Rational::Rational(int p, int q)
{
  this->p = p;
  this->q = q;
}

Rational Rational::add(Rational r)
{
  Rational temp;
  temp.p = this->p * r.q + this->q * r.p;
  temp.q = this->q * r.q;

  return temp;
}

Rational Rational::operator+(Rational r)
{
  Rational temp;
  temp.p = this->p * r.q + this->q * r.p;
  temp.q = this->q * r.q;

  return temp;
}

ostream &operator<<(ostream &output, Rational &r)
{
  output << r.p << "/" << r.q << endl;
  return output;
}
