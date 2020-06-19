#include <iostream>
using namespace std;
/*
A global function can access only the public members of a class on the object of that class.
But if we declare the function as a friend function then it can access all the private, protected
and public members of the class.
*/

class Test
{
private:
  int a;

protected:
  int b;

public:
  Test(){};
  int c;
  friend void show();
};

//friend function show() can access all the private, protected and public members
//of class Test
void show()
{
  //create object of class Test
  Test t;
  //using object of class Test access the variables declared inside the class
  t.a = 10;
  t.b = 20;
  t.c = 30;

  cout << t.a << " " << t.b << " " << t.c << endl;
}

//global function display() can access only the public members of class Test
void display()
{
  //create object of class Test
  Test test;
  //using object of class Test access the variables declared inside the class
  //test.a = 10; //can't access the private variables
  //test.b = 20; //can't access the protected variables
  test.c = 30;

  cout << test.c << endl;
}

int main()
{
  //call the global function display()
  display();
  //call the friend function show()
  show();

  return 0;
}
