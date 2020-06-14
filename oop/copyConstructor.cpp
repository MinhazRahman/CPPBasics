#include <iostream>
using namespace std;

/*
Copy constructors:
1. shallow copy constructor
2. deep copy constructor
*/

class Department
{
private:
  int size;
  int *students;

public:
  Department(int size)
  {
    this->size = size;
    students = new int[size];
  }

  //shallow copy constructor
  /*   Department(Department &dept)
  {
    this->size = dept.size;
    this->students = dept.students
  } */

  //deep copy constructor
  Department(Department &dept)
  {
    this->size = dept.size;
    this->students = new int[this->size];
  }

  //member functions
  int getSize()
  {
    return size;
  }
};

int main()
{
  //create object
  Department cs(10);

  //create department using deep copy constructor
  Department cse(cs);

  cout << cs.getSize() << endl;
  cout << cs.getSize() << endl;
}