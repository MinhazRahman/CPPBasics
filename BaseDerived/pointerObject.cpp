#include <iostream>
#include <string>
using namespace std;

/*
1. A Base class pointer can point to a derived class object
2. But it's not possible for a Derived class pointer to point to Base class object

Base class pointer and derived class object
When a base class pointer points to a derived class object,
using that pointer, we can only access base class methods.
Base *p;
p = new Derived();
*/

//create a base class Animal
class Animal
{
private:
  string name;

public:
  Animal()
  {
  }
  Animal(string name)
  {
    this->name = name;
  }
  void walk()
  {
    cout << name << " is walking!!" << endl;
  }
  void eat()
  {
    cout << name << " is eating!!" << endl;
  }

  string getName()
  {
    return name;
  }
};

//create a class Bird that inherits from Animal class
class Bird : public Animal
{
public:
  Bird() : Animal() {}
  Bird(string name) : Animal(name)
  {
  }
  void fly()
  {
    cout << getName() << " is flying" << endl;
  }
};

int main()
{
  //Create a pointer of Animal class
  Animal *p;
  //pointer p points to Bird class object
  p = new Bird("Parrot"); //creates an object in the heap

  //using p we can call only those methods that are in Animal class
  //we can't call the methods that belong to the Bird class
  //not all Animals can fly() as Birds do.
  p->eat();
  p->walk();
  //p->fly(); //can't call fly() method, not all animals can fly

  cout << endl;
  //It's not possible for a Bird class pointer to point to Animal class object
  Bird *pb;
  //pb = new Animal("Animal"); //incompatible type
  pb = new Bird("Eagle"); //creates an object in the heap
  pb->eat();
  pb->walk();
  pb->fly(); //birds can fly

  cout << endl;
  //create objects in the stack memory
  Animal animal;
  Bird bird;
  //cannot initialize a variable of type 'Bird *' with an rvalue of type 'Animal *'
  //Bird *ptr = &animal;
  //initialize a variable of type 'Animal *' with an rvalue of type 'Bird *'
  Animal *ptr = &bird;

  return 0;
}