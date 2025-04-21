#include "linked_list.hpp"
#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <random>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

// SORTS.
template <size_t SIZE> constexpr void bubble_sort(std::array<int, SIZE> &arr);
template <size_t SIZE>
constexpr void insertion_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void merge_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void quick_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void counting_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void radix_sort(std::array<int, SIZE> &arr);

// Prepares array for sorting.
template <size_t SIZE>
constexpr auto generate_random_array(size_t n) -> std::array<int, SIZE>;
// Times the sorts.
template <size_t SIZE>
constexpr auto benchmark(std::array<int, SIZE> &) -> double;

auto main() -> int {
  constexpr std::array<size_t, 6> sizes = {10, 100, 500, 5000, 25000, 100000};

  return 0;
}

template <size_t SIZE>
constexpr auto benchmark(std::array<int, SIZE> &arr) -> double {
  return 0;
}

// Generates a vector of random integers of size `n` with values in the range
// [0, 2*n].
template <size_t SIZE>
constexpr auto generate_random_array(size_t n) -> std::array<int, SIZE> {
  std::array<int, SIZE> arr(n); // Size n
  int max_val = 2 * static_cast<int>(n);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, max_val);

  for (auto &x : arr)
    x = dist(gen);
  return arr; // Return the generated vector
}

template <size_t SIZE> constexpr void bubble_sort(std::array<int, SIZE> &arr) {
  size_t size = arr.size();
  for (size_t i = 0; i < size - 1; i++) {

    for (size_t j = 0; j < size - 1; j++) {

      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

template <size_t SIZE>
constexpr void insertion_sort(std::array<int, SIZE> &arr) {
  size_t size = arr.size();
}

template <size_t SIZE>
constexpr void counting_sort(std::array<int, SIZE> &arr) {}

template <size_t SIZE> constexpr void radix_sort(std::array<int, SIZE> &arr) {
  // Passes.
}
