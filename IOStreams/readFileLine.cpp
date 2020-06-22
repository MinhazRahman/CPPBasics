#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Read a file line by line
*/

int main()
{
  //declare the fstream variable
  fstream file;
  //open the file
  file.open("./example.txt");
  //check if the file is open or not
  if (!file.is_open())
  {
    cerr << "Can't open the file!" << endl;
    exit(1); //call system to stop
  }
  //declare a string line
  string line;
  //read the file line by line till the EOF
  while (getline(file, line))
  {
    cout << line << endl;
  }
  //close the file
  if (file.is_open())
  {
    file.close();
  }
}