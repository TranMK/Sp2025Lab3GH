#include "EnterCollect.hpp"
template<class T>
T *EnterCollect<T>::remove_T() {
    T *copy = collection[T_count - 1];
    collection[--T_count] = nullptr;
    return copy;
  }
