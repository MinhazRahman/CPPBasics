#include <iostream>
using namespace std;
//find an element in an sorted array using binary search algorithm
int search(int[]);

//returns the index where the element is found otherwise returns -1
int search(int *arr, int n, int x)
{
  int start = 0;
  int end = n - 1;
  int mid = 0;

  //iterate through the array till start == end
  while (start <= end)
  {
    mid = (start + end) / 2;

    if (x < arr[mid])
    {
      end = mid - 1;
    }
    else if (x > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}

int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(a) / sizeof(a[0]); // number of elements

  cout << "Found element at index: " << search(a, n, 1) << endl;
  cout << "Found element at index: " << search(a, n, 9) << endl;
  cout << "Found element at index: " << search(a, n, 10) << endl;
}
