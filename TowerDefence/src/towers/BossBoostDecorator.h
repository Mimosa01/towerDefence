#pragma once
#include "ITowerDecorator.h"

class BossBoostDecorator : public ITowerDecorator {
public:
    explicit BossBoostDecorator(std::shared_ptr<ITower> tower) 
        : ITowerDecorator(std::move(tower)) {}

    int get_damage() const override { return wrapped_->get_damage() * 2; }
    std::string describe() const override { return wrapped_->describe() + " [BOSS-DEBUFF]"; }
};

