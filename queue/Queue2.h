/**
 * FILE: Queue2.h
 */

#include <cstdlib>    // Provides size_t

#include "Node2.h"    // Node template class
#include "NodeIterator.h"

namespace main_savitch_8C {
  template <class Item>
  class Queue {
    public:
      // TYPEDEF
      typedef std::size_t sizeType;
      typedef Item valueType;
      typedef main_savitch_6B::NodeIterator<Item> iterator;

      // CONSTRUCTOR and DESTRUCTOR
      Queue();
      Queue(const Queue<Item>& source);
      ~Queue();

      // MODIFICATION MEMBER FUNCTIONS
      void pop();
      void push(const Item& entry);
      void operator =(const Queue<Item>& source);

      // CONSTANT MEMBER FUNCTIONS
      bool empty() const { return (count == 0); }
      Item front() const;
      sizeType size() const { return count; }

      // Iterator interface
      iterator begin() { return iterator(frontPtr); }
      iterator end() { return iterator(); }

    private:
      main_savitch_6B::Node<Item> *frontPtr;
      main_savitch_6B::Node<Item> *rearPtr;
      sizeType count;       // Total number of items in the Queue
  };
}

#include "Queue2.template"