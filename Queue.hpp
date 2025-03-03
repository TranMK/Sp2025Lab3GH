#include <array>
#include <cstddef>
#include <memory>

#pragma once

const size_t MAX_QUEUE_SIZE = 10;

template <class T> class Queue {
private:
  std::array<std::unique_ptr<T>, MAX_QUEUE_SIZE> data;
  size_t size;
  size_t front;
  size_t back;

public:
  Queue(size_t size) : size(size) {}

  auto enqueue(std::unique_ptr<T> to_add) -> void;
  auto dequeue() -> std::unique_ptr<T>;
  auto peek() -> std::unique_ptr<T>;
  auto length() -> size_t { return size; }
  auto is_full() -> bool { return size == MAX_QUEUE_SIZE; }
  auto is_empty() -> bool { return size == 0; }
  auto empty() -> void;
};
