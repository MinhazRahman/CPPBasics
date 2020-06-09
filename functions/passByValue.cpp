#include <iostream>
using namespace std;

//write a program to swap values

void swap(int, int);

//swap values
void swap(int a, int b)
{
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
  //after swaping values
  cout << x << " " << y << endl;
}