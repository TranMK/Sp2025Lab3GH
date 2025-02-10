#include <iostream>

#include "Show.hpp"

bool Show::set_title(std::string title) {
  if (title.empty()) {
    std::cout << "Show title cannot be empty. Try again." << std::endl;
    return true;
  }
  this->title = title;
  return false;
}

bool Show::set_description(std::string description) {
  if (description.empty()) {
    std::cout << "Show description cannot be empty. Try again." << std::endl;
    return true;
  }
  this->description = description;
  return false;
}

bool Show::set_show_id(size_t show_id) {
  this->show_id = show_id;
  return true;
};

void Show::Details() {
  std::cout << "Show: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
}
