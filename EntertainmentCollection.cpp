#include <string>

#include "EntertainmentCollection.hpp"

template <class T> void EntertainmentCollection<T>::add(T *to_add) {
  if (count == MAX_COLLECTION_SIZE) {
    throw std::string("FullCollectionError");
  }
  collection[count++] = to_add;
}

template <class T> T *EntertainmentCollection<T>::remove() {
  if (count == 0) {
    throw std::string("EmptyCollectionError");
  }
  T *copy = collection[count - 1];
  collection[--count] = nullptr;
  return copy;
}
