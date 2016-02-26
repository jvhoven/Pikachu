#include <iostream>
#include <memory>

#include "src/entities/player.h"
#include "src/items/cheese.h"

int main() {
  auto cheese = std::make_shared<Pikachu::Item>("Kaasje", Pikachu::Item::FOOD, "Ik wil kaas");
  Player player(1, 120, "Henk de Vries", Pikachu::Entity::PLAYER);
  player.inventory().addItem(cheese);

  std::cout << player.inventory().getItem(0)->getName() << std::endl;

  return 0;
}
