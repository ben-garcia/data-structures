#ifndef MAIN_SAVITCH_CONSTNODEITERATOR_H 
#define MAIN_SAVITCH_CONSTNODEITERATOR_H 

namespace main_savitch_6B {
  template <class Item>
  class ConstNodeIterator : public std::iterator<std::forward_iterator_tag, Item> {
    public:
      ConstNodeIterator(const Node<Item>* initial = NULL) {
        current = initial;
      }

      const Item& operator *() const {
        return current->data();
      }

      ConstNodeIterator& operator ++() { // Prefix ++
        current = current->link();
        return *this;
      }

      ConstNodeIterator operator ++(int) { // Postfix ++
        ConstNodeIterator original(current);
        current = current->link();
        return original;
      } 

      bool operator ==(const ConstNodeIterator other) const {
        return current == other.current;
      }

      bool operator !=(const ConstNodeIterator other) const {
        return current != other.current;
      }

    private:
      const Node<Item>* current;
  };
}

#endif