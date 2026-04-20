#pragma once

#include <iostream>
#include "mediator.h"

class AchievementSystem {
  void on_enemy_killed() {
    std::cout << "[Achievement] Kill Counted." << std::endl;
  }

  void on_level_up() {
    std::cout << "[Achievement] Level Up." << std::endl;
  }

  void on_item_picked() {
    std::cout << "[Achievement] Item Picked Counted." << std::endl;
  }

  public:
    AchievementSystem(EventBus& bus) {
      bus.subscribe("item_picked", [this]() { on_item_picked(); });
      bus.subscribe("enemy_killed", [this]() { on_enemy_killed(); });
      bus.subscribe("level_up", [this]() { on_level_up(); });
    }
};
