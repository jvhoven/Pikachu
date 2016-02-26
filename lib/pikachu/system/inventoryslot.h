#ifndef _PIKACHU_INVENTORYSLOT_H
#define _PIKACHU_INVENTORYSLOT_H

#include <memory>
#include <iostream>
#include "pikachu/base/item.hpp"

typedef std::shared_ptr<Pikachu::Item>& shared_item;

namespace Pikachu {
  class InventorySlot {
  public:
    void addItem(shared_item item);
    void removeItem();
    Pikachu::Item* getItem(); // If we do not store it as a pointer we lose our polymorphism
    bool isEmpty();
    int getQuantity() const;
  private:
    Pikachu::Item* _item;
    int _quantity;
  };
}

#endif
