template <class T> class LinkedListNode {
private:
  T value;
  LinkedListNode *next;
  LinkedListNode *prev;

public:
  LinkedListNode(T init_value) : value(init_value) {}

  auto get_value() -> LinkedListNode * { return value; }
  auto get_next() -> LinkedListNode * { return next; }
  auto get_prev() -> LinkedListNode * { return prev; }

  auto add_item() -> void;
  auto get_item() -> void;

  auto is_in_list() -> void;
  auto is_empty() -> void;
  auto size() -> void;
};
