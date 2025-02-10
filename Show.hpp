#include <string>
#include <utility>

class Show {
protected:
  std::string title;
  std::string description;
  size_t show_id;

public:
  virtual void Play();
  void Details();

  bool set_title(std::string title);
  bool set_description(std::string description);
  bool set_show_id(size_t show_id);
  std::string get_title() { return title; };
  std::string get_description() { return description; };
  size_t get_show_id() { return show_id; };

  Show() : title(""), description("") {}
  Show(std::string title, std::string description)
      : title(std::move(title)), description(std::move(description)) {}
};
