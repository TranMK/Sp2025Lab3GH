#include <iostream>
#include <string>

#include "EnterCollect.hpp"
#include "Game.hpp"

template <class T> void print_show(T s);
void get_and_add_Game_attributes(Game *Game);

int main() {
  EnterCollect<Game> collection;

  while (true) {
    std::cout << "--- OPTIONS ---" << std::endl;
    std::cout << "Press 1 to add a Game to the collection" << std::endl;
    std::cout << "Press 2 to remove a Game from the collection" << std::endl;
    std::cout << "Press 3 to see how many Games are on the collection" << std::endl;
    std::cout << "Press 4 to quit" << std::endl;
    std::string user_option;
    std::getline(std::cin, user_option);
    if (user_option == "4") {
      break;
    }

    switch (std::stoul(user_option)) {
    case 1: {
      auto *new_Game = new Game;
      get_and_add_Game_attributes(new_Game);
      collection.add_T(new_Game);
      break;
    }
    case 2: {
      Game *removed_Game = collection.remove_T();
      removed_Game->Details();
      break;
    }
    case 3:
      size_t Game_count = collection.get_T_count();
      std::cout << Game_count << " Game(s) left in the collection." << std::endl;
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

void get_and_add_Game_attributes(Game *Game) {
  std::string Game_title, Game_description, Game_rating_as_str;
  std::cout << "Enter the title of the Game: ";
  std::getline(std::cin, Game_title);
  std::cout << std::endl;
  std::cout << "Enter the description of the Game: ";
  std::getline(std::cin, Game_description);
  std::cout << std::endl;
  std::cout << "Enter the rating of the Game: ";
  std::getline(std::cin, Game_rating_as_str);
  std::cout << std::endl;

  size_t Game_rating = std::stoul(Game_rating_as_str);
  Game->set_title(Game_title);
  Game->set_description(Game_description);
  Game->set_rating(Game_rating);
};
