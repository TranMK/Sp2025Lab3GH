#include <Queue.hpp>
#include <Errors.hpp>
template <class T> auto Queue<T>::length()->size_t {return length;}
template <class T> auto Queue<T>::isfull()->bool {
    return length == MAX_QUEUE_SIZE;
}
template <class T> auto Queue<T>::isempty() -> bool {
    return length == 0;
}
template <class T> auto Queue<T>::enqueue(T *to_add) -> void {
    if (isfull()) {
      throw StackOverflowError{};
    }
    data[front] = to_add;
    front = (front + 1) % MAX_QUEUE_SIZE;
    length++;
}
template <class T> auto Queue<T>::dequeue() -> T * {
    // Should do `data.empty()` instead we're using `std::array`.
    if (isempty()) {
      throw StackUnderflowError{};
    }
    length--;
    size_t retval = data[back];
    back = (back + 1) % MAX_QUEUE_SIZE;
    return retval;
}
template <class T> auto Queue<T>::peek() -> T * {
    return data[back]
}
template <class T> auto Queue<T>::empty() -> void {
    for (auto &index : data){
        index = nullptr;
    }
    length=0;
}
template <> class Queue<std::string> {};