/*
  FILE: bag3.h (part of the namespace main_savitch_5)
  CLASS PROVIDED: bag (a collection of items, where each item may appear multiple times)

  TYPEDEF for the bag class:
  typedef ______ valueType
    Bag::valueType is the data type of the items in the bag. I may be any of the C++
    built-in types( int, char, etc.), or a class with a default constructor, a copy constructor,
    an assignment operator, and a test for equality (x == y).

  typedef _______ sizeType
    Bag::sizeType is the data type of any variable that keep strack of how many items are
    in the bag.

  CONSTRUCTOR for the Bag class:
    Bag()
      Postcondition: The Bag is empty.
  
  MODIFICTATION MEMBER FUNCTIONS for the Bag class:
    sizeType erase(const valueType& target)
      Postcondition: All copies of target have been removed from the bag. The return value
      is the number of copies removed (which could be zero).

    bool eraseOne(const valueType& target)
      Postcondition: If target was in the bag, then one copy of target has been removed from 
      the bag; otherwise the bag is unchanged. A true return value indicates that one copy 
      was removed; false indicates that nothing was removed.

    void insert(const valueType& entry)
      Postcondition: A new copy of entry has been inserted into the bag.

    void operator +=(const Bag& addend)
      Postcondition: Each item in addend has been added to the bag.

    CONSTANT MEMBER FUNCTIONS for the Bag class:
      sizeType size() const
        Postcondition: The return value is the total number of items in the bag.

      sizeType count(const valueType& target) const
        Postcondition: The return value is the number of times target is in the bag.
      
      valueType grab() const
        Precondition: size() > 0
        Postcondition: The return value is a randomly selected item from the bag.
      
      NONMEMBER FUNCTIONS for the Bag class:
        Bag operator +(const Bag& b1, const Bag& b2) 
          Postcodition: The bag returned is the union of b1 and b2.
        
      VALUE SEMANTICS for the bag class:
        Assignments and the copy constructor may be used with bag objects.
      
      DYNAMIC MEMORY USAGE by the bag:
        If there is insufficient dynamic memory, then the following functions throw bad_alloc:
          The constructors, insert, operator +=, operator +, and the assignment operator
*/

#ifndef MAIN_SAVITCH_BAG3_H
#define MAIN_SAVITCH_BAG3_H

#include <cstdlib>  // Provides size_t and NULL

#include "Node1.h"  // Provides Node class

namespace main_savitch_5 {
  class Bag {
    public:
      // TYPEDEFS
      typedef std::size_t sizeType;
      typedef Node::valueType valueType;

      // CONSTRUCTORS and DESTRUCTOR
      Bag();
      Bag(const Bag& source);
      ~Bag();

      // MODIFICATION MEMBER FUNCTIONS
      sizeType erase(const valueType& target);
      bool eraseOne(const valueType& target);
      void insert(const valueType& entry);
      void operator +=(const Bag& addend);
      void operator =(const Bag& source);

      // CONSTANT MEMBER FUNCTIONS
      sizeType size() const { return manyNodes; }
      sizeType count(const valueType& target) const;
      valueType grab() const;

    private:
      Node *headPtr;      // List head pointerl
      sizeType manyNodes; // Number of nodes on the list.
    };

    // NONMEMBER FUNCTIONS for the Bag class:
    Bag operator +(const Bag& b1, const Bag& b2);
}

#endif