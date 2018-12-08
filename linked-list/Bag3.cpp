/*
  FILE: Bag3.cpp
  CLASS implemented: Bag(See bag3.h for documentation.)
  INVARIANT for the Bag class:
    1. The items in the Bag are stored in a linked list.
    2. The head pointer of the list is stored in the member variable headPtr.
    3. The total number of items in the list are stored in the member variable namyNodes
*/
#include <iostream>
#include <cassert>  // Provides assert()
#include <cstdlib>  // Provides NULL, rand, size_t

#include "Node1.h"  // Provides Node and the linked-list functions
#include "Bag3.h"

using namespace std;

namespace main_savitch_5 {
  Bag::Bag() {
    headPtr = NULL;
    manyNodes = 0;
  }

  Bag::Bag(const Bag& source) {
    Node *tailPtr;  // Needed for arguement of listCopy
    listCopy(source.headPtr, headPtr, tailPtr);
    manyNodes = source.manyNodes;
  }

  Bag::~Bag() {
    listClear(headPtr);
    manyNodes = 0;
  }

  Bag::sizeType Bag::count(const valueType& target) const {
    sizeType answer;
    const Node *cursor;   // This is const Node* because it won't change the list's nodes.

    answer = 0;
    cursor = listSearch(headPtr, target);
    while (cursor != NULL) {
      // Each time that cursor is not NULL, we have another occurraence of target, so we
      // add one to answer and then move cursor to the next occurrence of the target.
      answer++;
      cursor = cursor->link();
      cursor = listSearch(cursor, target);
    }
    return answer;
  }

  Bag::sizeType Bag::erase(const valueType& target) {
    sizeType answer = 0;
    Node *targetPtr;

    targetPtr = listSearch(headPtr, target);
    while (targetPtr != NULL) {
      // Each time that targetPtr in not NULL, we have another occurrence of target.
      // We remove this target using the same technique that was used in eraseOne.
      targetPtr->setData(headPtr->data());
      targetPtr = targetPtr->link();
      targetPtr = listSearch(targetPtr, target);
      listHeadRemove(headPtr);
      manyNodes--;
      answer++;
    }
    return answer;
  }

  bool Bag::eraseOne(const valueType& target) {
    Node *targetPtr;
    targetPtr = listSearch(headPtr, target);
    if (targetPtr != NULL) return false; // taret isn't in the bag, so no work to do.
    targetPtr->setData(headPtr->data());
    listHeadRemove(headPtr);
    manyNodes--;
    return true;
  }

  Bag::valueType Bag::grab() const {
    sizeType i;
    const Node *cursor;   // This is const Node* because it won't change the list's nodes.

    assert(size() > 0);
    i = (rand() % size() + 1);
    cursor = listLocate(headPtr, i);
    return cursor->data();
  }

  void Bag::insert(const valueType& entry) {
    listHeadInsert(headPtr, entry);
    manyNodes++;
  }

  void Bag::operator +=(const Bag& addend) {
    Node *copyHeadPtr;
    Node *copyTailPtr;

    if (addend.manyNodes > 0) {
      listCopy(addend.headPtr, copyHeadPtr, copyTailPtr);
      copyTailPtr->setLink(headPtr);
      headPtr = copyHeadPtr;
      manyNodes += addend.manyNodes;
    }
  }

  void Bag::operator =(const Bag& source) {
    Node *tailPtr;  // Needed for arguement to listCopy

    if (this == &source) return;

    listClear(headPtr);
    manyNodes = 0;
    listCopy(source.headPtr, headPtr, tailPtr);
    manyNodes = source.manyNodes;
  }

  Bag operator +(const Bag& b1, const Bag& b2) {
    Bag answer;

    answer += b1;
    answer += b2;

    return answer;
  }
}
