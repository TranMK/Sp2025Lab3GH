#include <cstddef>
#include <utility>

#pragma once

template <typename T> class Node {
public:
  T data;
  float count;
  Node<T> *left, *right;

  Node() : data(nullptr), left(nullptr), right(nullptr) {}
  Node(T data) : data(std::move(data)), left(nullptr), right(nullptr), count(1) {}
  Node(Node<T>* inNode) : data(inNode->data), left(inNode->left), right(inNode->right), count(inNode->count) {}

  auto operator<(Node<T> *other) -> bool;
  auto operator==(Node<T> *other) -> bool;
  auto operator>(Node<T> *other) -> bool;
};
