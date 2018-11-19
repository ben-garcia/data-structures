#include <iostream>       // Provides cout

#include "Stack1.h"       // Partially filled array implementation
#include "Stack2.h"       // Linked list implementation

using namespace std;
using namespace main_savitch_7A;
using namespace main_savitch_7B;

int main() {
  main_savitch_7A::Stack<int> numbers;
  main_savitch_7B::Stack<int> stack2;

  numbers.push(10);
  numbers.push(20);
  numbers.push(30);

  cout << numbers.top() << endl;

  stack2.push(100);
  stack2.push(200);
  stack2.push(300);

  cout << stack2.top() << endl;

  return 0;
}