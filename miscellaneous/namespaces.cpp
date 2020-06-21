#include <iostream>
using namespace std;

/*
Namespaces are used to resolve name conflicts that occur in the code 
*/

namespace first
{
  int add(int x, int y)
  {
    return x + y;
  }
} // namespace first

namespace second
{
  int add(int x, int y)
  {
    return x + y;
  }
} // namespace second

using namespace first;
int main()
{
  cout << add(3, 4) << endl; //will call the add() method that is in the first namespace
  cout << second::add(5, 6) << endl;

  return 0;
}