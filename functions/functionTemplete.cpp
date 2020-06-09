#include <iostream>
using namespace std;

//create a function template
template <class T>
T maximum(T x, T y)
{
  return x > y ? x : y;
}

int main()
{
  int n = maximum(10, 5);
  float f = maximum(10.25f, 5.24f);

  cout << n << endl;
  cout << f << endl;
}