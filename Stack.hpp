#include <array>
#include <cstddef>

#pragma once

const size_t MAX_STACK_SIZE = 10;

template <class T> class Stack {
private:
  size_t size;

public:
  std::array<T*, MAX_STACK_SIZE> data;

  Stack(size_t size) : size(std::move(size)) {}

  auto push(T *to_add) -> void;
  auto pop() -> T *;
  auto top() -> T *;
  auto length() -> size_t;
  auto empty() -> void;
};
