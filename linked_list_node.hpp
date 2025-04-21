
#pragma once
template <class T> class LinkedListNode {
protected:
  T* value = nullptr;
  LinkedListNode *next = nullptr;
  LinkedListNode *prev = nullptr;

public:
  explicit LinkedListNode(T *init_value = nullptr) : value(init_value) {}
  ~LinkedListNode() = default;

  auto get_value() -> T *{ return value; }
  auto get_next() -> LinkedListNode * { return next; }
  auto get_prev() -> LinkedListNode * { return prev; }

  auto set_next(LinkedListNode *next_node) -> void { next = next_node; }
  auto set_prev(LinkedListNode *prev_node) -> void { prev = prev_node; }
};
