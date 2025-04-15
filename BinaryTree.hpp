#include "GetAllStruct.hpp"
#include "Node.cpp"

#pragma once

template <typename T> class Tree {
private:
  Node<T> *root;
  int size;

public:
  Tree() : root(nullptr), size(0) {}
  Tree(T inVal) { root = new Node<T>(inVal); }

  // Getters.
  auto get_root() -> Node<T> * { return root; };

  // Usual operations.
  auto Insert(Node<T> *node, T inVal) -> Node<T> *;
  auto Find(T target) -> Node<T> *;
  auto FindSub(T target, Node<T> *node) -> Node<T> *;
  auto Remove(T inVal) -> Node<T> *;
  auto RemoveSub(T Inval, Node<T> *node) -> Node<T> *;
  void EmptyTree(Node<T> *node);

  // Other operations.
  void PrintSub(Node<T> *place);
  void Print();
  void PrintS(Node<T> *place);
  auto LeftLargest(Node<T> *parent) -> Node<T> *;
  auto GetAll(Node<T> *parent) -> std::vector<Node<T> *>;
  auto GetAllAscending() -> std::vector<GetAllStruct<T> *>;
  auto GetAllDescending() -> std::vector<GetAllStruct<T> *>;

  // Balancing.
  void RotateLeft(Node<T> *parent, Node<T> *child);
  void RotateRight(Node<T> *parent, Node<T> *child);
  void RotateRL(Node<T> *parent, Node<T> *child);
  void RotateLR(Node<T> *parent, Node<T> *child);

  auto Levels(Node<T> *parent, Node<T> *child) -> int;
};
