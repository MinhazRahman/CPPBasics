#include <iostream>
using namespace std;

//write a program to add array elements

//function declaration
int add(int[]);

//add array elements
int add(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);
  cout << "Sum: " << add(a, n) << endl;
}