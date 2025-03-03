#include "Queue.hpp"
#include "Errors.hpp"

template <class T> auto Queue<T>::enqueue(std::unique_ptr<T> to_add) -> void {
  if (is_full()) {
    throw QueueOverflowError{};
  }
  data[front] = std::move(to_add);
  front = (front + 1) % MAX_QUEUE_SIZE;
  size++;
}

template <class T> auto Queue<T>::dequeue() -> std::unique_ptr<T> {
  if (is_empty()) {
    throw QueueUnderflowError{};
  }
  size--;
  auto retval = std::move(data[back]);
  back = (back + 1) % MAX_QUEUE_SIZE;
  return retval;
}

template <class T> auto Queue<T>::peek() -> std::unique_ptr<T> {
  return std::move(data[front]);
}

template <class T> auto Queue<T>::empty() -> void { size = 0; }

template class Queue<std::string>;
