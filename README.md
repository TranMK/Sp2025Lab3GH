---
title: "CS2028C Lab 3"
author: [Ansh Mendiratta, Khoi Tran, Thanh Tin]
date: "2025-02-06"
---

# Sp2025Lab3

Group members:

  - Ansh Mendiratta (Wrote class member implementations, `unit_tests.cpp`, and `main.cpp`)
  - Khoi Tran (Fixed bugs)
  - Thanh Tin

## Compilation
Run `make`. If this does not work, run `g++ --std=c++2b main.cpp heaplotlittle.hpp heaplotlittle.cpp; ./a.out`

To run tests, run `make test`. This runs everything in `unit_tests.cpp` but not the required test from the assignment.

## Class Declaration
Additional procedures that weren't required by the assignment:

  - `Measurement::to_str()`: returns a string (from a stream) that prints out the measurement's quantities line by line.
  - `Measurement::rebalance()`: rebalances the quantities if each of them (minus the heaps) can be "compacted".
  - `Measurement::to_littles()`: uses the instance member variable values to convert into an equivalent `littles` count. Used for `rebalance()` and the arithmetic operations.
  - `Measurement::to_littles()`: uses the instance member variable values to convert into an equivalent `littles` count. Used for `rebalance()` and the arithmetic operations.

## Assumptions
1. A `little` is equal to 1. meters.
