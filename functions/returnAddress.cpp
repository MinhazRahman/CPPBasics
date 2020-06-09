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
int *add(int *arr);

int *add(int size)
{
  int *numbers = new int[size];
  for (int i = 0; i < size; i++)
  {
    numbers[i] = i + 1;
  }

  return numbers;
}

int main()
{
  //address returned by the add() function is stored in the ptr pointer
  int *ptr = add(5);

  //print the array
  cout << ptr[0] << endl;
  cout << ptr[4] << endl;

  return 0;
}