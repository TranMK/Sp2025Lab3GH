#include <map>
#include <vector>

#include "Show.hpp"

struct Season {
  std::map<size_t, std::string> episodes_with_summaries;
};

class TVShow : public Show {
  std::vector<Season> seasons;

  void Play() override;
  void Details();
};
