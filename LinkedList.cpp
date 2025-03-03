#include "LinkedList.hpp"

template <class T> auto DoublyLinkedList<T>::add_item(T *value_to_add) -> void {
  LinkedListNode<T> *node_before_insertion = head;
  while (node_before_insertion->next->get_value() < value_to_add) {
    node_before_insertion = node_before_insertion->get_next();
  }

  LinkedListNode<T> *node_to_add = new LinkedListNode(value_to_add);
  // Set node.
  node_to_add->set_next(node_before_insertion->get_next());
  node_to_add->set_prev(node_before_insertion);
  // Set node before.
  node_before_insertion->set_next(node_to_add);
  // Set node after.
  node_to_add->get_next()->set_prev(node_to_add);
}
template <class T>
auto DoublyLinkedList<T>::get_item() -> LinkedListNode<T> * {}

template <class T> auto DoublyLinkedList<T>::is_in_list(T *find_val) -> bool {}
template <class T> auto DoublyLinkedList<T>::is_empty() -> bool {
  return size == 0;
}

template <class T> auto DoublyLinkedList<T>::see_next() -> LinkedListNode<T> {}
template <class T> auto DoublyLinkedList<T>::see_prev() -> LinkedListNode<T> {}
template <class T> auto DoublyLinkedList<T>::see_at() -> LinkedListNode<T> {}
template <class T> auto DoublyLinkedList<T>::reset() -> void {}
