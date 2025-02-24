#include <array>

#pragma once

const size_t MAX_STACK_SIZE = 5;

template <class T> class Stack {
  std::array<T *, MAX_STACK_SIZE> data;
  size_t size;

public:
  Stack(size_t size) : size(size) {}

  auto push(T *to_add) -> void;
  auto pop() -> T *;
  auto top() -> T *;
  auto length() -> size_t;
  auto empty() -> void;
};
