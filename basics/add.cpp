#include <iostream>
using namespace std;

/**
 *
 * When not overloaded, left-shift and right-shift and some people call them that even when used with streams,
 * but insertion and extraction is a lot more common in that context.
 * They are also sometimes informally called put to and get from.
 * Stroustrup favoured that last form
 *
 * This operator (<<) applied to an output stream is known as insertion operator.
 * This operator (>>) applied to an input stream is known as extraction operator.
 *
 * In case of std::cout, << is used to write to standard output. >> is not overloaded for std::cout.
 * So std::cout >> x would give compilation error.

* In case of std::cin, >> is used to read from standard input. << is not overloaded for std::cin.
* So std::cin <<  x would give compilation error.
 *
 */

int main()
{
  int a, b, c;

  // left-shift: insertion: put to: put the line to the console
  cout << "Enter two numbers" << endl;

  // right-shift: extraction: get from: get two numbers from keyboard
  cin >> a >> b;
  c = a + b;

  cout << c << endl;

  return 0;
}