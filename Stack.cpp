#include "Stack.hpp"
#include "Errors.hpp"

template <class T> auto Stack<T>::push(T *to_add) -> void {
  if (size == MAX_STACK_SIZE) {
    throw StackOverflowError{};
  }
  data[++size] = to_add;
}

template <class T> auto Stack<T>::pop() -> T * {
  // Should do `data.empty()` when using using `std::array`.
  if (size == 0) {
    throw StackUnderflowError{};
  }
  return data[size--];
}

template <class T> auto Stack<T>::top() -> T * {
  if (size == 0) {
    throw StackUnderflowError{};
  }
  return data[size - 1];
}

template <class T> auto Stack<T>::length() -> size_t { return size; }

template <class T> auto Stack<T>::empty() -> void {
  for (auto *datum : data) {
    delete (datum);
    // datum = nullptr;
  }
  size = 0;
}

template class Stack<char>;
