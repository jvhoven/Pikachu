#ifndef _PIKACHU_ITEM_H
#define _PIKACHU_ITEM_H

#include <string>

namespace Pikachu {
  class Item {
  public:
    enum Type {
      TRASH,
      WEAPON,
      MATERIAL,
      FOOD,
      QUEST
    };

    Item(std::string name, Type type, std::string description)
      : _name(name), _type(type), _description(description) {
    }

    virtual ~Item() {

    }

    std::string getName() const {
      return _name;
    }

    bool isStackable() const {
      return _stackable;
    }

    void setStackable(bool b) {
      _stackable = b;
    }
  private:
    std::string _name;
    Type _type;
    std::string _description;
    bool _stackable = false;
  };
}

#endif
