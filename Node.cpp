#include <utility>

template <typename T> class Node {
public:
  T data;
  Node *left, *right;

  Node() : data(nullptr), left(nullptr), right(nullptr) {}
  Node(T data) : data(std::move(data)), left(nullptr), right(nullptr) {}
};
