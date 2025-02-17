#include <cstddef>

#pragma once

const size_t MAX_COLLECTION_SIZE = 10;

template <class T> class EntertainmentCollection {
  T *collection[MAX_COLLECTION_SIZE] = {};
  size_t count = 0;

public:
  EntertainmentCollection() = default;
  void add(T *to_add);
  T *remove();
  size_t get_count() { return count; }
};
