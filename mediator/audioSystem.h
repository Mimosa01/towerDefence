#pragma once

#include <iostream>
#include "mediator.h"

class AudioSystem {
  void on_enemy_killed() {
   std::cout << "[Audio] Kill Counted." << std::endl;
  }

  void on_level_up() {
    std::cout << "[Audio] Level Up." << std::endl;
   }

  void on_item_picked() {
    std::cout << "[Audio] Item Picked." << std::endl;
  }

  void on_player_died() {
    std::cout << "[Audio] Player Died." << std::endl;
  }

  public:
    AudioSystem(EventBus& bus) {
      bus.subscribe("item_picked", [this]() { on_item_picked(); });
      bus.subscribe("enemy_killed", [this]() { on_enemy_killed(); });
      bus.subscribe("level_up", [this]() { on_level_up(); });
      bus.subscribe("player_died", [this]() { on_player_died(); });
    }
};