#include "Node.cpp"

#pragma once

template <typename T> class Tree {
private:
  Node<T> *root;

public:
  Tree() : root(nullptr) {}
  Tree(char inVal) { root = new Node<T>(inVal); }

  // Getters.
  auto get_root() -> Node<T> * { return root; };

  // Usual operations.
  void Insert(T inVal);
  auto Find(T target) -> T;
  auto Remove(T Inval) -> T;

  // Other operations.
  void PrintSub(Node<T> *place);
  void Print();
  void PrintS(Node<T> *place);
  auto LeftLargest(Node<T> *parent) -> T;
  auto GetAllAscending(Node<T> *parent) -> std::vector<Node<T> *>;
  auto GetAllDescending(Node<T> *parent) -> std::vector<Node<T> *>;

  // Balancing.
  void RotateLeft(Node<T> *parent, Node<T> *child);
  void RotateRight(Node<T> *parent, Node<T> *child);
  void RotateRL(Node<T> *parent, Node<T> *child);
  void RotateLR(Node<T> *parent, Node<T> *child);

  auto Levels(Node<T> *parent, Node<T> *child) -> int;
};
