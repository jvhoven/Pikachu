#include <iostream>

#include "src/entities/player.h"
#include "src/items/cheese.h"

int main() {
  Cheese cheese("Kaasje", Pikachu::Item::FOOD, "Ik wil kaas");
  Player player(1, 120, "Henk de Vries", Pikachu::Entity::PLAYER);
  player.inventory().addItem(cheese);

  std::cout << player.inventory().getItem(0).getName() << std::endl;

  return 0;
}
