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
      FOOD
    };

    Item(std::string name, Type type, std::string description)
      : _name(name), _type(type), _description(description) {

    }

    std::string getName() const {
      return _name;
    }
  private:
    std::string _name;
    Type _type;
    std::string _description;
  };
}

#endif
