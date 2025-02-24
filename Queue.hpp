#include <array>

#pragma once

const size_t MAX_QUEUE_SIZE = 10;

template <class T> class Queue {
private:
  std::array<T *, MAX_QUEUE_SIZE> data;
  size_t size;
  size_t front;
  size_t back;

public:
  Queue(size_t size) : size(size) {}
  auto enqueue(T *to_add) -> void;
  auto dequeue() -> T *;
  auto peek() -> T *;
  auto length() -> size_t;
  auto empty() -> void;
  auto isempty() -> bool;
  auto isfull() -> bool;
};
