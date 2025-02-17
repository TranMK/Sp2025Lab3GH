#include "Shelf.hpp"

Movie *Shelf::remove_movie() {
  Movie *copy = movies[movie_count - 1];
  movies[--movie_count] = nullptr;
  return copy;
}
