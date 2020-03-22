/*
  FILE: Stack2.h (part of the namespace main_savitch_7B)
  DYNAMIC MEMORY USAGE by the Stack<Item> template class:
    If there is insufficient dynamic memory, then the following functions throw bad_alloc:
    the copy constructor, push, and the assignment operator.
*/

#ifndef MAIN_SAVITCH_STACK2_H
#define MAIN_SAVITCH_STACK2_H

#include <cstdlib>      // Provides NULL and size_t

#include "Node2.h"      // Node template class from Figure 0.4 on page 326.

namespace main_savitch_7B {
  template <class Item>
  class Stack {
    public:
      // TYPEDEFS
      typedef std::size_t sizeType;
      typedef Item valueType;

      // CONSTRUCTORS and DESTRUCTOR
      Stack() { topPtr = NULL; }
      Stack(const Stack& source);
      ~Stack() { main_savitch_6B::listClear(topPtr); }

      // MODIFICATION MEMBER FUNCTIONS
      void push(const Item& entry);
      void pop();
      void operator =(const Stack& source);

      // CONSTANT MEMBER FUNCTIONS
      sizeType size() const { return main_savitch_6B::listLength(topPtr); }
      bool empty() const { return (topPtr == NULL); }
      Item top() const;

    private:
      main_savitch_6B::Node<Item> *topPtr;    // Points to top of stack
  };
}

#include "Stack2.template"    // Include the implementation
#endif