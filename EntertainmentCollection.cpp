#include <string>

#include "EntertainmentCollection.hpp"
#include "Game.hpp"

template <class T> void EntertainmentCollection<T>::add_item(T *to_add) {
  if (item_count == MAX_COLLECTION_SIZE) {
    throw std::string("FullCollectionError");
  }
  collection[item_count++] = to_add;
}

template <class T> T *EntertainmentCollection<T>::remove_item() {
  if (item_count == 0) {
    throw std::string("EmptyCollectionError");
  }
  T *copy = collection[item_count - 1];
  collection[--item_count] = nullptr;
  return copy;
}

template class EntertainmentCollection<Game>;
