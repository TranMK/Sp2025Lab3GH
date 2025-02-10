#include <map>
#include <vector>

#include "Show.hpp"

struct Season {
  std::map<size_t, std::string> episodes_with_summaries;
};

class TVShow : public Show {
  std::vector<Season> seasons;

public:
  void Play() override;
  void Details();

  void set_seasons(std::vector<Season> seasons) { this->seasons = seasons; };
  std::vector<Season> get_seasons() { return seasons; };
};
