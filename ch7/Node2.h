#ifndef MAIN_SAVITCH_NODE2_H 
#define MAIN_SAVITCH_NODE2_H 

#include <cstdlib> // Provides size_t and NULL
#include <iterator> // Will be used for the node_iterator in Section 6.5 

namespace main_savitch_6B {
  template <class Item>
  class Node {
    public:
      //TYPEDEF
      typedef Item valueType;
      
      // CONSTRUCTOR
      Node(const Item& initData = Item(), Node* initLink = NULL) {
        dataField = initData; 
        linkField = initLink;
      }

      // MODIFICATION MEMBER FUNCTIONS
      Item& data() { return dataField; }
      Node* link() { return linkField; }
      void setData(const Item& newData) { dataField = newData; }
      void setLink(Node* newLink) { linkField = newLink; }

      // CONST MEMBER FUNCTIONS
      const Item& data() const { return dataField; }
      const Node* link() const { return linkField; }

    private:
      Item dataField;
      Node *linkField;
  };

  // FUNCTIONS to manipulate a linked-list 
  template <class Item>
  std::size_t listLength(const Node<Item>* headPtr);
  
  template <class Item>
  void listHeadInsert(Node<Item>*& headPtr, const Item& entry);

  template <class Item>
  void listInsert(Node<Item>* previousPtr, const Item& entry);

  template <class NodePtr, class Item>
  NodePtr listSearch(NodePtr headPtr, const Item& target);

  template <class NodePtr, class SizeType>
  NodePtr listLocate(NodePtr headPtr, SizeType position);
  
  template <class Item>
  void listHeadRemove(Node<Item>*& headPtr);

  template <class Item>
  void listRemove(Node<Item>* previousPtr);

  template <class Item>
  void listClear(Node<Item>*& headPtr);

  template <class Item>
  void listCopy(const Node<Item>* sourcePtr, Node<Item>*& headPtr, Node<Item>*& tailPtr);
}

#include "Node2.template"

#endif
