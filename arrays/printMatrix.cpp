#include <iostream>
using namespace std;
//print matrix as follows
/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
void printMatrix(int n);

void printMatrix(int n)
{
  int counter = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << counter << " ";
      ++counter;
    }
    cout << endl;
  }
}

int main()
{
  printMatrix(4);
}
