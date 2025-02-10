#include <iostream>
#include <string>

#include "Movie.hpp"
#include "TVShow.hpp"

void print_show(Show show);

int main() {
  bool should_quit = false;

  while (!should_quit) {

    std::cout << "Which of the following would you like to create? "
              << std::endl;
    std::cout << "1) Show " << std::endl;
    std::cout << "2) Movie " << std::endl;
    std::cout << "3) TV Show" << std::endl;
    std::cout << "4) Movie declared as a Show" << std::endl;
    std::cout << "5) TVShow declared as a Show" << std::endl;
    std::string user_selection;
    std::getline(std::cin, user_selection);
    size_t user_option = std::stoul(user_selection);

    switch (user_option) {
    case 1: {
      Show show;
      print_show(show);
      break;
    }
    case 2: {
      handle_movie_creation();
      Movie show;
      print_show(show);
      break;
    }
    case 3: {
      handle_tvshow_creation();
      Show show;
      print_show(show);
      break;
    }
    case 4: {
      handle_movie_as_show_creation();
      Show show;
      print_show(show);
      break;
    }
    case 5: {
      handle_tvshow_as_show_creation();
      Show show;
      print_show(show);
      break;
    }
    }

    std::cout << "Do you wish to continue? (Y/N): ";
    std::string user_quit;
    std::getline(std::cin, user_quit);
    while (user_quit != "Y" && user_quit != "y"){
        if (user_quit == "N" || user_quit == "n") {
        should_quit = true;
        break;
        }
        std::cout << "Invalid input. Please enter Y or N: ";
        std::getline(std::cin, user_quit);
    }
    std::cout << std::endl;
  }

  return 0;
}

void print_show(Show show) {
  show.Play();
  show.Details();
};
