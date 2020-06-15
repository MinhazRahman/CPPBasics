#include <iostream>
using namespace std;
#ifndef RATIONAL_H
#define RATIONAL_H
/*
A rational number is a number that can be in the form p/q
where p and q are integers and q is not equal to zero.
*/
class Rational
{
private:
  int p;
  int q;

public:
  Rational();
  Rational(int, int);
  Rational add(Rational);
  Rational operator+(Rational);                      //overload + operator
  friend ostream &operator<<(ostream &, Rational &); //overload << operator
  void getP();
  void getQ();
  int setP();
  int setQ();
};

#endif