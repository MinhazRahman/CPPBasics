#include <iostream>
using namespace std;
/*
Static variables belong to the class and they are shared by all the objects
of the class. There is exactly one copy of a static variable throughout the class
and all the objects can access that variable, modify it and use it.
Instance variables belong to the instances of a class and static variables belong to 
the class itself.

Static functions can access only othe static members of a class.
Static functions can be called by class name as well as by the object name.
*/

class Demo
{
private:
  //declare instance variables
  int a;
  int b;

public:
  //declare static variable
  static int count;
  Demo()
  {
    a = 5;
    b = 10;
    count++;
  }
  static int getCount();
};

//declare the static variable outside of the class using scope resolution operator
int Demo::count = 0;
int Demo::getCount()
{
  return count;
}

int main()
{
  //call the static function getCount()
  cout << Demo::getCount() << endl;
  //create objects of class Demo
  Demo d1;
  Demo d2;
  //both objects d1 and d2 can access getCount()
  cout << d1.getCount() << endl;
  cout << d2.getCount() << endl;
  //call the static function getCount()
  cout << Demo::getCount() << endl;

  return 0;
}