#include <array>

#pragma once

const size_t MAX_QUEUE_SIZE = 10;

template <class T> class Queue {
private:
  std::array<T *, MAX_QUEUE_SIZE> data;
  size_t size;

public:
  Queue(size_t size) : size(size) {}

  auto Enqueue(T *to_add) -> void;
  auto Dequeue() -> T *;
  auto Peek() -> T *;
  auto length() -> size_t;
  auto empty() -> void;
};
