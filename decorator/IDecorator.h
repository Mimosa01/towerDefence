#pragma once

#include "damage.h"

class IDecorator : public DamageHandler {
  protected:
    DamageHandler* wrapped;

  public:
    IDecorator(DamageHandler* c) : wrapped(c) {};

    float handle(float damage) override {
      return wrapped->handle(damage);
    }
};
