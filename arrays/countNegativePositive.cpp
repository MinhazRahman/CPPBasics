#include <iostream>
using namespace std;
//count negative and positive numbers
void count(int[]);

//counts positive and negative numbers in an array
void count(int *arr, int n)
{
  int pcount = 0;
  int ncount = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      ++pcount;
    }
    else
    {
      ++ncount;
    }
  }

  cout << "Positive count: " << pcount << endl;
  cout << "Negative count: " << ncount << endl;
}

int main()
{
  int a[] = {2, 4, 5, -6, 7, 3, -9};
  int n = sizeof(a) / sizeof(a[0]); // number of elements

  count(a, n);
}