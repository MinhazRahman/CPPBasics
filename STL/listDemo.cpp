#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/*
Vectors are sequence containers representing arrays that can change in size.
*/

void display()
{
  //declare and initialize a vector
  list<int> l{4, 5, 6};
  int n = l.size();
  cout << "Size of the list is :" << n << endl;

  //insert values at the back
  l.push_back(7);
  l.push_back(8);

  //iterate over the array using for loop
  for (int n : l)
  {
    cout << n << endl;
  }
}

void show()
{
  //declare and initialize a vector
  list<int> l{4, 5, 6};
  int n = l.size();
  cout << "Size of the list is :" << n << endl;

  //insert values at the back
  l.push_back(7);
  l.push_back(8);

  //iterate over the array using iterator
  list<int>::iterator itr;
  for (itr = l.begin(); itr != l.end(); itr++)
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