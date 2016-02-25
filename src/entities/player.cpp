#include "player.h"

Player::Player(unsigned int level, unsigned int health, std::string name, Pikachu::Entity::Type type)
  : Pikachu::Entity(level, health, name, type) {
}

Pikachu::Inventory& Player::inventory() {
  return _inv;
}
