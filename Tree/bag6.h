/**
 * FILE: bag6.h (part of the namespace main_savitch_10)
 * TEMPLATE CLASS PROVIDED: Bag<Item> (a container template class for a collection of items)
 * 
 * TYPEDEFS for the Bag<Item> class:
 *  Bag<Item>::valueType
 *    Bag<Item>::valueType is the data type of the items in the bag. It may be any of the
 *    C++ built-in types (int, char, etc.), or a lass with a default constructor, a copy constructor, an
 *    assignment operator, and a less-than operator forming a strict weak ordering.
 * 
 *  Bag<Item>::sizeType
 *    Bag<Item>::sizeType is the data type of any variable that keeps track of how many 
 *    items are in a bag.
 *
 * CONSTRUCTOR for the Bag<Item> class:
 *  Bag()
 *    Postcondition: The bag is empty.
 *  
 *  MODIFICATION MEMBER FUNCTIONS for the Bag<Item> class:
 *    siizeType erase(const Item& target)
 *      Postcondition: All copies of target have been removed from the bag. The return value
 *       is the number of copies removed (which could be zero).
 * 
 *    bool eraseOne(const Item& target)
 *      Postcondiiton: If target was in the bag, then one copy of target has been removed from 
 *      the bag; otherwise the bag is unchanged. A true return value indicates that one copy 
 *      was removed; false indicates that nothing was removed.
 * 
 *    void insert(const Item& entry)
 *      Postcondition: A new copy of entry has been inserted into the bag.
 * 
 *    void operator +=(const Bag& addend)
 *      Postcondition: Each item in addend has been added to this bag.
 * 
 * CONSTANT MEMBER FUNCTIONS for the Bag<Item> class:
 *  sizeType size() const
 *    Postcondition: Return value is the total number of items in the bag.
 * 
 *  sizeType count(const Item& target) const
 *    Postcondition: Return value is the number of times target is in the bag.
 * 
 * NONMEMBER FUNCTIONS for the Bag class:
 *  Bag operator +(const Bag& b1, const Bag& b2)
 *    Postcondition: The bag returned is the union of b1 and b2.
 * 
 * VALUE SEMANTICS for the Bag class:
 *  Assignments and the copy constructor may be used with bag objects.
 * 
 * DYMANIC MEMORY USAGE by the Bag:
 *  If there is insufficient dynamic memory, then the following functions throw bad_alloc:
 *  the constructors, insert, operator +=, operator +, and the assignment operator.
 * 
 * INVARIANT for the Sixth Bag class:
 *  1. The items in the bag are stored in a binary search tree.
 *  2. The root pointer of the binary search tree is stored in the
 *     member variable rootPtr (which may be null for an empty tree).
 */

#ifndef BAG6_H
#define BAG6_H

#include <cstdlib>  // Provides NULL and size_t

#include "bintree.h"  // Provides BinaryTreeNode and related functions

namespace main_savitch_10 {
template <class Item>
class Bag {
   public:
    // TYEPDEFS
    typedef std::size_t sizeType;
    typedef Item valueType;

    // CONSTRUCTORS and DESTRUCTOR
    Bag();
    Bag(const Bag& source);
    ~Bag();

    // MODIFICATION functions
    sizeType erase(const Item& target);
    bool eraseOne(const Item& target);
    void insert(const Item& entry);
    void operator+=(const Bag& addend);
    void operator=(const Bag& source);

    // CONSTANT functions
    sizeType size() const;
    sizeType count(const Item& target) const;

    //    private:
    BinaryTreeNode<Item>* rootPtr;  // Root pointer of binary search tree.

    void insertAll(const BinaryTreeNode<Item>* addRootPtr);
};

// NONMEMBER functions for the Bag<Item> template class:
template <class Item>
Bag<Item> operator+(const Bag<Item>& b1, const Bag<Item>& b2);

}  // namespace main_savitch_10

#include "bag6.template"  // include the implementation.
#endif