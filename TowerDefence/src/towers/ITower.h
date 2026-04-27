#pragma once

#include <memory>
#include <string>
#include "../core/coord.h"

class ITower {
  public:
    virtual ~ITower() = default;

    virtual in get_damage() const = 0;
    virtual int get_range() const = 0;
    virtual int get_cost() const = 0;

    virtual std::string describe() const = 0;
    virtual void attack(Coord target) = 0;
  }