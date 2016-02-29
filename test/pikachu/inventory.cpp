#include <memory>

#include <gtest/gtest.h>
#include "../src/entities/player.h"
#include "../src/items/cheese.h"

class InventoryTest : public ::testing::Test {
protected:
  Player* player;
  std::shared_ptr<Pikachu::Item> item_one;
  std::shared_ptr<Pikachu::Item> item_two;

  virtual void SetUp() {
    player = new Player(1, 120, "John Doe", Pikachu::Entity::PLAYER);
    item_one = std::make_shared<Pikachu::Item>("Item one", Pikachu::Item::TRASH, "An item");
    item_two = std::make_shared<Pikachu::Item>("Item two", Pikachu::Item::TRASH, "An item");
  }

  virtual void TearDown() {
    delete player;
  }
};

TEST_F(InventoryTest, addItem) {
  player->inventory().addItem(item_one);
  ASSERT_EQ(player->inventory().getSlot(0).getQuantity(), 1);
}

TEST_F(InventoryTest, duplicate) {
  player->inventory().addItem(item_one);
  player->inventory().addItem(item_two);
  ASSERT_EQ(player->inventory().getSlot(0).getQuantity(), 1);
  ASSERT_EQ(player->inventory().getSlot(1).getQuantity(), 1);
}

TEST_F(InventoryTest, full) {
  for(unsigned int i = 0; i < 17; i++) {
    player->inventory().addItem(item_one);
    if(i == 17) {
      // Should throw exception
      ASSERT_EQ(player->inventory().getSlot(i).getQuantity(), 0);
    }
  }

  // All slots should have 1 item
  for(unsigned int i = 0; i < 16; i++) {
    ASSERT_EQ(player->inventory().getSlot(i).getQuantity(), 1);
  }
}
