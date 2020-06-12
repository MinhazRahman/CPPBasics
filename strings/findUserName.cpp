#include <iostream>
using namespace std;

string findUserName(string email)
{
  string userName = "";
  for (int i = 0; email[i] != '@'; i++)
  {
    userName += email[i];
  }
  return userName;
}

string getUserName(string email)
{
  return email.substr(0, email.find('@'));
}

string getDomainName(string email)
{
  return email.substr(email.find('@') + 1, email.length());
}

int main()
{
  string email = "abc123@example.com";
  cout << findUserName(email) << endl;
  cout << getUserName(email) << endl;
  cout << getDomainName(email) << endl;

  return 0;
}