#pragma once
#include "ITowerDecorator.h"

class RangeDecorator : public ITowerDecorator {
public:
    explicit RangeDecorator(std::shared_ptr<ITower> tower) 
        : ITowerDecorator(std::move(tower)) {}

    int get_range() const override { return wrapped_->get_range() + 2; }
    std::string describe() const override { return wrapped_->describe() + " + RangeBoost"; }
};

