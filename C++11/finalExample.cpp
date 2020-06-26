#include <iostream>
#include <string>
using namespace std;

/*
Use of keyword final:
1. If we declare a class as final then that class can't be subclassed
2. A function declared as final can't be overridden
3. 
*/

class Super final
{
public:
  void show()
  {
    cout << "Inside Super class" << endl;
  }
};

class Sub : Super //Error a final class can't be inherited
{
public:
  void show()
  {
    cout << "Inside Sub class" << endl;
  }
};

int main()
{

  return 0;
}