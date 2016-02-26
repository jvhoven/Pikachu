#include <iostream>
#include <memory>

#include "src/entities/player.h"
#include "src/items/cheese.h"

int main() {
  auto cheese = std::make_shared<Pikachu::Item>("Kaasje", Pikachu::Item::FOOD, "Ik wil kaas");
  cheese->setStackable(true);

  Player player(1, 120, "Henk de Vries", Pikachu::Entity::PLAYER);
  player.inventory().addItem(cheese);
  player.inventory().addItem(cheese);

  std::cout << player.inventory().getSlot(0).getQuantity() << std::endl;
  return 0;
}
