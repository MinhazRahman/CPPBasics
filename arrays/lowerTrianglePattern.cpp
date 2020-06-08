#include <iostream>
using namespace std;
//draw a pattern as follows:
/*
* * * #
* * # #
* # # #
# # # #
*/
void draw();

void draw(int n)
{
  for (int row = 0; row < n; row++)
  {
    string pattern = "";
    for (int col = 0; col < n; col++)
    {
      if (row + col >= n - 1)
      {
        pattern += "*";
      }
      else
      {
        pattern += " ";
      }
    }
    cout << pattern << endl;
  }
}

int main()
{
  draw(5);
}