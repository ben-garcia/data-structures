/*
  FILE: Stack1.h (part of the namespace main_savitch_7A)
  TEMPLATE CLASS PROVIDED: Stack<Item>

  TEMPLATE PARAMETER, TYPEDEFS, and MEMBER CONSTANTS for the Stack<Item> class:
    The template parameter, item, is the data type of the items of the stack, also defined
    as Stack<Item>::valueType. It may be any of the C++ built-in types (int, char, etc.), or a
    class with a default constructor, a copy constructor, and an assignment operator.
    The definition Stack<iTem>::sizeType is the data tpye of any variable that keep track of
    how many items are in a stack. For this implementation, Stack<Item>::CAPACITY
    is the maximum capacity of any stack (once CAPACITY is reached, further pushes are forbidden).

  CONSTRUCTOR for the Stack<Item> template class:
    Stack()
      Postcondition: The stack has been initialized as an empty stack.

  MODIFICATION MEMBER FUNCTIONS for the Stack<Item> template class:
    void push(const Item& entry)
      Precondition: size() < CAPACITY.
      Postcondition: A new copy of entry has been pushed onto the stack.
    void pop()
      Precondition: size() > 0
      Postcondition: The top item of the stack has been removed.
  CONSTANT MEMBER FUNCTIONS for the Stack<Item> template class:
    Item top() const
      Precondition: size() > 0.
      Postcondition: The return value is the top iem of the stack, but the stack is
      unchanged. This differs slightly from the STL stack (where the top function return a 
      reference to the item on top of the stack).

    sizeType size() const
      Postcondition: The return value is the total number of items in the stack.o
    
    bool empty() const
      Postcondition: The return value is true if the stack is empty, and false otherwise.

  VALUE SEMANTICS for the Stack<Item> template class:
    Assignments and the copy constructor may be used with Stack<Item> objects.
*/

#ifndef MAIN_SAVITCH_7A
#define MAIN_SAVITCH_7A

#include <cstdlib>      // Provides size_t

namespace main_savitch_7A {
  template <class Item>
  class Stack {
    public:
      // TYPEDEFS AND MEMBER CONSTANT
      typedef std::size_t sizeType;
      typedef Item valueType;
      static const sizeType CAPACITY = 30;

      // CONSTRUCTOR
      Stack() { used = 0; }

      // MODIFICATION MEMBER FUNCTIONS
      void push(const Item& entry);
      void pop();

      // CONSTANT MEMBER FUNCTIONS
      bool empty() const { return (used == 0); }
      sizeType size() const { return used; }
      Item top() const;
    
    private:
      Item data[CAPACITY];    // Particially filled array.
      sizeType used;          // How much of array is being used.
  };
}

#include "Stack1.template"    // Include the implementation.
#endif