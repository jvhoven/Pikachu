#ifndef _PIKACHU_ENTITY_H
#define _PIKACHU_ENTITY_H

#include <string>

namespace Pikachu {
  class Entity {
  public:
    enum Type {
      NPC,
      PLAYER,
      UNKNOWN
    };

    Entity(unsigned int level, unsigned int health, std::string name, Type type)
      : _level(level), _health(health), _name(name), _type(type) {
      _currentHealth = health;
    };

    virtual ~Entity() {
      
    }

    unsigned int getLevel() const {
      return _level;
    }

    unsigned int getHealth() const {
      return _health;
    }

    std::string getName() const {
      return _name;
    }

    Type getType() const {
      return _type;
    }
  private:
    unsigned int _level;
    unsigned int _health;
    unsigned int _currentHealth;
    std::string _name;
    Type _type;
  };
}

#endif
