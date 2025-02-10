#include <string>
#include <utility>

#pragma once

class Show {
protected:
  std::string title;
  std::string description;

public:
  void Details();
  virtual void Play() {};

  bool set_title(std::string title);
  bool set_description(std::string description);
  std::string get_title() { return title; };
  std::string get_description() { return description; };

  Show() : title(""), description("") {}
  Show(std::string title, std::string description)
      : title(std::move(title)), description(std::move(description)) {}
};
