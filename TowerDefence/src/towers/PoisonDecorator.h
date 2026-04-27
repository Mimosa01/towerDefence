#pragma once
#include "ITowerDecorator.h"

class PoisonDecorator : public ITowerDecorator {
public:
    explicit PoisonDecorator(std::shared_ptr<ITower> tower) 
        : ITowerDecorator(std::move(tower)) {}

    int get_damage() const override { return wrapped_->get_damage() + 5; }
    std::string describe() const override { return wrapped_->describe() + " + Poison"; }
};

