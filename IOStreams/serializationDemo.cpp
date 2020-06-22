#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
Serialization is the process of storing and retrieving the states of an object.
Write a program to store a list of items into a text file and retrieve those items
from the file into the console.
*/
class Item
{
private:
  string name;
  double price;
  int quantity;

public:
  Item(){};
  Item(string, double, int);
  string getName();
  double getPrice();
  int getQuantity();
  friend ofstream &operator<<(ofstream &, Item &);
  friend ifstream &operator>>(ifstream &, Item &);
};

//implementations
string Item::getName()
{
  return name;
}

double Item::getPrice()
{
  return price;
}

int Item::getQuantity()
{
  return quantity;
}

Item::Item(string name, double price, int quantity)
{
  this->name = name;
  this->price = price;
  this->quantity = quantity;
}

//save the item object into the file
ofstream &operator<<(ofstream &ofs, Item &item)
{
  ofs << item.name << endl;
  ofs << item.price << endl;
  ofs << item.quantity << endl;
  return ofs;
}

//retrieve the item object from the file
ifstream &operator>>(ifstream &ifs, Item &item)
{
  ifs >> item.name >> item.price >> item.quantity;
  return ifs;
}

int main()
{
  //create an Item object
  Item item("Pen", 2.99, 5);
  Item item1;

  //create an ofstream variable
  ofstream ofs;
  //open a file if it already exists, otherwise create the file and open it
  ofs.open("./item.txt");
  //check if the file is open or not
  if (!ofs.is_open())
  {
    cerr << "Can't open the file!" << endl;
    exit(1); //call system to stop
  }
  //save the item into the text file
  ofs << item;
  //close the file
  if (ofs.is_open())
  {
    ofs.close();
  }

  //deserialize an object
  ifstream ifs;
  ifs.open("./item.txt");
  //check if the file is open or not
  if (!ifs.is_open())
  {
    cerr << "Can't open the file!" << endl;
    exit(1); //call system to stop
  }
  //retrieve the object from the file
  ifs >> item1;
  cout << item1.getName() << endl;
  cout << item1.getPrice() << endl;
  cout << item1.getQuantity() << endl;
  //close the file
  if (ifs.is_open())
  {
    ifs.close();
  }

  return 0;
}