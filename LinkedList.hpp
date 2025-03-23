#include <cstddef>

#include "LinkedListNode.hpp"

#pragma once

template <class T> class DoublyLinkedList {
private:
  LinkedListNode<T> *head;
  LinkedListNode<T> *node_cursor;
  size_t size = 0;

public:
  DoublyLinkedList(T *init_value)
      : head(new LinkedListNode(init_value)), node_cursor(head), size(1) {}
  ~DoublyLinkedList() {
    size = 0;
    LinkedListNode<T> *curr_node = head;
    while (curr_node != nullptr) {
      LinkedListNode<T> *curr_ref = curr_node;
      curr_node = curr_node->get_next();
      delete (curr_ref);
    }
  }

  auto add_item(T *value_to_add) -> void;
  auto get_item(T *value_to_find) -> LinkedListNode<T> *;

  auto is_in_list(T *value_to_find) -> bool;
  auto is_empty() -> bool;
  auto get_size() -> size_t { return size; };
  auto display() -> void;

  auto see_next() -> LinkedListNode<T> *;
  auto see_prev() -> LinkedListNode<T> *;
  auto see_at(size_t index) -> LinkedListNode<T> *;
  auto reset() -> void;

  // Operator overloads.
  auto operator<(DoublyLinkedList other) -> bool;
  auto operator>(DoublyLinkedList other) -> bool;
  auto operator==(DoublyLinkedList other) -> bool;
};
