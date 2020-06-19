#include <iostream>
using namespace std;
/*
We can declare a class inside another class.

To suppresss c++11 extension warning use -std=c++11 as command line flag while
compiling the .cpp file:
compile: $ clang++ -std=c++11 -c innerClass.cpp
link: $ clang++ innerClass.o -o innerClass 
run: $ ./innerClass
*/
class Outer
{
private:
  int a;
  static int b;

public:
  Outer()
  {
    a = 0;
  }
  void display()
  {
    //access the members of Inner class inside an Outer class function
    cout << inner.x << endl;
    inner.show();
  }

  //inner class
  class Inner
  {
  public:
    int x = 10;
    void show()
    {
      //a = 10; //can't access non-static variable
      b = 20; //can access static variable
      cout << b << endl;
    }
  };
  //create an object of Inner class
  Inner inner;
};

//declare the static variable outside of the class
int Outer::b = 0;

int main()
{
  //create an object of Outer class
  Outer outer;
  //call Outer class function
  outer.display();

  return 0;
}