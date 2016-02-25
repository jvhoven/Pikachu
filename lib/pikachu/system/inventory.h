#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <vector>
#include <iostream>
#include "pikachu/base/item.hpp"

namespace Pikachu {
  class Inventory {
  public:
    Inventory();
    void addItem(Pikachu::Item item);
    void show();
    const Pikachu::Item& getItem(unsigned int index);
  private:
    const unsigned int MAX = 16;
    std::vector<Pikachu::Item> _items;
  };
}

#endif
