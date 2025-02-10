#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Movie.hpp"
#include "Show.hpp"
#include "TVShow.hpp"

template <class T> void print_show(T s);
std::vector<Season> get_tv_show_seasons();

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
      std::cout << "Title of Show: ";
      std::string show_title, show_decription;
      std::getline(std::cin, show_title);
      std::cout << "Description of Show: ";
      std::getline(std::cin, show_decription);

      Show show = Show(show_title, show_decription);
      print_show(show);
      break;
    }
    case 2: {
      std::cout << "Title of Movie: ";
      std::string movie_title, movie_description, movie_rating;
      std::getline(std::cin, movie_title);
      std::cout << "Description of Movie: ";
      std::getline(std::cin, movie_description);
      std::cout << "Rating of Movie: ";
      std::getline(std::cin, movie_rating);

      Movie movie;
      movie.set_title(movie_title);
      movie.set_description(movie_description);
      while (!movie.set_rating(std::stod(movie_rating))) {
        std::cout << "Rating of Movie: ";
        std::getline(std::cin, movie_rating);
      }
      print_show(movie);
      break;
    }
    case 3: {
      std::cout << "Title of TVShow: ";
      std::string tv_show_title, tv_show_description;
      std::getline(std::cin, tv_show_title);
      std::cout << "Description of TVShow: ";
      std::getline(std::cin, tv_show_description);

      TVShow tv_show;
      tv_show.set_title(tv_show_title);
      tv_show.set_description(tv_show_description);
      tv_show.set_seasons(get_tv_show_seasons());
      print_show(tv_show);
      break;
    }
    case 4: {
      std::cout << "Title of Movie: ";
      std::string movie_title, movie_description, movie_rating;
      std::getline(std::cin, movie_title);
      std::cout << "Description of Movie: ";
      std::getline(std::cin, movie_description);
      std::cout << "Description of Movie: ";
      std::getline(std::cin, movie_description);

      Movie movie;
      movie.set_title(movie_title);
      movie.set_description(movie_description);
      movie.set_rating(std::stod(movie_rating));
      Show show = movie;
      print_show(movie);
      break;
    }
    case 5: {
      std::cout << "Title of TVShow: ";
      std::string tv_show_title, tv_show_description;
      std::getline(std::cin, tv_show_title);
      std::cout << "Description of TVShow: ";
      std::getline(std::cin, tv_show_description);

      TVShow tv_show;
      tv_show.set_title(tv_show_title);
      tv_show.set_description(tv_show_description);
      tv_show.set_seasons(get_tv_show_seasons());
      Show show = tv_show;
      print_show(show);
      break;
    }
    }

    std::cout << "Do you wish to continue? (Y/N): ";
    std::string user_quit;
    std::getline(std::cin, user_quit);
    while (user_quit != "Y" && user_quit != "y") {
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

// No explicit restriction on T since the user does not call this function.
template <class T> void print_show(T show) {
  show.Play();
  show.Details();
};

std::vector<Season> get_tv_show_seasons() {
  std::string num_seasons_str;
  std::cout << "Enter the number of seasons: ";
  std::getline(std::cin, num_seasons_str);
  size_t num_seasons = std::stoul(num_seasons_str);

  std::vector<Season> seasons = std::vector<Season>(num_seasons);

  size_t episode_number = 1;
  // Default value so the while doesn't run.
  std::string episode_description = "0";
  for (size_t season = 0; season < num_seasons; season++) {

    while (!episode_description.empty()) {
      std::cout << "Enter the description for Season " << season + 1
                << " Episode " << episode_number
                << ". Enter nothing and press <ENTER> to stop adding episodes";
      std::getline(std::cin, episode_description);
      if (episode_description.empty()) {
        break;
      }

      seasons[season].episodes_with_summaries[episode_number] =
          episode_description;

      episode_number += 1;
    }
  }

  return seasons;
};
