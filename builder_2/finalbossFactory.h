#pragma once

#include "shipFactory.h"
#include "builder.h"

class FinalbossFactory : public ShipFactory {
  public:
   Builder* createBulletBuilder() override {
     FinalbossBuilder* builder = new FinalbossBuilder();
     builder->setSpeed(20.0f).setDamage(150.0f).setEffect("venom");
     return builder;
   }
 };