#include <iostream>
using namespace std;
/*
Let suppose, a pointer to the Super class points to the Sub class object.
If we call the overridden methods using the Super class pointer then which
version of the overridden method will be called depends on whether the method
is virtual or not.
1. If we declare the Super class method as virtual then the Sub class method will be called
2. Otherwise the Super class method will be called

Polymorphism:
We can achieve polymorphism with the combination of the following things:
1. virtual keyword
2. method overriding
2. Super/Base class pointer
*/

class Super
{
public:
  Super() {}
  virtual void display()
  {
    cout << "Inside Super's display method" << endl;
  }

  void show()
  {
    cout << "Inside Super's show method" << endl;
  }
};

//derive class Child from Parent class
class Sub : public Super
{
public:
  Sub() : Super() {}
  //override the display method
  void display()
  {
    cout << "Inside Sub's display method" << endl;
  }

  void show()
  {
    cout << "Inside Super's display method" << endl;
  }
};

int main()
{

  //point to the Child class object using a pointer to the Parent class
  Super *ptr;
  ptr = new Sub();
  //calls the Sub's display method
  ptr->display();
  //calls the Super's show method, as it is not declared as virtual
  ptr->show();
}