#include "heaplotlittle.hpp"
#include <cmath>

Measurement::Measurement() {
  heaps = 0;
  lots = 0;
  littles = 0;
}

Measurement::Measurement(const double heaps, const double lots, const double littles) : heaps(heaps), lots(lots), littles(littles) {}

Measurement::Measurement(const double littles) {
  double total_heap_count = littles / (23. * 7.);
  double heap_count, leftover_heap;
  leftover_heap = std::modf(total_heap_count, &heap_count);
  heaps = heap_count;

  double total_littles_leftover_after_heaps = leftover_heap * 23. * 7.;

  double total_lots_count= total_littles_leftover_after_heaps / 7.;
  double lots_count, leftover_lots;
  leftover_lots = std::modf(total_lots_count, &lots_count);
  lots = lots_count;

  double total_littles_leftover_after_lots = leftover_lots * 7.;
  /* for no namespace "collisions" */ this->littles = total_littles_leftover_after_lots;
}
