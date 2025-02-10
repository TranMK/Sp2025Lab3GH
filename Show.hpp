#include <string>
#include <utility>

class Show {
  std::string title;
  std::string description;
  size_t show_id;

public:
  bool set_title(std::string title);
  bool set_description(std::string description);
  bool set_show_id(size_t show_id);
  std::string get_title() { return title; };
  std::string get_description() { return description; };
  size_t get_show_id() { return show_id; };

  virtual void Play() = 0;
  void Details();

  Show() : title(""), description("") {}
  Show(std::string title, std::string description)
      : title(std::move(title)), description(std::move(description)) {}
};
