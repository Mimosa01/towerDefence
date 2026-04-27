#pragma once

#include <memory>
#include <string>
#include <utility>

#include "ITower.h"

class ITowerDecorator : public ITower {
  protected:
    std::shared_ptr<ITower> wrapped_;

  public:
    explicit ITowerDecorator(std::shared_ptr<ITower> tower) : wrapped_(std::move(tower)) {}
    
    int get_damage() const override {
      return wrapped_->get_damage();
    };
    int get_range() const override {
      return wrapped_->get_range();
    };
    int get_cost() const override {
      return wrapped_->get_cost();
    };

    std::string describe() const override {
      return wrapped_->describe();
    };
    void attack(Coord target) override {
      wrapped_->attack(target);
    };
};