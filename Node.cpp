#include <cstddef>

#include "Node.hpp"

template <typename T> auto Node<T>::operator<(Node<T> *other) -> bool {
  return data < other->data;
}

template <typename T> auto Node<T>::operator==(Node<T> *other) -> bool {
  return data == other->data;
}

template <typename T> auto Node<T>::operator>(Node<T> *other) -> bool {
  return data > other->data;
}
