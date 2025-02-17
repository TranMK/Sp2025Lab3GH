#include "Movie.hpp"

#pragma once

const size_t MAX_MOVIES = 10;

class Shelf {
  Movie *movies[MAX_MOVIES] = {nullptr};
  size_t movie_count = 0;

public:
  Shelf() = default;
  void add_movie(Movie movie_to_add) { movies[movie_count++] = &movie_to_add; };
  void remove_movie(Movie movie_to_add) { movies[--movie_count] = nullptr; };
  size_t get_movie_count() { return movie_count; }
};
