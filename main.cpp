#include <iostream>
#include <memory>

#include "src/entities/player.h"
#include "src/items/cheese.h"

int main() {
  Player player2(1, 120, "Dennis van Hoven", Pikachu::Entity::PLAYER);
  auto whey = std::make_shared<Pikachu::Item>("Whey Poeder", Pikachu::Item::FOOD, "Gratis whey poeder");
  whey->setStackable(false);

  for(unsigned int i = 0; i < 4000; i++) {
    player2.inventory().addItem(whey);
  }

  std::cout << player2.inventory().getSlot(0).getQuantity() << "x " << player2.inventory().getItem(0)->getName() << std::endl;
  return 0;
}
