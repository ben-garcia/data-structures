#ifndef H_Node1_H
#define H_Node1_H

#include <cstdlib> // Provides size_t and NULL

namespace main_savitch_5 {
  class Node {
    public:
      //TYPEDEF
      typedef double valueType;
      
      // CONSTRUCTOR
      Node(const valueType& initData = valueType(), Node* initLink = NULL) {
        dataField = initData; 
        linkField = initLink;
      }

      // MODIFICATION MEMBER FUNCTIONS
      Node* link() { return linkField; }
      void setData(const valueType& newData) { dataField = newData; }
      void setLink(Node* newLink) { linkField = newLink; }

      // CONST MEMBER FUNCTIONS
      valueType data() const { return dataField; }
      const Node* link() const { return linkField; }

    private:
      valueType dataField;
      Node *linkField;
  };

  // FUNCTIONS for theh linked-list toolkit
  std::size_t listLength(const Node* headPtr);
  void listHeadInsert(Node*& headPtr, const Node::valueType& entry);
  void listInsert(Node* previousPtr, const Node::valueType& entry);
  Node* listSearch(Node* headPtr, const Node::valueType& target);
  const Node* listSearch(const Node* headPtr, const Node::valueType& target);
  Node* listLocate(Node* headPtr, std::size_t position);
  const Node* listLocate(const Node* headPtr, std::size_t position);
  void listHeadRemove(Node*& headPtr);
  void listRemove(Node* previousPtr);
  void listClear(Node*& headPtr);
  void listCopy(const Node* sourcePtr, Node*& headPtr, Node*& tailPtr);
}

#endif
