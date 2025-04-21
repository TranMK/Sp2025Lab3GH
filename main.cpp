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
template <size_t SIZE> constexpr void merge_sort(std::array<int, SIZE> &arr, int l, int r);
template <size_t SIZE> constexpr void merge(std::array<int, SIZE> &arr, int l, int m, int r);
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
  int key = 0;
  int j = 0;
  for(int i = 0; i < arr.size(); i++){
    key = arr[i];
    j = i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  } 
}

// Logic from the pseudocode listed in
// https://en.wikipedia.org/wiki/Counting_sort.
template <size_t SIZE>
constexpr void counting_sort(std::array<int, SIZE> &arr) {
  constexpr size_t max_item = std::max(arr);
  std::array<int, max_item + 1> counts;
  std::array<int, SIZE> output;

  for (size_t idx = 0; idx < arr.size(); ++idx) {
    auto j = arr[idx];
    counts[j] += 1;
  }

  for (size_t idx = 0; idx < max_item; ++idx) {
    counts[idx] = counts[idx] + counts[idx - 1];
  }

  for (size_t idx = arr.size(); idx > 0; --idx) {
    auto j = arr[idx];
    counts[j] -= 1;
    output[counts[j]] = arr[j];
  }

  return output;
}

template <size_t SIZE> constexpr void radix_sort(std::array<int, SIZE> &arr) {
  // Passes.
}
template <size_t SIZE> constexpr void merge_sort(std::array<int, SIZE>& arr, int l, int r){
  if(l < r){
    int m = l + floor(r-l)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}
template <size_t SIZE> constexpr void merge(std::array<int, SIZE>& arr, int l, int m, int r){
  int elements_on_left = m - l + 1;
  int elements_on_right = r - m;
  std::vector<int> lefthalf(arr.begin()+l, arr.begin()+m+1);
  std::vector<int> righthalf(arr.begin()+m+1, arr.begin()+r+1);
  int lefthalfindex = 0;
  int righthalfindex = 0;
  int k = l;
  while(lefthalfindex < elements_on_left && righthalfindex < elements_on_right){
    arr[k++] = (lefthalf[lefthalfindex]<=righthalf[righthalfindex]) ? lefthalf[lefthalfindex] : righthalf[righthalfindex];
  }while(lefthalfindex < elements_on_left) arr[k++] = lefthalf[lefthalfindex++];
  while(righthalfindex < elements_on_right) arr[k++] = righthalf[righthalfindex++];
}