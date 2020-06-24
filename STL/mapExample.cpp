#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
map is an associative container that stores values in key-value pair

- difference between [] operator and insert() function
If specified key already existed in map then operator [] will silently change its value where as 
insert will not replace already added key instead it returns the information i.e. if element is added or not
*/

int main()
{
  //create map objects
  map<string, int> mapOfWords;
  //insert data in map using insert function
  mapOfWords.insert(make_pair("Java", 2));
  mapOfWords.insert(make_pair("C++", 1));
  mapOfWords.insert(make_pair("JavaScript", 3));
  //insert data in map using [] operator
  mapOfWords["Python"] = 4;

  //iterating through a map
  //Each entry in map<string, int> is pair<string, int> therefore through iterator,
  //key can be accessed by it->first and value by it->second
  map<string, int>::iterator itr;
  for (itr = mapOfWords.begin(); itr != mapOfWords.end(); itr++)
  {
    cout << itr->first << "::" << itr->second << endl;
  }

  return 0;
}