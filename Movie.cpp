#include <iostream>

#include "Movie.hpp"

bool Movie::set_rating(double rating) {
  if (rating <= 0. || rating >= 10.) {
    std::cout << "Rating must be between 0 and 10." << std::endl;
    return false;
  }
  this->rating = rating;
  return true;
}

void Movie::Play() { std::cout << "Rating: " << rating << std::endl; }

void Movie::Details() {
  std::cout << "Title: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Rating: " << rating << std::endl;
}
