#include <cstddef>
#include <utility>

#pragma once

template <typename T> class Node {
public:
  T data;
  size_t count;
  Node<T> *left, *right;

  Node() : data(nullptr), left(nullptr), right(nullptr) {}
  Node(T data) : data(std::move(data)), left(nullptr), right(nullptr) {}

  auto operator<(Node<T> *other) -> bool;
  auto operator==(Node<T> *other) -> bool;
  auto operator>(Node<T> *other) -> bool;
};
