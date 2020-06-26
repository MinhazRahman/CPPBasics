#include <iostream>
using namespace std;

/*
1. starting from C++11 we can initialize variables at the time they are declared

2. Constructors are allowed to call other constructors. This process is called delegating constructors (or constructor chaining).
To have one constructor call another, simply call the constructor in the member initializer list. 
This is one case where calling another constructor directly is acceptable.
*/

class Test
{
  //inclass initializer
private:
  int a = 10;
  int b = 20;

public:
  Test(int a, int b)
  {
    this->a = a;
    this->b = b;
  }
  Test() : Test(1, 1) //delegating constructor
  {
  }
};

int main()
{
}