#include <iostream>
#include <fstream>
using namespace std;

/*
Destructors are used to release resources acquired by the program:
  - delete unused objects
  - close files
  - release network connections
*/

class Demo
{
private:
  //an integer pointer
  int *ptr;
  //write to or read from a file
  fstream file;

public:
  //constructor
  Demo()
  {
    //create an array on the heap
    ptr = new int[5];
    //open a file
    file.open("test.txt");
    //write on the file
    file << "This is first line" << endl;
  }

  //destructor
  ~Demo()
  {
    //delete the array from the heap
    delete[] ptr;
    //close the file
    file.close();
  }
};

int main()
{
  //create an object
  Demo *d = new Demo(); //constructor will be called
  //delete the object
  delete d; //destructor will be called
}