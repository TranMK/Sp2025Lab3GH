#include <cmath>
#include <iostream>

#include "heaplotlittle.hpp"
#include "utility.cpp"

const double little_to_meter = 1.;

Measurement::Measurement() {
  heaps = 0;
  lots = 0;
  littles = 0;
}

Measurement::Measurement(const double heaps, const double lots,
                         const double littles)
    : heaps(heaps), lots(lots), littles(littles) {
  this->littles = to_littles();
  this->heaps = 0;
  this->lots = 0;
  this->rebalance();
}

void Measurement::operator+(Measurement other) {
  littles = to_littles() + other.to_littles();
  this->rebalance();
};

void Measurement::operator-(Measurement other) {
  double total_littles = to_littles();
  if (total_littles < other.to_littles()) {
    std::cout << "Subtraction operation would result in a negative distance."
              << std::endl;
    return;
  } else {
    // total_littles -= other.to_littles();
    littles = total_littles - other.to_littles();
    this->rebalance();
    return;
  }
}

void Measurement::operator*(Measurement other) {
  littles = to_littles() * other.to_littles();
  this->rebalance();
};

void Measurement::operator/(Measurement other) {
  if (other.to_littles() == 0) {
    std::cout << "Divider is 0." << std::endl;
    return;
  }

  littles = to_littles() / other.to_littles();
  this->rebalance();
};

bool Measurement::operator==(Measurement other) {
  return (doubles_equal(heaps, other.heaps)) &&
         (doubles_equal(lots, other.lots)) &&
         (doubles_equal(littles, other.littles));
};

std::ostream &operator<<(std::ostream &os, Measurement &self) {
  os << "Heaps: " << self.get_heaps() << std::endl;
  os << "Lots: " << self.get_lots() << std::endl;
  os << "Littles: " << self.get_littles() << std::endl;
  return os;
}

void Measurement::rebalance() {
  heaps = 0;
  lots = 0;

  // Lots.
  double littles_as_lots = littles / 7.;
  lots = std::floor(littles_as_lots);
  littles -= lots * 7.;

  // Heaps.
  size_t lots_as_heaps = lots / 23.;
  heaps = std::floor(lots_as_heaps);
  lots -= heaps * 23;
}

double Measurement::to_meters() {
  double total_littles = (heaps * 23 * 7) + (lots * 7);
  double total_meters = total_littles * little_to_meter;
  return total_meters;
}

double Measurement::to_littles() {
  double total_littles =
      (get_heaps() * 23 * 7) + (get_lots() * 7) + get_littles();
  return total_littles;
}
