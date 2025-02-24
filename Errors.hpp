#include <string>

#pragma once

class StackOverflowError {
  std::string message = "Stack Overflow";
};

class StackUnderflowError {
  std::string message = "Stack Underflow";
};

class QueueOverflowError {
  std::string message = "Queue Overflow";
};

class QueueUnderflowError {
  std::string message = "Queue Underflow";
};
