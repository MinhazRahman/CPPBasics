#include <iostream>
#include <string>
using namespace std;

/*
Use of keyword final:
1. If we declare a class as final then that class can't be subclassed
2. A function declared as final can't be overridden
3. 
*/

class Super
{
public:
  virtual void show() final
  {
    cout << "Inside Super class" << endl;
  }
};

class Sub : Super
{
public:
  void show() //can't override a final method
  {
    cout << "Inside Sub class" << endl;
  }
};

int main()
{

  return 0;
}