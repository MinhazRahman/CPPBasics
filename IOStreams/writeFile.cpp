#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cout << "Writing to a file" << endl;
  //create a fstream object, it the file doesn't exist the it will create a file
  fstream fileOut("example.txt", ios::app); //ios::trunc
  //write to a file
  fileOut << "First" << endl;
  fileOut << 40;
  //close the file
  fileOut.close();

  return 0;
}