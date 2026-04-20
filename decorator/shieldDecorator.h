#pragma once

#include <iostream>
#include "IDecorator.h"

class ShieldDecorator : public IDecorator {
  private:
    float percent;

  public:
    ShieldDecorator(DamageHandler* c, float p_percent) : IDecorator(c), percent(p_percent) {};

    float handle(float damage) override {
      std::cout << "Применился щит" << std::endl;
      return wrapped->handle(damage) - wrapped->handle(damage) * percent;
    }
};