#include <ostream>

class Measurement {
private:
  double heaps = 0.;
  double lots = 0.;
  double littles = 0.;

public:
  // Constructors.
  Measurement();
  Measurement(double heaps, double lots, double littles);
  Measurement(double littles) {
    this->littles = littles;
    this->rebalance();
  };

  // Getters.
  double get_heaps() { return heaps; }
  double get_lots() { return lots; }
  double get_littles() { return littles; }

  // Setters.
  void set_heaps(double heaps) {
    this->heaps = heaps;
    this->rebalance();
  }
  void set_lots(double lots) {
    this->lots = lots;
    this->rebalance();
  }
  void set_littles(double littles) {
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
  double to_meters();
  double to_littles();
};
