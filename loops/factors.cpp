#include <iostream>
using namespace std;

//function declaration
int factors(int);

//gets factors of a number
int factors(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cout << i << endl;
    }
  }

  return 0;
}

int main()
{
  //call the function
  factors(12);
}