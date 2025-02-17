#include "Movie.hpp"

#pragma once

const size_t MAX_MOVIES = 10;

class Shelf {
  Movie *movies[MAX_MOVIES] = {};
  size_t movie_count = 0;

public:
  Shelf() = default;
  void add_movie(Movie *movie_to_add);
  Movie *remove_movie();
  size_t get_movie_count() { return movie_count; }
};
