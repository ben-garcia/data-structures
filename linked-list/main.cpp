#include <iostream>

#include "Bag3.h"

using namespace std;
using namespace main_savitch_5;

int main() {
  Bag bag;

  cout << "manyNodes: " << bag.size() << endl;
  
  bag.insert(30.0);
  bag.insert(10.0);
  bag.insert(20.0);
  bag.insert(30.0);
  bag.insert(40.0);

  cout << "number of 30.0 is: " << bag.count(30.0) << endl;
  cout << "grab: " << bag.grab() << endl;
  cout << "manyNodes after: " << bag.size() << endl;

  return 0;
}