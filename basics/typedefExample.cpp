#include <iostream>
using namespace std;

// use of typedef
typedef int marks;
typedef int rollNumber;

int main()
{
  marks m1, m2, m3;
  rollNumber r1, r2, r3;

  m1 = 90;
  r1 = 1;

  cout << "Marks: " << m1 << ",Roll number: " << r1 << endl;

  return 0;
}