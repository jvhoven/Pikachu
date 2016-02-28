#include "inventory.h"

/*
* Prepopulate our vector because we always want 16 InventorySlot objects ready.
 */
Pikachu::Inventory::Inventory() {
  _slots = std::vector<Pikachu::InventorySlot>(MAX_SLOTS);
  std::generate(_slots.begin(), _slots.end(), [&]{ return Pikachu::InventorySlot(); });
}

/*
* Attempt to add the item to the inventory; throws error if inventory is full.
 */
void Pikachu::Inventory::addItem(shared_item item) {
  if(isFull()) {
    std::cerr << "Inventory is full!" << std::endl;
  } else {
    Pikachu::InventorySlot& slot = getInventorySlot(item, item->isStackable());
    slot.addItem(item);
  }
}

/*
* Returns read only variable of the item or a nullptr if the given slot is empty.
 */
const Pikachu::Item *const Pikachu::Inventory::getItem(unsigned int index) {
  if(_slots.at(index).isEmpty()) {
    return nullptr;
  }
  return _slots.at(index).getItem();
}

/*
* Returns the inventory slot at position.
 */
Pikachu::InventorySlot Pikachu::Inventory::getSlot(unsigned int index) const {
  return _slots.at(index);
}

/*
* Checks if the inventory already has the item, it then calls find to return the slot that has the item.
 */
Pikachu::InventorySlot& Pikachu::Inventory::getInventorySlot(shared_item item, bool stack) {
  if(stack) {
    Pikachu::InventorySlot& slot = find(item);
    return slot;
  }
  return getFreeSlot();
}

/*
* Attempt to find the item in the inventory
* If it cannot find the item, it returns the first empty inventory slot it encounters
 */
Pikachu::InventorySlot& Pikachu::Inventory::find(shared_item item) {
  for(auto& slot : _slots) {
    if(!slot.isEmpty() && slot.getItem()->getName() == item->getName()) {
      return slot;
    }
  }
  return getFreeSlot();
}

/*
* Searches for an empty slot in the inventory
* Returns the first one it encounters
 */
Pikachu::InventorySlot& Pikachu::Inventory::getFreeSlot() {
  for(auto& slot : _slots) {
    if(slot.isEmpty()) {
      return slot;
    }
  }
}

/*
* Check if there is any free slot in the inventory
 */
bool Pikachu::Inventory::isFull() const {
  for(auto slot : _slots) {
    if(slot.isEmpty()) {
      return false;
    }
  }
  return true;
}
