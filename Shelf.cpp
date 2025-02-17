#include "Shelf.hpp"

void Shelf::add_movie(Movie *movie_to_add) {
  if (movie_count == MAX_MOVIES) {
    throw std::string("FullShelfError");
  }
  movies[movie_count++] = movie_to_add;
}

Movie *Shelf::remove_movie() {
  if (movie_count == 0) {
    throw std::string("EmptyShelfError");
  }
  Movie *copy = movies[movie_count - 1];
  movies[--movie_count] = nullptr;
  return copy;
}
