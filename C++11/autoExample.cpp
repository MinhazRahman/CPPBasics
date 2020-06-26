#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;

/*
The auto keyword specifies that the type of the variable that is begin declared will automatically be deduced
from its initializer and for functions if their return type is auto 
then that will be evaluated by return type expression at runtime
*/

// a variable can be declared as auto
void autoVariable()
{
  //declare a variable a and assign a value
  int a = 10;
  //assign the value of a to b, b is now of type int
  auto b = a;

  //we can write as follows, the type of c will be deduced
  //according to the assigned value
  auto c = 20;

  cout << typeid(b).name() << " " << b << endl;
}

//we can use auto in place of a very long type
void iterateOverVector()
{
  vector<string> teams;
  //insert values
  teams.push_back("Mats");
  teams.push_back("Giants");
  teams.push_back("Yankees");
  //get the iterator
  vector<string>::iterator itr;
  //iterate through the vector
  for (itr = teams.begin(); itr != teams.end(); itr++)
  {
    cout << *itr << endl;
  }

  cout << endl;
  //we can replace "vector<string>::iterator" by auto when iterating over a vector
  for (auto it = teams.begin(); it != teams.end(); it++)
  {
    cout << *it << endl;
  }
}

int main()
{
  iterateOverVector();

  return 0;
}