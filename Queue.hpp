#include <array>
#include <cstddef>

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
  auto length() -> size_t { return size; }
  auto is_full() -> bool { return size == MAX_QUEUE_SIZE; }
  auto is_empty() -> bool { return size == 0; }
  auto empty() -> void;
};
