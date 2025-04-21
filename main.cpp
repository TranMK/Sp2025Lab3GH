#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <random>
#include <ranges>
#include <string>
#include <utility>

#include "linked_list.hpp"

// SORTS.
template <size_t SIZE> constexpr void bubble_sort(std::array<int, SIZE> &arr);
template <size_t SIZE>
constexpr void insertion_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void merge_sort(std::array<int, SIZE> &arr);
template <size_t SIZE> constexpr void quick_sort(std::array<int, SIZE> &arr);
template <size_t SIZE>
constexpr auto counting_sort(std::array<int, SIZE> &indices,
                             std::array<int, SIZE> &arr)
    -> std::array<int, SIZE>;
template <size_t SIZE> constexpr void radix_sort(std::array<int, SIZE> &arr);

// Prepares array for sorting.
template <size_t SIZE>
constexpr auto generate_random_array() -> std::array<int, SIZE>;
// Times the sorts.
template <size_t SIZE>
constexpr auto benchmark(std::array<int, SIZE> &) -> double;

auto main() -> int {
  constexpr std::array<size_t, 6> sizes = {10, 100, 500, 5000, 25000, 100000};

  auto test_array = generate_random_array<sizes[0]>();
  auto test_indices = std::array<int, test_array.size()>();
  for (size_t idx = 0; idx < test_indices.size() - 1; ++idx) {
    test_indices[idx] = idx;
  }
  auto sorted = counting_sort(test_indices, test_array);
  for (int item : sorted) {
    std::cout << item << std::endl;
  }

  return 0;
}

template <size_t SIZE>
constexpr auto benchmark(std::array<int, SIZE> &arr) -> double {
  return 0;
}

// Generates a vector of random integers of size `n` with values in the range
// [0, 2*n].
template <size_t SIZE>
constexpr auto generate_random_array() -> std::array<int, SIZE> {
  std::array<int, SIZE> arr; // Size n
  int max_val = 2 * static_cast<int>(SIZE);

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

// Logic from the pseudocode listed in
// https://en.wikipedia.org/wiki/Counting_sort.
template <size_t SIZE>
constexpr auto counting_sort(std::array<int, SIZE> &indices,
                             std::array<int, SIZE> &arr)
    -> std::array<int, SIZE> {
  int *max_item = std::max_element(arr.begin(), arr.end());
  std::vector<int> counts(*max_item);
  std::array<int, SIZE> output;

  for (size_t idx = 0; idx < arr.size(); ++idx) {
    auto j = arr[idx];
    counts[j] += 1;
  }

  for (size_t idx = 0; idx < *max_item; ++idx) {
    counts[idx] = counts[idx] + counts[idx - 1];
  }

  for (size_t idx = arr.size(); idx > 0; --idx) {
    auto j = arr[idx];
    counts[j] -= 1;
    output[counts[j]] = arr[j];
    indices[counts[j]] = idx;
    std::cout << "INDEX MOVED FROM " << idx << " TO " << counts[j] << std::endl;
  }

  return output;
}

// template <size_t SIZE> constexpr void radix_sort(std::array<int, SIZE> &arr)
// {
//   auto pad_left = [](std::string s, size_t length) {
//     s.insert(s.begin(), length - s.length(), '0');
//   };

//   size_t max_item = std::max(arr);
//   std::array<int, SIZE> arr_as_string =
//       std::for_each(arr.begin(), arr.end(), pad_left(max_item));
//   std::array<int, SIZE> output;

//   // Passes.
//   std::array<size_t, SIZE> index_map;
//   auto get_digit_as_char = [char](size_t number, size_t position) {
//     return std::string(number)[1];
//   };
//   for (char[] : arr_as_string) {
//   }

//   return output;
// }
