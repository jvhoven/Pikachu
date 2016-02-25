#include "inventory.h"

Pikachu::Inventory::Inventory() {
  _slots = std::vector<std::unique_ptr<Pikachu::InventorySlot>>(MAX_SLOTS);
}

void Pikachu::Inventory::addItem(Pikachu::Item item) {
  std::unique_ptr<Pikachu::InventorySlot> slot = getInventorySlot(&item);
  if(slot != nullptr) {
    slot->addItem(item);
  } else {
    // TODO: Return error that inventory is full.
  }
}

const Pikachu::Item* Pikachu::Inventory::getItem(unsigned int index) {
  return _slots.at(index).get()->getItem();
}

std::unique_ptr<Pikachu::InventorySlot> Pikachu::Inventory::getInventorySlot(Pikachu::Item* item) {
  if(item->isStackable()) {
    // Attempt to find if we already have the item
    std::unique_ptr<Pikachu::InventorySlot> const& slot = find(item);
    if(slot->getItem() != item) {
      //return *slot;
    }
  } else if(isFull()) {
    return nullptr;
  } else {
    return getFreeSlot();
  }
  return 0;
}

std::unique_ptr<Pikachu::InventorySlot> const& Pikachu::Inventory::find(Pikachu::Item* item) {
  for(auto& slot : _slots) {
    if(!slot->isEmpty() && slot->getItem() == item) {
      //return slot;
    }
  }
  return 0;
}

bool Pikachu::Inventory::isFull() const {
  for(auto const& slot : _slots) {
    if(!slot.get()->isEmpty()) {
      return false;
    }
  }
  return true;
}

std::unique_ptr<Pikachu::InventorySlot> Pikachu::Inventory::getFreeSlot() {
  for(auto const& slot : _slots) {
    if(slot->isEmpty()) {
      //return slot;
    }
  }
  return 0;
}
