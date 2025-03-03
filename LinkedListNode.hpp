template <class T> class LinkedListNode {
private:
  T *value;
  LinkedListNode *next;
  LinkedListNode *prev;

public:
  LinkedListNode(T *init_value) : value(init_value) {}

  auto get_value() -> LinkedListNode * { return value; }
  auto get_next() -> LinkedListNode * { return next; }
  auto get_prev() -> LinkedListNode * { return prev; }
};
