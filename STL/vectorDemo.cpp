#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/*
Vectors are sequence containers representing arrays that can change in size.

*/

void display()
{
  //declare and initialize a vector
  vector<int> v{4, 5, 6};
  int n = v.size();
  cout << "Size of the vector is :" << n << endl;

  //insert values at the back
  v.push_back(7);
  v.push_back(8);

  //iterate over the array using for loop
  for (int n : v)
  {
    cout << n << endl;
  }
}

void show()
{
  //declare and initialize a vector
  vector<int> v{4, 5, 6};
  int n = v.size();
  cout << "Size of the vector is :" << n << endl;

  //insert values at the back
  v.push_back(7);
  v.push_back(8);

  //iterate over the array using iterator
  vector<int>::iterator itr;
  for (itr = v.begin(); itr != v.end(); itr++)
  {
    cout << *itr << endl;
  }
}

int main()
{
  display();
  show();

  return 0;
}