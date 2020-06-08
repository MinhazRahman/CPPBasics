#include <iostream>
using namespace std;

int main()
{
  //declare and initialize a data variable
  int x = 30;
  //declare and initialize a reference variable
  //a reference variable has to be initialized whenever it is declared
  int &y = x; //x and y refers to the same memory location hence, their value is same

  cout << x << endl;
  cout << y << endl;

  cout << endl;
  //increment
  x++;
  cout << x << endl;
  cout << y << endl;

  cout << endl;
  //decrement
  y--;
  cout << x << endl;
  cout << y << endl;

  return 0;
}