#include <iostream>
using namespace std;

/*Compile, Link and Run multiple files:
1. compile the .cpp files into object files (.o files)first:
$ clang++ -c add.cpp addMain.cpp  

2. Link object code files (.o files) into an executable called "sample":
$ clang++ add.o addMain.o -o sample

3. Run the executable file "sample":
$ ./sample

*/

int add(int, int);

int main()
{

  cout << add(5, 5) << endl;

  return 0;
}