#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //create a ifstream variable
  ifstream file;
  //open the file
  file.open("./example.txt");
  //check if the file is open or not
  if (!file.is_open())
  {
    cerr << "Can't open the file!" << endl;
    exit(1); //call system to stop
  }
  //read from the stream in the same way as cin
  string str;
  int x;
  while (file >> str || file >> x)
  {
    cout << str << x << endl;
  }
  //close the file
  if (file.is_open())
  {
    file.close();
  }

  return 0;
}