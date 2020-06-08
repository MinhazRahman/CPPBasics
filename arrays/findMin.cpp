#include <iostream>
using namespace std;

//write a program to find max array element
int findMin(int[]);

//finds maximum array element
int findMin(int *arr, int n)
{
  int min = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

int main()
{
  int a[] = {4, 1, 6, 8, 10};
  int n = sizeof(a) / sizeof(a[0]); //number of elements
  cout << "Min value: " << findMin(a, n) << endl;
}