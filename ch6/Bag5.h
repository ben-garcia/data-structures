/*
  FILE: Bag5.h (part of the namespace main_savitch_6B)
  TEMPLATE CLASS PROVIDED: Bag<Item> (a collection of items; each item may appear multiple times.)

  TYPEDEFS for the Bag<Item> class:
    Bag<Item>::valueType
      Bag<Item>::valueType is the data type of the items in the bag. It may be any of the
      C++ built-in types (int, char, etc.), or a class with a defualt constructor, a copy
      constructor, an assignment operator, and a test for equality (x == y),
    Bag<Item>::sizeType
      Bag<Item>::sizeType is the data type of any variable that keeps track of how many 
      items are in a bag.

    Bag<Item>::iterator and Bag<Item>::constIterator
      Forward iterators for the Bag<Item> class:
  CONSTRUCTOR for the Bag<Item> class:
    Bag()
      Postcondition: The Bag is empty.
  
  MODIFICATION MEMBER FUNCTIONS for the Bag<Item> class:
    sizeType erase(const Item& target)
      Postcondition: All copies of target have been removed from the bag. The return value
      is the number of copies removed (which could be zero).

    bool eraseOne(const Item& target)
      Postconidition: If target was in the bag, then one copy of target has been removed from
      the bag; otherwise the bag is unchanged. A true return value indicates that one copy
      was removed; false indicates that nothing was removed.

    void insert(const Item& entry)
      Postcondition: A new copy of entry has been inserted into the bag.o
    
    void operator +=(const Bag& addend)
      Postcondition: Each item in addend has been added to this bag.

  CONSTANT MEMBER FUNCTIONS for the Bag<Item> class:
    sizeType count(const Item& target) const
      Postcondition: Return value is the number of times target is in the bag.

    Item grab() const
      Precondition: size() > 0
      Postcondition: The return value is a randomly selected item from the bag.
    
    sizeType size() const
      Postcondition: Retun value is the total number of items in the bag.

  STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
    iterator begin()
    constIterator begin() const
    iterator end()
    constIterator end() const

  NONMEMBER FUNCTIONS for the Bag<Item> class:
    template <class Item>
    Bag<Item> operator +(const Bag<Item>& b1, const Bag<Item>& b2)
      Postcondition: The bag returned is the union of b1 and b2.

  VALUE SEMANTICS for the Bag<Item> class:
    Assignments and the copy constructor may be used with bag objects.

  DYNAMIC MEMORY USAGE by the Bag<Item>
    If there is insufficient dynamic memory, then the following functions throw bad_alloc:
    the constructors, insert, operator +=, operator+, and the assignment operator.
*/

#ifndef MAIN_SAVITCH_BAG5_H
#define MAIN_SAVITCH_BAG5_H

#include <cstdlib>              // Provides NULL and size_t

#include "Node2.h"              // Provides Node class
#include "NodeIterator.h"       // Provides NodeIterator
#include "ConstNodeIterator.h"  // Provides ConstNodeIterator

namespace main_savitch_6B {
  template <class Item>
  class Bag {
    public:
      // TYPEDEFS
      typedef std::size_t sizeType;
      typedef Item valueType;
      typedef NodeIterator<Item> iterator;
      typedef ConstNodeIterator<Item> constIterator;

      // CONSTRUCTOR and DESCRUCTOR
      Bag();
      Bag(const Bag& source);
      ~Bag();

      // MODIFICATION MEMBER FUNCTIONS
      sizeType erase(const Item& target);
      bool eraseOne(const Item& target);
      void insert(const Item& entry);
      void operator +=(const Bag& addend);
      void operator =(const Bag& source);

      // CONST MEMBER FUNCTIONS
      sizeType count(const Item& target) const;
      Item grab() const;
      sizeType size() const { return manyNodes; }

      // FUNCTIONS TO PROVIDE ITERATORS
      iterator begin() { return iterator(headPtr); }
      constIterator begin() const { return constIterator(headPtr); }
      iterator end() { return iterator(); } // Uses default constructor
      constIterator end() const { return constIterator(); }  // Uses default constructor
    
    private:
      Node<Item> *headPtr;    // Head pointer for the list of items.
      sizeType manyNodes;     // Number of nodes on the list.
  };

  // NONMEMBER FUNCTIONS for the Bag<Item> template class
  template <class Item>
  Bag<Item> operator +(const Bag<Item>& b1, const Bag<Item>& b2);
}

// The implementation of a template class must be included in its ehader file:
#include "Bag5.template"

#endif