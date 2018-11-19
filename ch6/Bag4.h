/*
  FILE: Bag4.h (part of the namespace main_savitch_6A)
  TEMPLATE CLASS PROVIDED: Bag<Item>

  TEMPLATE PARAMETER, TYPEDEFS, and MEMBER CONSTANTS for the Bag<Item> class:
    The template parameter, Item, is the data type of the items in the bag, also defined as
    Bag::valueType. It may be any of the C++ built-in types (int, char, etc.), or a class with a
    default constructor, a copy constructor, an assignment operator, and operators to test for
    equality (x == y) and non-equality (x != y). The definition Bag::sizeType is the data type of
    any variable that keep strack of how many items are in a Bag. The static const DEFAULT_CAPACITY 
    is the initial capacity of a Bag created by the default constructor.

  CONSTRUCTOR for the Bag<Item> template class:
    Bag(sizeType initialCapacity = DEFAULT_CAPACITY)
      Postcondition: The Bag is empty with the specified initial capacity. The insert
      function works efficiently (without allocating a new memory) until the capacity
      is reached.

  MODIFICATION MEMBER FUNCTIONS for the Bag<Item> template class:
    sizeType erase(const Item& target)
      Postcondition: All copies of target have been removed from the Bag.
      The return value is the number of copies removed (which could be zero).

    bool eraseOne(const Item& target)
      Postcondition: If target was in the Bag, then one copy has been removed;
      otherwise the Bag is unchanged. A true return value indicates that one copy was
      removed; false indicates that nothing was removed.

    void insert(const Item& entry)
      Postcondition: A new copy of entry has been inserted into the Bag.

    void operator +=(const Bag& addend)
      Postcondition: Each item is addend has been added to this Bag.
    
    void reserve(sizeType newCapacity)
      Postcondition: The Bag's current capacity is changed to the newCapacity (but not less
      than the number of items in the bag). The insert function will work efficiently (without
      allocating new memory) until the new capacity is reached.

  CONSTANT MEMBER FUNCTIONS for the Bag<Item> template class:
    sizeType count(const Item& target) const
      Postcondition: Return value is the number of times target is in the bag.

    Item grab() const
      Precondition: size() > 0
      Postcondition: The return value is a randomly selected item from the bag.

    sizeType size() const
      Postcondition: The return value is the total number of items in the bag.
  
  NONMEMBER FUNCTIONS for the Bag<Item> template class:
    Bag<Item> operator +(const Bag<Item>& b1, const Bag<Item>& b2)
      Postcondition: The bag returned is the union of b1 and b2.
  
  VALUE SEMANTICS: Assignments and the copy constructor may be used with bag objects.
  DYNAMCI MEMORY USAGE by the Bag<Item> template class:
    If there is insufficient dynamic memory, then the following functions throw bad_alloc:
    the constructors, reserve, isnert, operator +=, operator +, and the assignment operator.
 */

 #ifndef MAIN_SAVITCH_BAG4_H
 #define MAIN_SAVITCH_BAG4_H

 #include <cstdlib>   // Provides size_t

 namespace main_savitch_6A {
   template <class Item>
   class Bag {
     public:
      // TYPEDEFS and MEMBER CONSTANTS
      typedef Item valueType;
      typedef std::size_t sizeType;
      static const sizeType DEFAULT_CAPACITY = 30;

      // CONSTRUCTORS and DESTRUCTOR
      Bag(sizeType intialCapacity = DEFAULT_CAPACITY);
      Bag(const Bag& source);
      ~Bag();

      // MODIFICATION MEMBER FUNCTIONS
      sizeType erase(const Item& target);
      bool eraseOne(const Item& target);
      void insert(const Item& entry);
      void operator =(const Bag& source);
      void operator +=(const Bag& addend);
      void reserve(sizeType capacity);

      // CONSTANT MEMBER FUNCTIONS
      sizeType count(const Item& target) const;
      Item grab() const;
      sizeType size() const { return used; }

    //private:
      Item *data;         // Pointer to partially filled dynamic array
      sizeType used;      // How many of array is being used
      sizeType capacity;  // /Current capacity of the bag
   };

   // NONMEMBER FUNCTION
   template <class Item>
   Bag<Item> operator +(const Bag<Item>& b1, const Bag<Item>& b2);
 }

// Most compilers require theimplementation file to be included in the header
// file for a template class.
#include "Bag4.template"    // Include the implementation
#endif