#include <iostream>
using namespace std;

//create a function template
template <class T>
T maximum(T x, T y)
{
  return x > y ? x : y;
}

template <class T, class R>
R add(T a, R b)
{
  return a + b;
}

int main()
{
  int n = maximum(10, 5);
  float f = maximum(10.25f, 5.24f);

  cout << n << endl;
  cout << f << endl;

  cout << add(5, 5.5) << endl;

  return 0;
}