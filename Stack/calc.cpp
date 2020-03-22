/*
  FILE: calc.cpp
  Basic calculator program to evaluate a fully parenthesized arithmetic expression.
  The purpose is to illustrate a fundamental use of stacks.
*/

#include <cctype>       // Provices isdigit
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <cstring>      // Provides strchr
#include <iostream>     // Provides cout, cin, peek, ignore
#include <stack>        // Provides the stack template class

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
double readAndEvaluate(istream& ins);
// Precondiiton: The next line of characters in the istream ins is a fully parenthesized
// expression formed from non-negative numbers and the four operations +, -, *, /.
// Postcondition: A line has been read from the istream ins, and this line has been evaluated
// as an arithmetic expression. The value of the expression has been returned by the function.

void evaluateStackTops(stack<double>& numbers, stack<char>& operations);
// Precondition: The top of the operations stack contains +, -, *, or /, and the numbers stack
// contains at least two numbers.
// Postcondition: The top two numbers have been popped from the numbers stack, and the top
// operations has been popped from the operations stack. The two numbers have been
// combined using the operation (with the second number popped as the left operand). The
// result of the operation has then been pushed back onto the numbers stack.

int main() {
  double answer;

  cout << "Type a fully parenthesized arithmetic expression:" << endl;
  answer = readAndEvaluate(cin);
  cout << "That evaluates to " << answer << endl;

  return EXIT_SUCCESS;
}

double readAndEvaluate(istream& ins) {
  const char DECIMAL = '.';
  const char RIGHT_PARENTHESIS = ')';

  stack<double> numbers;
  stack<char> operations;
  double number;
  char symbol;

  // Loop continues while istream is not "bad" (tested by ins) and next character isn't newline
  while (ins && ins.peek() != '\n') {
    if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
      ins >> number;
      numbers.push(number);
    }
    else if (strchr("+-*/", ins.peek()) != NULL) {
      ins >> symbol;
      operations.push(symbol);
    }
    else if (ins.peek() == RIGHT_PARENTHESIS) { 
      ins.ignore();
      evaluateStackTops(numbers, operations);
    }
    else {
      ins.ignore();
    }
  }
  return numbers.top();
}

void evaluateStackTops(stack<double>& numbers, stack<char>& operations) {
  double operand1, operand2;

  operand2 = numbers.top();
  numbers.pop();
  operand1 = numbers.top();
  numbers.pop();
  switch (operations.top()) {
    case '+':
      numbers.push(operand1 + operand2);
      break;
    case '-':
      numbers.push(operand1 + operand2);
      break;
    case '*':
      numbers.push(operand1 + operand2);
      break;
    case '/':
      numbers.push(operand1 + operand2);
      break;
  }
  operations.pop();
}