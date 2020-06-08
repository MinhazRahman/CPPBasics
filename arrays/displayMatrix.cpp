#include <iostream>
using namespace std;
const int MAX_ROW = 2;
const int MAX_COL = 3;
//display a two dimensional array or matrix
void display(int matrix[MAX_ROW][MAX_COL], int, int);

//this function takes a two dimensional array as parameter
//and display the elements
void display(int matrix[MAX_ROW][MAX_COL], int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  display(arr, 2, 3);
}