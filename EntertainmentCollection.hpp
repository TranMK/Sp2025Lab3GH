#include <cstddef>

#pragma once

const size_t MAX_COLLECTION_SIZE = 10;

template <class T> class EntertainmentCollection {
  T *collection[MAX_COLLECTION_SIZE] = {};
  size_t item_count = 0;

public:
  EntertainmentCollection() = default;
  void add_item(T *item_to_add);
  T *remove_item();
  size_t get_item_count() { return item_count; }
};
