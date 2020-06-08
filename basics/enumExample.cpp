#include <iostream>
using namespace std;

// define an enum type
enum day
{
  sat,
  sun,
  mon,
  tue,
  wed,
  thu,
  fri
};

enum dept
{
  CSE = 1,
  EEE,
  IT,
  CIVIL
};
int main()
{
  //declare enum type variables
  day d1, d2, d3;
  dept dept1;

  //assign values
  d1 = sat;
  d2 = sun;

  cout << d1 << endl;
  cout << d2 << endl;

  cout << CSE << endl;
  cout << EEE << endl;
  cout << IT << endl;

  return 0;
}