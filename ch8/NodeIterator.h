#ifndef MAIN_SAVITCH_NODEITERATOR_H 
#define MAIN_SAVITCH_NODEITERATOR_H 

namespace main_savitch_6B {
  template <class Item>
  class NodeIterator : public std::iterator<std::forward_iterator_tag, Item> {
    public:
      NodeIterator(Node<Item>* initial = NULL) {
        current = initial;
      }

      Item& operator *() const {
        return current->data();
      }

      NodeIterator& operator ++() { // Prefix ++
        current = current->link();
        return *this;
      }

      NodeIterator operator ++(int) { // Postfix ++
        NodeIterator original(current);
        current = current->link();
        return original;
      } 

      bool operator ==(const NodeIterator other) const {
        return current == other.current;
      }

      bool operator !=(const NodeIterator other) const {
        return current != other.current;
      }

    private:
      Node<Item>* current;
  };
}

#endif
