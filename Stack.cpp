#include "Stack.hpp"
#include "Errors.hpp"

template <class T> auto Stack<T>::push(std::unique_ptr<T> to_add) -> void {
  if (size == MAX_STACK_SIZE) {
    throw StackOverflowError{};
  }
  data[++size] = std::move(to_add);
}

template <class T> auto Stack<T>::pop() -> std::unique_ptr<T> * {
  // Should do `data.empty()` when using using `std::array`.
  if (size == 0) {
    throw StackUnderflowError{};
  }
  return &data[size--];
}

template <class T> auto Stack<T>::top() -> std::unique_ptr<T> * {
  if (size == 0) {
    throw StackUnderflowError{};
  }
  return &data[size - 1];
}

template <class T> auto Stack<T>::length() -> size_t { return size; }

template <class T> auto Stack<T>::empty() -> void { size = 0; }

template class Stack<char>;
