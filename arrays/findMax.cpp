#include <iostream>
using namespace std;

//write a program to find max array element
int findMax(int[]);

//finds maximum array element
int findMax(int *arr, int n)
{
  int max = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int main()
{
  int a[] = {4, 1, 6, 8, 10};
  int n = sizeof(a) / sizeof(a[0]);
  cout << "Max value: " << findMax(a, n) << endl;
}