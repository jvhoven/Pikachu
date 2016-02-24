#include <iostream>

#include "pikachu/entity.hpp"

class EntityTest : public Pikachu::Entity {
public:
  EntityTest(unsigned int level, unsigned int health, std::string name)
    : Pikachu::Entity(level, health, name) {};
  unsigned int getLevel() const {
    return _level;
  }
};

int main() {
  EntityTest test(12, 200, "De naam");
  std::cout << test.getName() << std::endl;
  return 0;
}
