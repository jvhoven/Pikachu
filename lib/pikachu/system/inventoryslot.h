#ifndef _PIKACHU_INVENTORYSLOT_H
#define _PIKACHU_INVENTORYSLOT_H

#include "pikachu/base/item.hpp"

namespace Pikachu {
  class InventorySlot {
  public:
    bool isEmpty();
    void addItem(Pikachu::Item item);
    void removeItem();
    Pikachu::Item* getItem();
  private:
    Pikachu::Item* _item;
    int _quantity;
  };
}

#endif
