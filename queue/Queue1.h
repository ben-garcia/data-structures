/**
 * FILE: Queue1.h (part of the namespace mani_savitch_8B)
 * TEMPLATE CLASS PROVIDED: Queue<Item> (a queue of items)
 * 
 * TEMPLATE PARAMETER, Item, is the data type of the items in the queue, also defined
 * as Queue<Item>::valueType. It may be any of the C++ built-in types (int, char, etc.), or a
 * class with a default constructor, a copy constructor, and an assignment operator. The
 * definition Queue<Item>::sizeType is the data type of any variable that keeps track of how
 * many items are in a queue. The static const CAPACITY is the maximum capacity of a
 * queue for this first queue inplementation.
 * 
 * CONSTRUCTOR for the Queue<Item> template class:
 *  Queue()
 *    Postcondition: The queue has been initialized as an empty queue.
 * 
 * MODIFICATION MEMBER FUNCTIONS for the Queue<Item> template class:
 *  void pop()
 *    Precondition: size() > 0.
 *    Postcondition: The top item of the queue has been removed.
 * 
 *   void push(const Item& entry)
 *    Postcondition: A new copy of entry has been inserted at the rear of the queue.
 * 
 * CONSTANT MEMBER FUNCTIONS for the Queue<Item> template class:
 *  bool empty() const
 *    Postcondition: The return value is true if the queue is empty.
 * 
 *  Item front() const
 *    Precondition: size() > 0
 *    Postcondition: The return value is the front item of the queue (but this item is not
 *    removed from the queue).
 * 
 *  sizeType size() const
 *    Postcondition: The return value is the total number of items in the queue.
 */ 

#ifndef MAIN_SAVITCH_QUEUE1_H
#define MAIN_SAVITCH_QUEUE1_H

#include <cstdlib>    // Provides size_t

namespace main_savitch_8B {
  template <class Item>
  class Queue {
    public:
      // TYPEDEFS and MEMBER CONSTANTS
      typedef std::size_t sizeType;
      typedef Item valueType;
      static const sizeType CAPACITY = 30;

      // CONSTRUCTOR
      Queue();

      // MODIFICATION MEMBER FUNCTIONS
      void pop();
      void push(const Item& entry);

      // CONSTANT MEMBER FUNCTIONS
      bool empty() const { return (count == 0); }
      Item front() const;
      sizeType size() const { return count; }

    private:
      Item data[CAPACITY];    // Circular array.
      sizeType first;         // Index of item at the front of the Queue.
      sizeType last;          // Index of item at the rear of the Queue.
      sizeType count;         // Total number of items in the Queue.
      // HELPER MEMBER FUNCTION
      sizeType nextIndex(sizeType i) const { return (i + 1) % CAPACITY; };
  };
}

#include "Queue1.template"    // Include the implementation

#endif