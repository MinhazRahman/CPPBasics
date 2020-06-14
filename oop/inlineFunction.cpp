#include <iostream>
#include <string>
using namespace std;

/*Inline function
Inline functions are expanded at the same place where they are called.
If we call an inline function inside main() function then its machine code
will reside inside the main() function.

In the following diagram fun1 and fun2 are inline functions.

fun3
-----------
-----------
-----------
main
------------
------------
------------
  fun1------
      ------
      ------
  fun2------
      ------
      ------
------------ fun3();
------------
*/

class Test
{
private:
  string name;
  int age;

public:
  Test(string, int);
  //inline function
  void fun1()
  {
    cout << "inside inline fun1" << endl;
  }
  //inline function
  inline void fun2();
  //non-inline function
  void fun3();
};

int main()
{
  //create an object
  Test t("Jon", 30);
  t.fun1();
  t.fun2();
  t.fun3();

  return 0;
}

Test::Test(string name, int age)
{
  this->name = name;
  this->age = age;
}
void Test::fun2()
{
  cout << "inside inline fun2" << endl;
}

void Test::fun3()
{
  cout << "inside fun3" << endl;
}