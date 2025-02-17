#include <iostream>

#include "Game.hpp"

bool Game::set_rating(double rating) {
  if (rating <= 0. || rating >= 10.) {
    std::cout << "Rating must be between 0 and 10." << std::endl;
    return false;
  }
  game_rating = rating;
  return true;
}
void Game::Details() {
  std::cout << "Title: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Rating: " << game_rating << std::endl;
}
