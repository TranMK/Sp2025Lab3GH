#include <cstddef>

#include "linked_list_node.hpp"

#pragma once

template <class T> class DoublyLinkedList {
private:
  LinkedListNode<T> *head = nullptr;
  LinkedListNode<T> *node_cursor = nullptr;
  size_t size = 0;

public:
  DoublyLinkedList() = default;
  DoublyLinkedList(T init_value)
      : head(new LinkedListNode(new T(init_value))), size(1) {
    node_cursor = head;
  }
  ~DoublyLinkedList() {
    size = 0;
    while (head != nullptr) {
      LinkedListNode<T> *temp = head;
      head = head->get_next();
      delete temp->get_value();
      delete temp;
    }
  }

  auto add_item(T value_to_add) -> void;
  auto get_item(T value_to_find) -> LinkedListNode<T> *;
  auto get_item2(T value_to_find) -> size_t;
  auto find(T value_to_find) -> LinkedListNode<T> *;
  auto is_in_list(T value_to_find) -> bool;
  auto is_in_list2(T value_to_find) -> size_t;
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
