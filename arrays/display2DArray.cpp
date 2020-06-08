#include <iostream>
using namespace std;

//display a two dimensional array or matrix
void display(int *matrix, int, int);

//this function takes a two dimensional array as parameter
//and display the elements
void display(int *arr, int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << *(arr + i * col + j) << " ";
    }
    cout << endl;
  }
}

int main()
{
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  display((int *)arr, 2, 3);
}