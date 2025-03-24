#include <cassert>
#include <iostream>

#include "Errors.hpp"
#include "LinkedList.hpp"
#include "Part.hpp"

template <class T> auto DoublyLinkedList<T>::add_item(T value_to_add) -> void {
  auto *node_to_add = new LinkedListNode(value_to_add);

  if (node_cursor == head and head->get_value() == Part{}) {
    head = node_to_add;
    node_cursor = head;
    return;
  }

  LinkedListNode<T> *node_before_insertion = head;
  while (node_before_insertion != nullptr &&
         node_before_insertion->get_next() != nullptr &&
         node_before_insertion->get_next()->get_value() < value_to_add) {
    node_before_insertion = node_before_insertion->get_next();
  }
  if (node_before_insertion == nullptr) {
    head = node_to_add;
  } else {
    // Set node.
    node_to_add->set_next(node_before_insertion->get_next());
    node_to_add->set_prev(node_before_insertion);
    // Set node before.
    node_before_insertion->set_next(node_to_add);
    // Set node after.
    if (node_to_add->get_next() != nullptr)
      node_to_add->get_next()->set_prev(node_to_add);
  };

  ++size;

  // Add reference to `node_cursor` if the list is empty and the first item has
  // been added.
  // if (size == 1)
  //   this->reset();
}

template <class T>
auto DoublyLinkedList<T>::get_item(T value_to_find) -> LinkedListNode<T> * {
  // TODO(Ansh): Refactor later. Shares most lines with
  // `DoublyLinkedList::is_in_list()`.
  LinkedListNode<T> *curr_node = head;
  while (curr_node->get_next() != nullptr &&
         !(curr_node->get_value() == value_to_find)) {
    curr_node = curr_node->get_next();
  }
  if (curr_node->get_value() == value_to_find) {
    // Join the two nodes on either side.
    if (curr_node->get_prev() != nullptr)
      curr_node->get_prev()->set_next(curr_node->get_next());
    if (curr_node->get_next() != nullptr)
      curr_node->get_next()->set_prev(curr_node->get_prev());
    --size;
    return curr_node;
  } else {
    throw ItemNotFound();
  }
}

template <class T>
auto DoublyLinkedList<T>::is_in_list(T value_to_find) -> bool {
  if (size == 0)
    return false;

  LinkedListNode<T> *curr_node = head;
  while (curr_node->get_next() != nullptr &&
         !(curr_node->get_value() == value_to_find)) {
    curr_node = curr_node->get_next();
  }
  if (curr_node->get_value() == value_to_find) {
    return true;
  }
  return false;
}

template <class T> auto DoublyLinkedList<T>::is_empty() -> bool {
  return size == 0;
}

template <class T> auto DoublyLinkedList<T>::display() -> void {
  LinkedListNode<T> *curr_node = head;
  if (size == 0) {
    std::cout << "**************************************" << std::endl;
    std::cout << "*           List is empty.           *" << std::endl;
    std::cout << "**************************************" << std::endl;
    return;
  }

  while (curr_node != nullptr) {
    curr_node->get_value().Display();
    if (curr_node->get_next() != nullptr) {
      std::cout << "\t\t  |" << std::endl;
      std::cout << "\t\t  |" << std::endl;
    }

    curr_node = curr_node->get_next();
  }
}

template <class T> auto DoublyLinkedList<T>::see_next() -> LinkedListNode<T> * {
  if (size == 0) {
    throw SeeEmptyListError{};
  }
  if (node_cursor->get_next() == nullptr)
    throw OutOfBoundsError{};

  auto after_cursor = node_cursor->get_next();
  node_cursor = node_cursor->get_next();
  return after_cursor;
}

template <class T> auto DoublyLinkedList<T>::see_prev() -> LinkedListNode<T> * {
  if (size == 0) {
    throw SeeEmptyListError{};
  }
  if (node_cursor->get_prev() == nullptr)
    throw OutOfBoundsError{};

  auto before_cursor = node_cursor->get_prev();
  if (before_cursor->get_value() == Part{})
    throw OutOfBoundsError{};
  node_cursor = node_cursor->get_prev();
  return before_cursor;
}

template <class T>
auto DoublyLinkedList<T>::see_at(size_t index) -> LinkedListNode<T> * {
  if (size - 1 < index || size < 0) {
    throw OutOfBoundsError();
  }

  LinkedListNode<T> *curr_node = head;
  for (size_t i = 0; i < index; i++) {
    if (curr_node != nullptr && curr_node->get_next() != nullptr)
      curr_node = curr_node->get_next();
  }

  return curr_node;
}

template <class T> auto DoublyLinkedList<T>::reset() -> void {
  if (head->get_prev() != nullptr)
    node_cursor = head->get_prev();
  node_cursor = new LinkedListNode<T>();
  node_cursor->set_next(head);
  head->set_prev(node_cursor);
}

template <class T>
auto DoublyLinkedList<T>::operator<(DoublyLinkedList<T> other) -> bool {
  assert(node_cursor != nullptr);
  assert(other.node_cursor != nullptr);
  return node_cursor->get_value() < other.node_cursor->get_value();
}

template <class T>
auto DoublyLinkedList<T>::operator>(DoublyLinkedList<T> other) -> bool {
  assert(node_cursor != nullptr);
  assert(other.node_cursor != nullptr);
  return node_cursor->get_value() > other.node_cursor->get_value();
}

template <class T>
auto DoublyLinkedList<T>::operator==(DoublyLinkedList<T> other) -> bool {
  if (node_cursor == nullptr || other.node_cursor == nullptr)
    return node_cursor == other.node_cursor;
  return node_cursor->get_value() == other.node_cursor->get_value();
}

template class DoublyLinkedList<Part>;
