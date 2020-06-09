#include <iostream>
using namespace std;

//global and local variables in c++
//global variables are accessible throughout the program
//and exist as long as the program is running.
//there is a separate memory area for global variables which 
//is inside the source code section

//global variable
int globalVar = 0;

void foo()
{
  globalVar++;
  cout << globalVar << endl;
}
int main()
{
  globalVar++;
  cout << "Inside main: " << globalVar << endl;
  foo();

  return 0;
}