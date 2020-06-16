#include <iostream>
using namespace std;
/*
Ways of achieving inheritance:
1. inherit using public access modifier
2. inherit using protected access modifier
3. inherit using private access modifier
*/

//create a class A
class A
{
private:
  int a;

protected:
  int b;

public:
  int c;
  A(int a, int b, int c)
  {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  //can acces all the private, protected and public variables
  void display()
  {
    a = 5;
    b = 10;
    c = 15;
    cout << a << " " << b << " " << c << endl;
  }
};

//Derive a class B from class A, the protected and public members of class A
//become public and protected members, respectively of class B.

class B : public A
{
public:
  void display()
  {
    //a = 10; //can't access the private members
    b = 15; // b is a protected member of B
    c = 20; //c is a public member of B
    cout << b << " " << c << endl;
  }
};

//Derive a class C from class A, that inherits the protected and public members of class A
//as protected members of its own
class C : protected A
{
public:
  void display()
  {
    //a = 10, //can't access the private member a
    b = 20; //b is now a protected member of class C
    c = 30; //c is now a protedted member of class C
    cout << b << " " << c << endl;
  }
};

//derive a class D from class A, that inherits the protected and public members of class A
//as private members of its own
class D : private A
{
public:
  void display()
  {
    //a = 10, //can't access the private member a
    b = 30; //b is now a private member of class D
    c = 40; //c is now a private member of class D
    cout << b << " " << c << endl;
  }
};

//derive a class E from class D, class E can't inherit the private members from class D
class E : public D
{
private:
  int x;

public:
  void display()
  {
    x = 10;
    //b = 30; //can't access private member of class D
    //c = 40; //can't access private member of class D
  }
};

int main()
{
  //On an object, we can only access public members
  A obj(10, 20, 30);
  cout << obj.c << endl;

  return 0;
}