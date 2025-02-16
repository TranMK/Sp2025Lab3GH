#include "Show.hpp"

#pragma once

class Movie : public Show {
public:
  double movie_rating;

public:
  bool set_rating(double rating);
  double get_rating() { return movie_rating; };

  void Play() override;
  void Details();
};
