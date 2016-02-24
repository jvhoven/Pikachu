#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <vector>
#include <iostream>
#include "pikachu/item.hpp"

class Inventory {
public:
  const unsigned int MAX = 16;
  Inventory();
  void addItem(Pikachu::Item item);
  void show();
  const Pikachu::Item& getItem(unsigned int index);
private:
  std::vector<Pikachu::Item> _items;
};

#endif
