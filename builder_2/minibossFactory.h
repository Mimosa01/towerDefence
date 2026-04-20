#pragma once

#include "shipFactory.h"
#include "builder.h"

class MinibossFactory : public ShipFactory {
  public:
   Builder* createBulletBuilder() override {
     MinibossBuilder* builder = new MinibossBuilder();
     builder->setSpeed(10.0f).setDamage(50.0f).setEffect("gap");
     return builder;
   }
 };