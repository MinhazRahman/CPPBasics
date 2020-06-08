#include <iostream>
using namespace std;
/*
C++ does not allow to pass an entire array as an argument to a function. 
However, You can pass a pointer to an array by specifying the array's name without an index.
*/

//function declaration
void display(int *arr);

//display array elements, *arr points to the memory address of the first element
//*arr = a[0], *(arr + i) = arr[i]
void display(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << *(arr + i) << endl;
  }
}

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  display(arr, n);

  return 0;
}