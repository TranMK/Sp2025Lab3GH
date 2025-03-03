#include <array>
#include <cstddef>
#include <memory>

#pragma once

const size_t MAX_STACK_SIZE = 10;

template <class T> class Stack {
private:
  size_t size;
  std::array<std::unique_ptr<T>, MAX_STACK_SIZE> data;

public:
  Stack(size_t size) : size(std::move(size)) {}

  auto push(std::unique_ptr<T> to_add) -> void;
  auto pop() -> std::unique_ptr<T> *;
  auto top() -> std::unique_ptr<T> *;
  auto length() -> size_t;
  auto empty() -> void;
};
