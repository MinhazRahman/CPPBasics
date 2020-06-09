#include <iostream>
using namespace std;

/*
Parameter passing:
We can pass a parameter to a function by.. 
1. value
2. address
3. reference

Return statement:
A function can return..
1. value
2. address
3. reference
*/

//write a function that returns an address
int *multiply(int *arr);

int *multiply(int *numbers, int size)
{
  for (int i = 0; i < size; i++)
  {
    ++numbers[i];
  }

  return numbers;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  //address returned by multiply() function is stored in the ptr pointer
  int *ptr = multiply(arr, n);

  //print the array
  cout << ptr[0] << endl;
  cout << ptr[n - 1] << endl;

  return 0;
}
