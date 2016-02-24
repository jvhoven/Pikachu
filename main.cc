#include <iostream>

#include "pikachu/entity.hpp"
#include "system/inventory.h"

using namespace Pikachu;

class Player : public Entity {
public:
  Player(unsigned int level, unsigned int health, std::string name, Pikachu::Entity::Type type)
    : Pikachu::Entity(level, health, name, type) {
  }
};

int main() {
  Player player(1, 120, "Henk de Vries", Entity::PLAYER);
  std::cout << player.getName() << std::endl;
  return 0;
}
