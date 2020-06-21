#include <iostream>
using namespace std;

#ifndef PI //if PI is not defined then define it, otherwise don't define it
#define PI 3.14
#endif

#define PI 3.14
#define c cout
#define square(x) (x * x)
#define msg(x) #x //x will be enclosed in double quotes

/*
Preprocessor directives/macros are instructions for the compiler.
1. In preprocessor directives the symbols will be replaced by the values before the 
  compilation process starts.
2. 
*/

int main()
{
  //all the symbols will be replaced before the compilation process
  cout << PI << endl;         //PI will be replaced by 3.14
  c << PI << endl;            //c will replaced by cout
  cout << square(10) << endl; //square(10) will be replaced by 10*10 = 100
  cout << msg(hello) << endl; //the paremeter will be a string

  return 0;
}