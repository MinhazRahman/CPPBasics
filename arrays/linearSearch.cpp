#include <iostream>
using namespace std;
//write a program to find an element in an array using linear search
int search(int[]);

//returns the index where the element is found otherwise returns -1
int search(int *arr, int n, int x)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(a) / sizeof(a[0]); // number of elements

  cout << "Found element at index: " << search(a, n, 5) << endl;
}
