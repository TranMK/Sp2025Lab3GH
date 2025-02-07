#include <cmath>
#include <iostream>

#include "heaplotlittle.hpp"

Measurement::Measurement() {
  heaps = 0;
  lots = 0;
  littles = 0;
}

Measurement::Measurement(const double heaps, const double lots,
                         const double littles)
    : heaps(heaps), lots(lots), littles(littles) {
  this->rebalance();
}

Measurement::Measurement(const double littles) {
  // Heaps.
  double total_heap_count = littles / (23. * 7.);
  double heap_count, leftover_heap;
  leftover_heap = std::modf(total_heap_count, &heap_count);
  heaps = heap_count;

  // Lots.
  double total_littles_leftover_after_heaps = leftover_heap * 23. * 7.;
  double total_lots_count = total_littles_leftover_after_heaps / 7.;
  double lots_count, leftover_lots;
  leftover_lots = std::modf(total_lots_count, &lots_count);
  lots = lots_count;

  // Littles.
  double total_littles_leftover_after_lots = leftover_lots * 7.;
  /* for no namespace "collisions" */ this->littles =
      std::roundf(total_littles_leftover_after_lots);

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

std::ostream& operator<<(std::ostream& os, Measurement& self) {
  os << "HEAPS: " << self.get_heaps() << std::endl;
os << "LOTS: " << self.get_lots() << std::endl;
  os << "LITTLES: " << self.get_littles() << std::endl;
  return os;
}

void Measurement::rebalance() {
  double lots_from_littles;
  double leftover_littles =
      std::modf(/* lots */ littles / 7, &lots_from_littles);
  lots += lots_from_littles;
  double total_littles_after_lots_extraction = leftover_littles * 7;
  littles = total_littles_after_lots_extraction;

  double heaps_from_lots;
  double leftover_lots = std::modf(/* heaps */ lots / 23, &heaps_from_lots);
  heaps += heaps_from_lots;
  double total_lots_after_heaps_extraction = leftover_lots * 7;
  lots = total_lots_after_heaps_extraction;
}

double Measurement::to_meters() { return 0; }
