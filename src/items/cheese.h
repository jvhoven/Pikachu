#include "pikachu/base/item.hpp"
#include <string>

class Cheese : public Pikachu::Item {
public:
  Cheese(std::string name, Pikachu::Item::Type type, std::string description);
};
