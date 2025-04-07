#include "Node.cpp"

#pragma once

template <typename T> class Tree {
private:
  T *root;

public:
  Tree() : root(nullptr) {}
  Tree(char inVal) { root = new Node<T>(inVal); }

  // Usual operations.
  void Insert(char inVal);
  auto Find(char target) -> char;
  auto Remove(char Inval) -> char;

  // Other operations.
  void PrintSub(Node<T> *place);
  void Print();
  void PrintS(Node<T> *place);
  auto LeftLargest(Node<T> *parent) -> char;
  auto GetAllAscending(Node<T> *parent) -> std::vector<Node<T> *>;
  auto GetAllDescending(Node<T> *parent) -> std::vector<Node<T> *>;

  // Balancing.
  void RotateLeft(Node<T> *parent, Node<T> *child);
  void RotateRight(Node<T> *parent, Node<T> *child);
  void RotateRL(Node<T> *parent, Node<T> *child);
  void RotateLR(Node<T> *parent, Node<T> *child);

  auto Levels(Node<T> *parent, Node<T> *child) -> int;
};
