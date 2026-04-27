#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "ITower.h"

class BaseTower : public ITower {
  private:
    int damage_;
    int range_;
    int cost_;
    std::string name_;

  public:
    BaseTower(std::string n, int d, int r, int c) : damage_(d), range_(r), cost_(c), name_(n) {}
    
    int get_damage() const override {
      return damage_;
    }

    int get_range() const override {
      return range_;
    }

    int get_cost() const override {
      return cost_;
    }

    std::string describe() const override {
      return name_;
    }

    void attack(Coord target) override {
      std::cout << "[" << name_ << "] Attacks target at (" << target.x << "," << target.y << ")\n" << std::endl;
    }
};