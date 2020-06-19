#include <iostream>
using namespace std;
/*
We can use static variables to assign roll no to students
*/

class Student
{
private:
  int rollNo;
  static int addmissionSL;

public:
  Student()
  {
    rollNo = ++addmissionSL;
  }
  int getRollNo();
};

//declare the static variable outside of the class
int Student::addmissionSL = 100;
int Student::getRollNo()
{
  return rollNo;
}

int main()
{
  //create students
  Student s1;
  Student s2;

  //get the rollNo of each student
  cout << "Student 1: " << s1.getRollNo() << endl;
  cout << "Student 2: " << s2.getRollNo() << endl;

  return 0;
}