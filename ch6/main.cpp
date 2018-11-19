#include <iostream>
#include <cstdlib>
#include <string>

#include "Bag5.h"

using namespace std;
using namespace main_savitch_6B;

int main() {
  Bag<string> *numbers = new Bag<string>();
  numbers->insert("one");
  numbers->insert("two");
  numbers->insert("three");

  Bag<string>::iterator position;

  for (position = numbers->begin(); position != numbers->end(); ++position) {
    cout << *position << endl;
  }

  numbers = NULL;
  delete numbers;

  return EXIT_SUCCESS;
}
