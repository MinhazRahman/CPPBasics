#include <iostream>
using namespace std;

class Parent
{
public:
  Parent() {}
  void display()
  {
    cout << "Inside Parent's display method" << endl;
  }
};

//derive class Child from Parent class
class Child : public Parent
{
public:
  Child() : Parent() {}
  //override the display method
  void display()
  {
    cout << "Inside Child's display method" << endl;
  }
};

int main()
{
  //create object of Parent class
  Parent p;
  p.display();

  //create object of Child class
  Child c;
  //calls the Child class's display method
  c.display();
  //calls the Parent's display method using Child's object
  c.Parent::display();

  //point to the Child class object using a pointer to the Parent class
  Parent *ptr;
  ptr = new Child();
  //calls the Parent's display method
  ptr->display();
}