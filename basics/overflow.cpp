#include <iostream>
using namespace std;

//character overflow
int main()
{
  //range of char is -128 to 127
  char x = 127;
  ++x;
  cout << (int)x << endl;
  return 0;
}