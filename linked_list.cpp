#include <cassert>
#include <iostream>

#include "linked_list.hpp"
#include "errors.hpp"

template <class T> 
auto DoublyLinkedList<T>::add_item(T value_to_add) -> void {
    // Create new node with COPY of the value (not pointer to local)
    auto* node_to_add = new LinkedListNode<T>(new T(value_to_add));
    
    if (size == 0) {
        head = node_to_add;
        node_cursor = head;
    } else {
        // Add at head for O(1) insertion
        node_to_add->set_next(head);
        head->set_prev(node_to_add);
        head = node_to_add;
    }
    ++size;
}
template <class T>
auto DoublyLinkedList<T>::get_item(T value_to_find) -> LinkedListNode<T>* {
    LinkedListNode<T>* curr_node = head;
    // TODO(Ansh): Refactor later. Shares most lines with
    // `DoublyLinkedList::is_in_list()`.
    while (curr_node != nullptr) {
        if (curr_node->get_value() && *curr_node->get_value() == value_to_find) {
            // Update neighbors
            if (curr_node->get_prev()) {
                curr_node->get_prev()->set_next(curr_node->get_next());
            } else {
                head = curr_node->get_next();
            }

            if (curr_node->get_next()) {
                curr_node->get_next()->set_prev(curr_node->get_prev());
            }

            // Update cursor if needed
            if (node_cursor == curr_node) {
                node_cursor = curr_node->get_next() ? curr_node->get_next() 
                                                  : curr_node->get_prev();
            }

            --size;
            
            return curr_node;
        }
        curr_node = curr_node->get_next();
    }
    throw ItemNotFound();
}
template <class T> auto DoublyLinkedList<T>::get_item2(T value_to_find) -> size_t {
  LinkedListNode<T>* curr_node = head;
  size_t spots_checked = 0;
  // TODO(Ansh): Refactor later. Shares most lines with
  // `DoublyLinkedList::is_in_list()`.
  while (curr_node != nullptr) {
      spots_checked++;
      if (curr_node->get_value() && *curr_node->get_value() == value_to_find) {
          // Update neighbors
          if (curr_node->get_prev()) {
              curr_node->get_prev()->set_next(curr_node->get_next());
          } else {
              head = curr_node->get_next();
          }

          if (curr_node->get_next()) {
              curr_node->get_next()->set_prev(curr_node->get_prev());
          }

          // Update cursor if needed
          if (node_cursor == curr_node) {
              node_cursor = curr_node->get_next() ? curr_node->get_next() 
                                                : curr_node->get_prev();
          }

          --size;
          delete curr_node->get_value();
          delete curr_node;
          return spots_checked;
      }
      curr_node = curr_node->get_next();
  }
  throw ItemNotFound();
}
template <class T>
auto DoublyLinkedList<T>::find(T value_to_find) -> LinkedListNode<T>* {
  // TODO(Ansh): Refactor later. Shares most lines with
  // `DoublyLinkedList::is_in_list()`.
    LinkedListNode<T>* curr_node = head;
    while (curr_node != nullptr) {
        if (curr_node->get_value() && *curr_node->get_value() == value_to_find) {
            return curr_node;
        }
        curr_node = curr_node->get_next();
    }
    throw ItemNotFound();
}
template <class T>
auto DoublyLinkedList<T>::is_in_list(T value_to_find) -> bool {
  if (size == 0)
    return false;

  LinkedListNode<T> *curr_node = head;
  while (curr_node != nullptr && curr_node->get_next() != nullptr &&
         curr_node->get_value() != nullptr &&
         !(*curr_node->get_value() == value_to_find)) {
    curr_node = curr_node->get_next();
  }
  if (curr_node->get_value() != nullptr &&
      *curr_node->get_value() == value_to_find) {
    return true;
  }
  return false;
}
template <class T>
auto DoublyLinkedList<T>::is_in_list2(T value_to_find) -> size_t {
  //returns number of spots checked. If not found or empty, return 0.
  if (size == 0)
    return 0;

  LinkedListNode<T> *curr_node = head;
  size_t checked_spots = 0;
  while (curr_node != nullptr && curr_node->get_next() != nullptr &&
         curr_node->get_value() != nullptr &&
         !(*curr_node->get_value() == value_to_find)) {
    checked_spots++;
    curr_node = curr_node->get_next();
  }
  if (curr_node->get_value() != nullptr &&
      *curr_node->get_value() == value_to_find) {
        checked_spots++;
    return checked_spots;
  }
  return 0;
}

template <class T> auto DoublyLinkedList<T>::is_empty() -> bool {
  return size == 0;
}

template <class T> auto DoublyLinkedList<T>::display() -> void {
  LinkedListNode<T> *curr_node = head;
  if (size == 0) {
    std::cout << "**************************************" << std::endl;
    std::cout << "*           List is empty.           *" << std::endl;
    std::cout << "**************************************" << std::endl;
    return;
  }

  while (curr_node != nullptr) {
    if (curr_node->get_next() != nullptr) {
      std::cout << "\t\t  |" << std::endl;
      std::cout << "\t\t  |" << std::endl;
    }

    curr_node = curr_node->get_next();
  }
}

template <class T> auto DoublyLinkedList<T>::see_next() -> LinkedListNode<T> * {
  if (size == 0) {
    throw SeeEmptyListError{};
  }
  if (node_cursor->get_next() == nullptr)
    throw OutOfBoundsError{};

  auto after_cursor = node_cursor->get_next();
  node_cursor = node_cursor->get_next();
  return after_cursor;
}

template <class T> auto DoublyLinkedList<T>::see_prev() -> LinkedListNode<T> * {
  if (size == 0) {
    throw SeeEmptyListError{};
  }
  if (node_cursor->get_prev() == nullptr)
    throw OutOfBoundsError{};

  auto before_cursor = node_cursor->get_prev();
  node_cursor = node_cursor->get_prev();
  return before_cursor;
}

template <class T>
auto DoublyLinkedList<T>::see_at(size_t index) -> LinkedListNode<T> * {
  if (size - 1 < index || size < 0) {
    throw OutOfBoundsError();
  }

  LinkedListNode<T> *curr_node = head;
  for (size_t i = 0; i < index; i++) {
    if (curr_node != nullptr && curr_node->get_next() != nullptr)
      curr_node = curr_node->get_next();
  }

  return curr_node;
}

template <class T> auto DoublyLinkedList<T>::reset() -> void {
  if (head->get_prev() != nullptr) {
    node_cursor = head->get_prev();
    return;
  }
  node_cursor = new LinkedListNode<T>();
  node_cursor->set_next(head);
  head->set_prev(node_cursor);
}

template <class T>
auto DoublyLinkedList<T>::operator<(DoublyLinkedList<T> other) -> bool {
  assert(node_cursor != nullptr);
  assert(other.node_cursor != nullptr);
  return node_cursor->get_value() < other.node_cursor->get_value();
}

template <class T>
auto DoublyLinkedList<T>::operator>(DoublyLinkedList<T> other) -> bool {
  assert(node_cursor != nullptr);
  assert(other.node_cursor != nullptr);
  return node_cursor->get_value() > other.node_cursor->get_value();
}

template <class T>
auto DoublyLinkedList<T>::operator==(DoublyLinkedList<T> other) -> bool {
  if (node_cursor == nullptr || other.node_cursor == nullptr)
    return node_cursor == other.node_cursor;
  return node_cursor->get_value() == other.node_cursor->get_value();
}

template class DoublyLinkedList<int>;
