#pragma once

#include "builder.h"

class ShipFactory {
 public:
  virtual Builder* createBulletBuilder() = 0;
};