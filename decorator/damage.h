#pragma once

class DamageHandler {
  public:
    virtual float handle(float damage) = 0;
};

class Damage : public DamageHandler {
  public:
    float handle(float damage) override {
      return damage;
    }
};