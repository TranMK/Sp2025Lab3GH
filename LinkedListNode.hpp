#pragma once

template <class T> class LinkedListNode {
private:
  T *value;
  LinkedListNode *next;
  LinkedListNode *prev;

public:
  LinkedListNode(T *init_value) : value(init_value) {}

  auto get_value() -> T * { return value; }
  auto get_next() -> LinkedListNode * { return next; }
  auto get_prev() -> LinkedListNode * { return prev; }

  auto set_value(T *set_value) -> void { value = set_value; }
  auto set_next(LinkedListNode *next_node) -> void { next = next_node; }
  auto set_prev(LinkedListNode *prev_node) -> void { prev = prev_node; }
};
