#include <iostream>
#include <string>
using namespace std;

/*
In modern C++ programming, the Standard Library includes smart pointers, 
which are used to help ensure that programs are free of memory and resource leaks and are exception-safe.

https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019
*/

class Song
{
private:
  string name;
  int ranking;

public:
  Song();
  Song(string, int);
  ~Song();
  void useRawPointer();
  void useSmartPointer();
  int getRanking();
};

Song::Song() {}

Song::Song(string name, int ranking)
{
  cout << "Inside the constructor" << endl;
  this->name = name;
  this->ranking = ranking;
}

Song::~Song()
{
  cout << "Inside the destructor" << endl;
}

int Song::getRanking()
{
  return ranking;
}

void Song::useRawPointer()
{
  // Using a raw pointer -- not recommended.
  Song *pSong = new Song("song", 1);

  // Use pSong...
  int top = pSong->getRanking();

  // Don't forget to delete!
  delete pSong;
}

void Song::useSmartPointer()
{
  // Declare a smart pointer on stack and pass it the raw pointer.
  unique_ptr<Song> song2(new Song("Nothing on You", 2));

  // Use song2...
  int top = song2->getRanking();

  //...

} // song2 is deleted automatically here.

int main()
{
  //create objects
  Song song;

  //call methods
  song.useRawPointer();
  song.useSmartPointer();

  return 0;
}