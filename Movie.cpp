#include <iostream>

#include "Movie.hpp"

bool Movie::set_rating(double rating) {
  if (rating < 0. || rating > 10.) {
    std::cout << "Rating must be between 0 and 10." << std::endl;
    return false;
  }
  movie_rating = rating;
  return true;
}

void Movie::Play() {
  std::cout << "--- MOVIE---" << std::endl;
  std::cout << "Rating: " << movie_rating << std::endl;
  std::cout << std::endl;
}

void Movie::Details() {
  std::cout << "--- MOVIE---" << std::endl;
  std::cout << "Title: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Rating: " << movie_rating << std::endl;
  std::cout << std::endl;
}
