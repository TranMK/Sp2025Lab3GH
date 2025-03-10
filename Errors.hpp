#include <string>

class SeeEmptyListError {
  std::string message = std::string("Attempted to see an empty list.");

public:
  auto display() -> std::string { return message; };
};

class OutOfBoundsError {
  std::string message = std::string("No item at that index.");

public:
  auto display() -> std::string { return message; };
};

class ItemNotFound {
  std::string message = std::string("That item was not found in the list.");

public:
  auto display() -> std::string { return message; };
};
