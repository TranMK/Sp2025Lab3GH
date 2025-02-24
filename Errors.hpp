#include <string>

#pragma once

class StackOverflowError {
public:
  std::string message = "Stack Overflow";
};

class StackUnderflowError {
public:
  std::string message = "Stack Underflow";
};

class QueueOverflowError {
public:
  std::string message = "Queue Overflow";
};

class QueueUnderflowError {
public:
  std::string message = "Queue Underflow";
};
