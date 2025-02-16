#include <iostream>

#include "TVShow.hpp"

void TVShow::Play() {
  std::string season_number_str, episode_number_str;
  std::cout << "What season number do you wish to play? ";
  std::getline(std::cin, season_number_str);
  std::cout << std::endl;
  std::cout << "What episode number do you wish to play? ";
  std::getline(std::cin, episode_number_str);
  std::cout << std::endl;
  size_t season_number, episode_number;
  season_number = std::stoul(season_number_str);
  episode_number = std::stoul(episode_number_str);

  std::string episode_summary =
      seasons[season_number - 1].episodes_with_summaries[episode_number];
  std::cout << "Episode summary: " << episode_summary << std::endl;
};

void TVShow::Details() {
  std::cout << "--- TVSHOW ---" << std::endl;
  std::cout << "Title: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Number of seasons: " << seasons.size() << std::endl;
  std::cout << std::endl;
};
