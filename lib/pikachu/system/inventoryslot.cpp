#include "inventoryslot.h"

bool Pikachu::InventorySlot::isEmpty() {
  if(_item) {
    return false;
  }
  return true;
}

void Pikachu::InventorySlot::addItem(shared_item item) {
  if(!isEmpty()) {
    if(_item->isStackable()) {
      _quantity++;
    }
  } else {
    _item = item.get();
    _quantity = 1;
  }
}

int Pikachu::InventorySlot::getQuantity() const {
  return _quantity;
}

Pikachu::Item* Pikachu::InventorySlot::getItem() {
  return _item;
}

void Pikachu::InventorySlot::removeItem() {
  if(!isEmpty()) {
    if(_quantity > 1) {
      _quantity--;
    } else if(_quantity == 1) {
      _item = nullptr;
    }
  } else {
    // TODO: Throw error
  }
}
