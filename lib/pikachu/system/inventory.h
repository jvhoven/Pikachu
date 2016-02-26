#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include "pikachu/system/inventoryslot.h"

typedef std::shared_ptr<Pikachu::Item>& shared_item;

namespace Pikachu {
  class Inventory {
  public:
    Inventory();
    void addItem(shared_item item);
    const Pikachu::Item *const getItem(unsigned int index);
    Pikachu::InventorySlot getSlot(unsigned int index) const;
    Pikachu::InventorySlot& getInventorySlot(shared_item item, bool stack);
    bool isFull() const;
  private:
    const unsigned int MAX_SLOTS = 16;
    std::vector<Pikachu::InventorySlot> _slots;

    Pikachu::InventorySlot& find(shared_item item);
    Pikachu::InventorySlot& getFreeSlot();
  };
}

#endif
