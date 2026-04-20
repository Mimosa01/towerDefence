#pragma once

#include "shipFactory.h"
#include "builder.h"

class PlayerFactory : public ShipFactory {
 public:
  Builder* createBulletBuilder() override {
    PlayerBuilder* builder = new PlayerBuilder();
    builder->setSpeed(8.0f).setDamage(10.0f).setEffect("through");
    return builder;
  }
};