#pragma once

#include <string>
#include "unit.h"

class Builder {
private:
  Unit unit = Unit();

public:
  void reset() {
    unit = Unit();
  }

  Builder& setClassUnit(std::string value) {
    unit.classUnit = value;
    return *this;
  }

  Builder& setPerk(std::string value) {
    unit.perk = value;
    return *this;
  }

  Builder& setEquip(std::string value) {
    unit.equip = value;
    return *this;
  }

  Unit build() {
    Unit temp  = unit;
    reset();
    return temp;
  }
};