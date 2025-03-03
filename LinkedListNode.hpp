template <class T> class DoubleLinkedNode {
private:
  T value;
  DoubleLinkedNode *next;
  DoubleLinkedNode *prev;

public:
  DoubleLinkedNode(T init_value) : value(init_value) {}

  auto get_value() -> DoubleLinkedNode * { return value; }
  auto get_next() -> DoubleLinkedNode * { return next; }
  auto get_prev() -> DoubleLinkedNode * { return prev; }

  auto add_item() -> void;
  auto get_item() -> void;

  auto is_in_list() -> void;
  auto is_empty() -> void;
  auto size() -> void;
};
