#include <iostream>
using namespace std;

/*
Dynamic array
*/
int *insert(int *arr, int size, int x)
{

  return arr;
};
int main()
{
  //create an array dynamically
  int size = 5;
  int *array = new int[size];

  //delete the array
  delete[] array;
  //create another array
  int *temp = new int[10];
  //old pointer to the array, points to the new array
  array = temp;

  return 0;
}