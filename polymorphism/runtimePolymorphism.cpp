#include <iostream>
#include <string>
using namespace std;

/*
A Super class pointer points to different Sub class objects at different times.
*/

class Car
{
private:
  string name;
  string type;
  string model;

public:
  Car(){};
  Car(string name, string type, string model)
  {
    this->name = name;
    this->type = type;
    this->model = model;
  }
  //pure virtual functions
  virtual void start() = 0;
  virtual void stop() = 0;
  //setters
  virtual void setName(string name)
  {
    this->name = name;
  }
  virtual void setType(string type)
  {
    this->type = type;
  }
  virtual void setModel(string model)
  {
    this->model = model;
  }
  //getters
  virtual string getName()
  {
    return name;
  }
  virtual string getType()
  {
    return type;
  }
  virtual string getModel()
  {
    return model;
  }
};

//Tesla inherits from Car
class Tesla : public Car
{
public:
  Tesla(string name, string type, string model) : Car(name, type, model){};
  void start()
  {
    cout << getName() << " " << getModel() << " started" << endl;
  }
  void stop()
  {
    cout << getName() << " " << getModel() << " stopped" << endl;
  }
};

//Honda inherits from Car
class Honda : public Car
{
public:
  Honda(string name, string type, string model) : Car(name, type, model){};
  void start()
  {
    cout << getName() << " " << getModel() << " started" << endl;
  }
  void stop()
  {
    cout << getName() << " " << getModel() << " stopped" << endl;
  }
};

int main()
{
  //create a pointer to the Car class, we can't create an object of Car class
  Car *car;
  //car points to the Tesla object
  car = new Tesla("Tesla", "Electric", "Model-S3");
  //call methods of the class Tesla
  car->start();
  car->stop();

  //car now points to the Honda object
  car = new Honda("Honda", "Gas", "Model-X");
  //call methods of the Honda class
  car->start();
  car->stop();

  return 0;
}