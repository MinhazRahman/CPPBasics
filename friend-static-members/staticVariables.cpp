#include <iostream>
using namespace std;
/*
Static variables belong to the class and they are shared by all the objects
of the class. There is exactly one copy of a static variable throughout the class
and all the objects can access that variable, modify it and use it.
Instance variables belong to the instances of a class and static variables belong to 
the class itself.
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
};

//declare the static variable outside of the class using scope resolution operator
int Demo::count = 0;

int main()
{
  //create objects of class Demo
  Demo d1;
  Demo d2;
  //both objects d1 and d2 can access the static variable count
  cout << d1.count << endl;
  cout << d2.count << endl;
  //static variable count can be accessed using class name Demo
  cout << Demo::count << endl;

  return 0;
}