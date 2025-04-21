#include <string>

#pragma once

struct ItemNotFoundError {
  std::string message = "Not Found";
};

struct SeeEmptyListError {
  std::string message = "Attempted to peek inside an empty list.";
};

struct OutOfBoundsError {
  std::string message = "Attempted to peek outside the list.";
};
