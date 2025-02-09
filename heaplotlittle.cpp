#include <iostream>

#include "heaplotlittle.hpp"

Measurement::Measurement() {
  heaps = 0;
  lots = 0;
  littles = 0;
}

Measurement::Measurement(const size_t heaps, const size_t lots,
                         const size_t littles)
    : heaps(heaps), lots(lots), littles(littles) {
  this->rebalance();
}

Measurement::Measurement(const size_t littles) {
  size_t leftover_littles = littles;
  // Heaps.
  size_t total_heap_count = leftover_littles / (23. * 7.);
  heaps = total_heap_count;
  leftover_littles -= total_heap_count * 23 * 7;

  // Lots.
  size_t total_lots_count = leftover_littles / 7.;
  lots = total_lots_count;
  leftover_littles -= total_lots_count * 7;

  // Littles.
  this->littles = leftover_littles;

  this->rebalance();
}

void Measurement::operator+(Measurement other) {
  heaps = this->heaps + other.heaps;
  lots = this->lots + other.lots;
  littles = this->littles + other.littles;

  this->rebalance();
};

void Measurement::operator-(Measurement other) {
  heaps = this->heaps - other.heaps;
  lots = this->lots - other.lots;
  littles = this->littles - other.littles;

  this->rebalance();
};

void Measurement::operator*(Measurement other) {
  heaps = this->heaps * other.heaps;
  lots = this->lots * other.lots;
  littles = this->littles * other.littles;

  this->rebalance();
};

void Measurement::operator/(Measurement other) {
  heaps = this->heaps / other.heaps;
  lots = this->lots / other.lots;
  littles = this->littles / other.littles;

  this->rebalance();
};

bool Measurement::operator==(Measurement other) {
  return (heaps == other.heaps) && (lots == other.lots) &&
         (littles == other.littles);
};

std::ostream &operator<<(std::ostream &os, Measurement &self) {
  os << "HEAPS: " << self.get_heaps() << std::endl;
  os << "LOTS: " << self.get_lots() << std::endl;
  os << "LITTLES: " << self.get_littles() << std::endl;
  return os;
}

void Measurement::rebalance() {
  // Lots.
  size_t lots_from_littles = littles / 7;
  lots += lots_from_littles;
  littles -= lots_from_littles * 7;

  // Heaps.
  size_t heaps_from_littles = littles / (23 * 7);
  littles -= heaps_from_littles * 23 * 7;
  heaps += heaps_from_littles;
  size_t heaps_from_lots = lots / 23;
  lots -= heaps_from_lots * 23;
  heaps += heaps_from_lots;
}

size_t Measurement::to_meters() { return 0; }
