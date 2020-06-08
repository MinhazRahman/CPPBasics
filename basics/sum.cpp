#include <iostream>
using namespace std;

//calculate the sum of n natural number
int main()
{
  int sum = 0, n;

  cout << "Enter number: " << endl;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    sum += i;
  }

  cout << sum << endl;
  return 0;
}