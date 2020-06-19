#include <iostream>
using namespace std;

//create a template class
template <class T>
class Stack
{
private:
  T *stack;
  int top;
  int size;

public:
  Stack(int);
  void push(T);
  T pop();
};

//define the constructor
template <class T>
Stack<T>::Stack(int n)
{
  size = n;
  stack = new T[size];
  top = -1;
}
//define the functions outside of the class
template <class T>
void Stack<T>::push(T x)
{
  //increment top and then insert the value in the array
  stack[++top] = x;
}

template <class T>
T Stack<T>::pop()
{
  //get the value from the stack and then decrement top
  T value = stack[top--];

  return value;
}

int main()
{
  //create object
  Stack<int> s(10);
  //push values in the stack
  s.push(1);
  s.push(2);
  s.push(3);

  cout << s.pop() << endl;

  return 0;
}
