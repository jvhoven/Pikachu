#include "pikachu/base/entity.hpp"
#include "pikachu/system/inventory.h"

class Player : public Pikachu::Entity {
public:
  Player(unsigned int level, unsigned int health, std::string name, Pikachu::Entity::Type type);
  Pikachu::Inventory& inventory();
private:
  Pikachu::Inventory _inv;
};
