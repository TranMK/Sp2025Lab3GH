#include <array>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "linked_list.hpp"

void bubble_sort(size_t arr);
template <size_t SIZE, class T> auto benchmark(std::array<T, SIZE> &) -> double;

auto main() -> int {
  constexpr std::array<size_t, 5> ARRAY_SIZES = {10, 100, 500, 5000, 25000};

  return 0;
}

template <size_t SIZE, class T>
auto benchmark(std::array<T, SIZE> &arr) -> double {
  return 0;
}
