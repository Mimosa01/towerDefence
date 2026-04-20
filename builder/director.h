#pragma once

#include "builder.h"
#include "unit.h"
#include <string>

class Director {
private:
  Builder* builder = new Builder();

public:
  Unit buildWarrior() {
    return builder->setClassUnit("Warrior").setPerk("Blood").setEquip("Sword").build();
  }

  Unit buildPreMag(std::string perk) {
    return builder->setClassUnit("Mag").setPerk(perk).setEquip("Stick").build();
  }
};