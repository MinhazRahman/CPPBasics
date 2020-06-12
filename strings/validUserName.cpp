#include <iostream>
#include <iterator>
#include <string>
#include <regex>

using namespace std;

string getUserName(string email)
{
  return email.substr(0, email.find('@'));
}

//check if a user name contains only letters(upper case or lower case),
//digits(0-9), underscores(_) or dots(.)
bool isValid(string userName)
{
  //match a letter(upper case and lower case) or an underscore(_) or a dot(.) or a digit(0-9)
  regex pattern("[a-zA-z_.0-9]+");
  return regex_match(userName, pattern);
}

int main()
{
  string email = "abc#123@gmail.com";

  string userName = getUserName(email);
  bool valid = isValid(userName);

  cout << boolalpha << valid << endl;
  cout << boolalpha << isValid("abc123") << endl;
  cout << boolalpha << isValid("____") << endl;
  cout << boolalpha << isValid("....") << endl;
  cout << boolalpha << isValid("abc%123") << endl;

  return 0;
}