#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Iterating over array
  int a[] = {0, 1, 2, 3, 4, 5};

  for (int n : a)
  {
    cout << n << " ";
  }
  cout << endl;
}