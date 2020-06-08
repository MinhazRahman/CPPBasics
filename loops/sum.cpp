#include <iostream>
using namespace std;
//function definition
int sum(int);

//calculate sum of n natural numbers
int sum(int n)
{
  int sum = 0;
  // add numbers from 1 to n
  for (int i = 1; i <= n; i++)
  {
    sum += i;
  }

  return sum;
}

//sum of n natural numbers
int main()
{
  cout << sum(5) << endl;

  return 0;
}