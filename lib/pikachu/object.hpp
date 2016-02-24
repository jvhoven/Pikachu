#ifndef _OBJECT_H
#define _OBJECT_H

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
