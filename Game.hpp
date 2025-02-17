#pragma once
#include <iostream>
class Game{
public:
  std::string title;
  std::string description;
  double game_rating;

public:
  void set_title(std::string title) {this->title = title;}
  void set_description(std::string description) {this->description = description;}
  bool set_rating(double rating);
  double get_rating() { return game_rating; };
  void Details();
};
