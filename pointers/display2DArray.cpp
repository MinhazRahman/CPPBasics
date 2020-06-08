#include <iostream>
using namespace std;

/*
Type casting a hex address into int pointer
int *q = (int *)0x7ffeeeab3690;
*/

//display elements of a two dimensional array using pointer
void display(int *arr, int, int);
void print(int *arr, int, int);

//display array elements using deferencing syntax
void display(int *arr, int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << *(arr + i * col + j) << " "; //using deferencing syntax
    }
    cout << endl;
  }
}

//display array elements using pointer
void print(int *arr, int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << arr[i * col + j] << " "; //using pointer
    }
    cout << endl;
  }
}

int main()
{
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  //deep dive into pointers
  cout << arr << endl;
  cout << (int *)arr << endl;
  cout << &arr[0][0] << endl;
  //type cast the pointer arr (that contains hex address) into int pointer
  //since display() method accepts an int pointer
  //for example arr = 0x7ffeeeab3690, int *q = (int *)0x7ffeeeab3690
  int *p = (int *)arr;
  display(p, 2, 3);

  cout << endl;

  //type cast the pointer arr (that contains hex address) into int pointer
  //since print() method accepts an int pointer
  print((int *)arr, 2, 3);

  return 0;
}