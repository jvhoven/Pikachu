#ifndef _PIKACHU_OBJECT_H
#define _PIKACHU_OBJECT_H

namespace Pikachu {
  class Object {
  public:
    virtual ~Object();
  protected:
    Object(unsigned int durability)
      : _durability(durability) {};
  protected:
    unsigned int _durability;
  };
}

#endif
