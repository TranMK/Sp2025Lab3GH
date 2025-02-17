#include <cstddef>

#pragma once

const size_t MAX_COLLECTION_SIZE = 10;

template <class T> class EnterCollect {
  T *collection[MAX_COLLECTION_SIZE] = {};
  size_t T_count = 0;

public:
  EnterCollect() = default;
  void add_T(T *T_to_add) { collection[T_count++] = T_to_add; };
  T *remove_T();
  size_t get_T_count() { return T_count; }
};
