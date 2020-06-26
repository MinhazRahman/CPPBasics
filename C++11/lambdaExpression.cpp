#include <iostream>
using namespace std;

/*
- Lambda expression is used to define anonymous function
- [capture-list](paremeter-list)->returnType{body};
*/

int main()
{
  int a = 10;
  int b = 20;

  //lambda expression with no capture-list, parameter-list and return type
  //semicolon at the end of the statmement is important
  []() { cout << "A very basic lambda expression" << endl; }();

  //parameterized lambda expression
  [](int x, int y) { cout << "sum: " << x + y << endl; }(4, 5);

  //lambda expression that returns a value
  int sum = [](int x, int y) { return x + y; }(3, 7);
  cout << "sum: " << sum << endl;

  //a lambda expression that captures global variables and returns the sum
  sum = [a, b]() { return a + b; }();
  cout << "sum: " << sum << endl;

  //when we capture global variable by value, we can't modify them inside the lambda expression
  //sum = [a, b]() { return ++a + b; }(); //error

  //if we capture the global variables by reference, we can modify them inside the lambda expression
  sum = [&a, &b]() { return (++a) + (++b); }();
  cout << "sum: " << sum << endl;

  //capture all the global variables by reference
  sum = [&]() { return (++a) + (++b); }();
  cout << "sum: " << sum << endl;

  //global variables have been modified
  cout << "a: " << a << " "
       << "b: " << b << endl;

  return 0;
}