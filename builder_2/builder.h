#pragma once

#include <string>

#include "bullet.h"

class Builder {
 protected:
    Bullet bullet = Bullet();

 public:
    void reset() {
      bullet = Bullet();
    }

    Builder& setSpeed(float value) {
      bullet.speed = value;
      return *this;
    }

    Builder& setDamage(float value) {
      bullet.damage = value;
      return *this;
    }

    Builder& setEffect(std::string value) {
      bullet.effect = value;
      return *this;
    }

    Builder& setVisualEffect(std::string value) {
      bullet.visualEffect = value;
      return *this;
    }

    virtual Bullet build() = 0;
};

class PlayerBuilder : public Builder {
  Bullet build() override {
    bullet.visualEffect = "BLUE";
    return bullet;
  }
};

class MinibossBuilder : public Builder {
  Bullet build() override {
    bullet.visualEffect = "RED";
    return bullet;
  }
};

class FinalbossBuilder: public Builder {
  Bullet build() override {
    bullet.visualEffect = "BLOOD";
    return bullet;
  }
};