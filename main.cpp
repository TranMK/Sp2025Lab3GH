#include <iostream>
#include <string>

#include "Shelf.hpp"

template <class T> void print_show(T s);
void get_and_add_movie_attributes(Movie *movie);

int main() {
  Shelf shelf;

  while (true) {
    std::cout << "--- OPTIONS ---" << std::endl;
    std::cout << "Press 1 to add a movie to the shelf" << std::endl;
    std::cout << "Press 2 to remove a movie from the shelf" << std::endl;
    std::cout << "Press 3 to see how many movies are on the shelf" << std::endl;
    std::cout << "Press 4 to quit" << std::endl;
    std::string user_option;
    std::getline(std::cin, user_option);
    if (user_option == "4") {
      break;
    }

    switch (std::stoul(user_option)) {
    case 1: {
      auto *new_movie = new Movie;
      get_and_add_movie_attributes(new_movie);
      shelf.add_movie(new_movie);
      break;
    }
    case 2: {
      shelf.remove_movie();
      break;
    }
    case 3:
      size_t movie_count = shelf.get_movie_count();
      std::cout << movie_count << " movie(s) left in the shelf." << std::endl;
      break;
    }
  }

  return 0;
}

// No explicit restriction on T since the user does not call this function.
template <class T> void print_show(T show) {
  show.Play();
  show.Details();
};

void get_and_add_movie_attributes(Movie *movie) {
  std::string movie_title, movie_description, movie_rating_as_str;
  std::cout << "Enter the title of the movie: ";
  std::getline(std::cin, movie_title);
  std::cout << std::endl;
  std::cout << "Enter the description of the movie: ";
  std::getline(std::cin, movie_description);
  std::cout << std::endl;
  std::cout << "Enter the rating of the movie: ";
  std::getline(std::cin, movie_rating_as_str);
  std::cout << std::endl;

  size_t movie_rating = std::stoul(movie_rating_as_str);
  movie->set_title(movie_title);
  movie->set_description(movie_description);
  movie->set_rating(movie_rating);
};
