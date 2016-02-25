#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <vector>
#include <algorithm>
#include <memory>
#include "pikachu/system/inventoryslot.h"

namespace Pikachu {
  class Inventory {
  public:
    Inventory();
    void addItem(Pikachu::Item item);
    void show();
    const Pikachu::Item* getItem(unsigned int index);
    std::unique_ptr<Pikachu::InventorySlot> getInventorySlot(Pikachu::Item* item);
    bool isFull() const;
  private:
    const unsigned int MAX_SLOTS = 16;
    std::vector<std::unique_ptr<Pikachu::InventorySlot>> _slots;

    std::unique_ptr<Pikachu::InventorySlot> const& find(Pikachu::Item* item);
    std::unique_ptr<Pikachu::InventorySlot> getFreeSlot();
  };
}

#endif
