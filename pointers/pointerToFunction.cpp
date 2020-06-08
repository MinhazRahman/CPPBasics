#include <iostream>
using namespace std;

void display()
{
  cout << "Hi there!" << endl;
}

int main()
{
  //declare pointer to a function
  void (*fp)();
  //initialize the pointer
  fp = display;
  //call the function through pointer
  (*fp)();

  return 0;
}