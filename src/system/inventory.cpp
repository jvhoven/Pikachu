#include "inventory.h"

Inventory::Inventory() {
  _items.reserve(MAX);
}

void Inventory::addItem(Pikachu::Item item) {
  // If we havent reached the limit yet
  if(_items.size() < MAX) {
    _items.push_back(item);
  } else {
    // TODO: Throw inventory is full error
  }
}

const Pikachu::Item& Inventory::getItem(unsigned int index) {
  Pikachu::Item item = _items.at(index);
  // TODO: Check if an item exists at index
  return item;
}

void Inventory::show() {
  /*for(Pikachu::Item item : _items) {
    std::cout << item.getName() << std::endl;
  }*/
}
