/******************************************************************************/

#include "Node1.h"

namespace main_savitch_5 {
  size_t listLength(const Node* headPtr) {
    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: The value returned is the number of nodes in the
    // linked list.
    const Node *cursor;
    size_t answer;

    answer = 0;
    for (cursor = headPtr; cursor != NULL; cursor = cursor->link())
      answer++;

    return answer;
  }

  void listHeadInsert(Node*& headPtr, const Node::valueType& entry) {
    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: A new node containing the given entry has been added
    // at the ehad of the linked list; headPtr now points to the head of the
    // new, longer linked list. NOTE: if there is insufficient dynamic memory
    // for a new node, then bad_alloc is thrown before changing the list.
    headPtr = new Node(entry, headPtr);
  }

  void listInsert(Node* previousPtr, const Node::valueType& entry) {
    // Precondition: previousPtr points to a node in a linked list.
    // Postcondition: A new node containing the given entry has been aded after
    // the node that previousPtr points to. NOTE: if there is insufficient
    // dynamic memory for a new node, then bad_alloc is thrown before changing
    // the list.
    Node *insertPtr;

    insertPtr = new Node;
    insertPtr->setData(entry);
    insertPtr->setLink(previousPtr->link());
    previousPtr->setLink(insertPtr);
  }

  Node* listSearch(Node* headPtr, const Node::valueType& target) {
    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: The return value is apointer to the first node
    // containing the specified target in its data field. If there is no such
    // node, the null pointer is returned.
    Node *cursor;

    for (cursor = headPtr; cursor != NULL; cursor = cursor->link())
      if (target == cursor->data())
        return cursor;
    return NULL;
  }
  const Node* listSearch(const Node* headPtr, const Node::valueType& target) {
    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: The return value is a pointer to the first node containing
    // the specified target in its data field. If there is no such node, the null
    // pointer is returned.
    const Node *cursor;

    for (cursor = headPtr; cursor != NULL; cursor = cursor->link())
      if (target == cursor->data())
        return cursor;
    return NULL;
  }

  Node* listLocate(Node* headPtr, std::size_t position) {

  }

  const Node* listLocate(const Node* headPtr, std::size_t position) {

  }

  void listHeadRemove(Node*& headPtr) {
    // Precondition: headPtr is the head pointer of a linked list, with at least
    //               one node.
    // Postcondition: The head node has been removed and returned to the heap;
    // headPtr is now the head pointer of the new, shorter linked list.
    Node *removePtr;

    removePtr = headPtr;
    headPtr = headPtr->link();
    delete removePtr;
  }

  void listRemove(Node* previousPtr) {
    // Precondition: previousPtr points to a node in a linked list, and this is not
    //               the tail node of the list.
    // Postcondition: The node atter previousPtr has been removed from the linked list.
    Node *removePtr;

    removePtr = previousPtr->link();
    previousPtr->setLink(removePtr->link());
    delete removePtr;
  }

  void listClear(Node*& headPtr) {
    // Precondition: headPtr is thehead pointer of a linked list.
    // Postcondition: All nodes of the list have been deleted, and headPtr is now NULL.
    while (headPtr != NULL)
      listHeadRemove(headPtr);
  }

  void listCopy(const Node* sourcePtr, Node*& headPtr, Node*& tailPtr) {
    // Precondition: sourcePtr is the head pointer of a linked list.
    // Postcondition: headPtr and tailPtr are the head and tail pointers
    //                for a new list that contains the same items as the list
    //                pointed to by sourcePtr. NOTE: If there is insufficient
    //                dynamic memory to create the new list, then bad_alloc 
    //                is thrown.
    headPtr = NULL;
    tailPtr = NULL;

    // Handle the case of the empty list.
    if (sourcePtr == NULL) return;

    // Make the head node for the newly created list and put data in it.
    listHeadInsert(headPtr, sourcePtr->data());
    tailPtr = headPtr;

    // Copy the rest of the nodes one at a time, adding at the tail of new list.
    sourcePtr = sourcePtr->link();
    while (sourcePtr != NULL) {
      listInsert(tailPtr, sourcePtr->data());
      tailPtr = tailPtr->link();
      sourcePtr = sourcePtr->link();
    }
  }
}
