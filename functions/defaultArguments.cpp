#include <iostream>
using namespace std;

//defines a function add() with default parameter z
int add(int x, int y, int z = 0)
{
  return x + y + z;
}

int main()
{
  cout << add(1, 2, 0) << endl;
  cout << add(10, 2) << endl; //not pasing the third argument
}