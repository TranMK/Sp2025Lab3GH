#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "linked_list.hpp"

void bubble_sort(std::vector<int> &arr);
void insertion_sort(std::vector<int> &arr);
void merge_sort(std::vector<int> &arr);
void quick_sort(std::vector<int> &arr);
void counting_sort(std::vector<int> &arr);
void radix_sort(std::vector<int> &arr);


template <size_t SIZE, class T> auto test(std::array<T, SIZE> &) -> double;
std::vector<int> generate_random_array(size_t n);
auto main() -> int {
  std::vector<size_t> sizes = {10, 100, 500, 5000, 25000, 100000};
  // int arr[ARRAY_SIZE]={};
  //   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  //   std::shuffle(arr.begin(), number_list.end(), std::default_random_engine(seed));//randomizes placement
  return 0;
}

auto main() -> int {
  return 0;
}

template <size_t SIZE, class T> auto test(std::array<T, SIZE> &arr) -> double {
  return 0;
}
// Generates a vector of random integers of size `n` with values in the range [0, 2*n].
std::vector<int> generate_random_array(size_t n){
  std::vector<int> arr(n); // Size n
  int max_val = 2 * static_cast<int>(n);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, max_val);
  for(auto &x: arr) x = dist(gen);
  return arr; // Return the generated vector
}
void bubble_sort(std::vector<int>& arr){
  size_t size = arr.size();
  for(size_t i = 0; i < size-1; i++){

    for(size_t j = 0; j < size-1; j++){

      if(arr[j]>arr[j+1]){
        std::swap(arr[j],arr[j+1]);
      }
    }
  }
}
void insertion_sort(std::vector<int>& arr){
  size_t size = arr.size();
  
}