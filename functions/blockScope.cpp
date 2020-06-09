#include <iostream>
using namespace std;

//global and local variables in c++
//global variables are accessible throughout the program
//and exist as long as the program is running
//C++ supports code block.

//global variable
int globalVar = 0;
int g = 0;

void foo()
{
  //local to function foo
  int g = 1;
  globalVar++;
  cout << "Inside foo:" << globalVar << endl;
  {
    //local to code block
    int g = 0;
    g++;
    cout << "Inside block:" << g << endl;
  }
  cout << "Inside foo:" << g << endl;
}
int main()
{
  globalVar++;
  cout << "Inside main: " << globalVar << endl;
  foo();

  return 0;
}