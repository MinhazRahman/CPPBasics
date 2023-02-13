#include <iostream>
using namespace std;

int main()
{
  string name;
  int age;
  string country;

  cout << "Please, enter your name:" << endl;
  getline(cin, name); // takes a string until we press enter key

  cout << "Please, enter your age:" << endl;
  cin >> age; // takes an int type data

  cout << "Please, enter your country:" << endl;
  cin >> country; // takes a string without the space

  cout << "Your name is: " << name << endl;
  cout << "Your age is: " << age << endl;
  cout << "Your country is: " << country << endl;

  return 0;
}