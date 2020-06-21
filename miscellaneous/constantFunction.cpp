#include <iostream>
using namespace std;

class Demo
{

private:
  int x = 10;
  int y = 5;

public:
  void modify()
  { //can modify x and y
    x++;
    cout << x << " " << y << endl;
  }
  void display() const
  {
    //x++; //can't modify x and y
    cout << x << " " << y << endl;
  }

  //paremeters are constants
  int add(const int &x, const int &y)
  {
    //x++; //can't modify x or y
    return x + y;
  }
};

int main()
{
  Demo d;
  d.modify();
  d.display();

  return 0;
}