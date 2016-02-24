#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>

namespace Pikachu {
  class Entity {
  public:
    Entity(unsigned int level, unsigned int health, std::string name)
      : _level(level), _health(health), _name(name) {};

    unsigned int getLevel() const {
      return _level;
    }

    unsigned int getHealth() const {
      return _health;
    }

    std::string getName() const {
      return _name;
    }
  protected:
    unsigned int _level;
    unsigned int _health;
    std::string _name;
  };
}

#endif
