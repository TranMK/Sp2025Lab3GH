#include <cstddef>
#include <ostream>

class Measurement {
private:
  size_t heaps;
  size_t lots;
  size_t littles;

public:
  // Constructors.
  Measurement();
  Measurement(size_t heaps, size_t lots, size_t littles);
  Measurement(size_t littles);

  // Getters.
  size_t get_heaps() { return heaps; }
  size_t get_lots() { return lots; }
  size_t get_littles() { return littles; }

  // Setters.
  void set_heaps(size_t heaps) {
    this->heaps = heaps;
    this->rebalance();
  }
  void set_lots(size_t lots) {
    this->lots = lots;
    this->rebalance();
  }
  void set_littles(size_t littles) {
    this->littles = littles;
    this->rebalance();
  }

  // Overloads.
  void operator+(Measurement other);
  void operator-(Measurement other);
  void operator*(Measurement other);
  void operator/(Measurement other);
  bool operator==(Measurement other);

  // Convenience.
  friend std::ostream &operator<<(std::ostream &os, Measurement &self);
  void rebalance();
  size_t to_meters();
};
