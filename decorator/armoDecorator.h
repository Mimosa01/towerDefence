#pragma once

#include <iostream>
#include "IDecorator.h"

class ArmoDecorator : public IDecorator {
  private:
    int point;

  public:
    ArmoDecorator(DamageHandler* c, int p) : IDecorator(c), point(p) {};

    float handle(float damage) override {
      std::cout << "Применилась броня" << std::endl;
      return wrapped->handle(damage) - point;
    }
};