#include <iostream>
using namespace std;
/*
Difference between struct and class
1. in struct data and methods are by default public, 
a class has private and public members
*/
struct Demo
{
  int x;
  int y;

  void display()
  {
    cout << x << " " << y << endl;
  }
};

int main()
{
  Demo d;
  d.x = 10;
  d.y = 3;
  d.display();
}