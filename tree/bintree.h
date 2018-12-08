/*
 FILE: bintree.h (part of the namespace main_savitch_10)
 PROVIDES: A template class for a node in a binary tree and functions for 
 manipulating binary trees. The template parameter is the type of data in each node.

 TYPEDEF for the BinaryTreeNode<Item> template class:
  Each node of the tree contains a piece of data and pointers to its children. The 
  type of the data (BinaryTreeNode<Item>::valueType) is the Item type from the template
  parameter. The type may be any of the C++ built-in types (int, char, etc.), or a class with 
  a default constructor, and an assignment operator.

  CONSTRUCTOR for the BinaryTreeNode<Item> class:
    BinaryTreeNode(
      const Item& initData= Item(),
      BinaryTreeNode<Item>* initLeft = NULL,
      BinaryTreeNode<Item>* initRight = NULL
    )
      Postcondition: The new node has its data equal to initData,
      and its child pointers equal to initLeft adn initRight

  MEMBER FUNCTIONS for the BinaryTreeNode<Item> class:
    const Item& data() const     <---- const version
    and
    Item& data()                 <---- non-const version
      Postcondition: The return value is a reference to the data from this BinaryTreeNode.
    
    const BinaryTreeNode* left() const <--- const version
    and
    BinaryTreeNode* left()             <--- non-const version
    and
    const BinaryTreeNode* right() const <--- const version
    and
    BinaryTreeNode* right()             <---- non-const version
      Postcondition: The return value is a pointer to the left or right child (which will be
      NULL if there is no child).

    void setData(const Item& newData)
      Postcondition: The BinaryTreeNode now contains the specified new data.

    void setLeft(BinaryTreeNode* new_link)
    and
    void setRight(BinaryTreeNode* new_link)
      Postcondition: The BinaryTreeNode now contains the specified new link to a child.
    
    bool isLeaf()
      Postcondtion: The return value is true if the node is a leaf; otherwise the return value 
      is false.

  NONMEMBER FUNCTIONS to manipulate binary tree nodes.
    template <class Process, class BTNode>
    void inorder(Process f, BTNode* nodePtr)
      Precondition: nodePtr is a pointer to a node in a binary tre(or node-ptr may be NULL
      to indicate the empty tree.)
      Postcondition: if nodePtr is non-NULL, then the function f hsa been applied to the
      contents of *nodePtr and all of its descendants, using an in-order traversal.
      Note: BTNode may be a BinaryTreeNode or a const binary tree node.
      Process is the type of a functiono f that may be called with a singled
      Item arguement (using the Item type from the node)

    template <class Process, class BTNode>
    void postorder(Process f, BTNode* nodePtr)
      Same as the in-order function, except with a post-order traversal.

    template <class Process, class BTNode>
    void preorder(Process f, BTNode* nodePtr)
      Same as the in-order function, except with a pre-order traversal

    template <class Item, class SizeType>
    void print(const BinaryTreeNode<Item>* nodePtr, SizeType depth)
      Precondition: nodePtr is a pointer to a node in a binary tree (or node-ptr may be
      NULL to inicate the empty tre). If the pointer is not NULL, depth is the depth of
      the node pointerd to by nodePtr.
      Postcondition: A representation of *nodePtr and all its descendants have been written
      to cout with the << operator. Each node is indented four times its depth.

    template <class Item>
    void treeClear(BinaryTreeNode<Item>*& rootPtr)
      Precondition: rootPtr is the root pointer of a binary tree (which may be NULL for the
      empty teee).
      Postcondition: All nodes at the root or below have been returne to the heap, and
      rootPtr has been set to NULL.
    
    template <class Item>
    BinaryTreeNode<Item>* TreeCopy(const BinaryTreeNode<Item>* rootPtr)
      Precondition: rootPtr is he root pointer of a binary tree (which may be NULL
      for the empty tree).
      Postcondition: A copy of the binary tree has been made, and the return value is a
      pointer to the root of this copy.

    template <class Item>
    size_t treeSize(const BinaryTreeNode<Item>* nodePtr)
      Precondition: ndoe_ptr is a pointer to a node in a BinaryTreeNode (or nodePtr may be 
      NULL to indicate th empty tee).
      Postcondition: The return value is the number of nodes in the tree.
*/

#ifndef BINTREE_H
#define BINTREE_H

#include <cstdlib>  // Provides NULL and size_t

namespace main_savitch_10 {
template <class Item>
class BinaryTreeNode {
   public:
    // TYPEDEF
    typedef Item valueType;

    // CONSTRUCTOR
    BinaryTreeNode(
        const Item& initData = Item(),
        BinaryTreeNode* initLeft = NULL,
        BinaryTreeNode* initRight = NULL) {
        dataField = initData;
        leftField = initLeft;
        rightField = initRight;
    }

    // MODIFICATION MEMBER FUNCTIONS
    Item& data() { return dataField; }
    BinaryTreeNode*& left() { return leftField; }
    BinaryTreeNode*& right() { return rightField; }
    void setData(const Item& newData) { dataField = newData; }
    void setLeft(BinaryTreeNode* newLeft) { leftField = newLeft; }
    void setRight(BinaryTreeNode* newRight) { rightField = newRight; }

    // CONSTANT MEMBER FUNCTIONS
    const Item& data() const { return dataField; }
    const BinaryTreeNode* left() const { return leftField; }
    const BinaryTreeNode* right() const { return rightField; }
    bool isLeaf() const {
        return (leftField == NULL) && (rightField == NULL);
    }

   private:
    Item dataField;
    BinaryTreeNode* leftField;
    BinaryTreeNode* rightField;
};

// NOMMBER FUNCTIONS for the BinaryTreeNode<Item>:
template <class Process, class BTNode>
void inorder(Process f, BTNode* nodePtr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* nodePtr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* nodePtr);

template <class Item, class SizeType>
void print(const BinaryTreeNode<Item>* nodePtr, SizeType depth);

template <class Item>
void treeClear(BinaryTreeNode<Item>*& rootPtr);

template <class Item>
BinaryTreeNode<Item>* treeCopy(const BinaryTreeNode<Item>* rootPtr);

template <class Item>
std::size_t treeSize(const BinaryTreeNode<Item>* nodePtr);
}  // namespace main_savitch_10

#include "bintree.template"  // Include the implementation.
#endif
