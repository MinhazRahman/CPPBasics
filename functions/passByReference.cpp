#include <iostream>
using namespace std;

//write a program to swap values

void swap(int &a, int &b);

//swap values
void swap(int &a, int &b)
{
  //addresses of a and b
  cout << &a << " " << &b << endl;
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main()
{
  int x = 10, y = 20;

  //before swaping values
  cout << x << " " << y << endl;
  //will not swap values because we are passing parameters by values
  swap(x, y);
  //addresses of x and y, addresses of a and b will be same
  cout << &x << " " << &y << endl;
  //after swaping values
  cout << x << " " << y << endl;
}