#include "Queue.hpp"
#include "Errors.hpp"

template <class T> auto Queue<T>::enqueue(T *to_add) -> void {
  if (is_full()) {
    throw QueueOverflowError{};
  }
  data[front] = to_add;
  front = (front + 1) % MAX_QUEUE_SIZE;
  size++;
}

template <class T> auto Queue<T>::dequeue() -> T * {
  if (is_empty()) {
    throw QueueUnderflowError{};
  }
  size--;
  T *retval = data[back];
  back = (back + 1) % MAX_QUEUE_SIZE;
  return retval;
}

template <class T> auto Queue<T>::peek() -> T * { return data[front]; }

template <class T> auto Queue<T>::empty() -> void {
  for (auto &index : data) {
    delete(index);
    index = nullptr;
  }
  size = 0;
}

template class Queue<std::string>;
