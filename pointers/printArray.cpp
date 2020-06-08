#include <iostream>
using namespace std;

void display(int *arr);
void print(int *arr);

//using pointer to print elements of an one dimensional array
//display array elements using deferencing syntax
void display(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << *(arr + i) << endl; //using dereferencing syntax
  }
}

//print array elements using pointer
void print(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl; //using pointer
  }
}

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  display(arr, n);

  cout << endl;
  print(arr, n);

  return 0;
}