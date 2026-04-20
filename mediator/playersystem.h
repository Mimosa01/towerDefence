#pragma once

#include <iostream>
#include "mediator.h"

class PlayerSystem {
  void on_item_picked() {
    std::cout << "[Player] Item Picked Counted." << std::endl;
  }

  void on_player_died() {
    std::cout << "[Player] Player Died." << std::endl;
  }

  public:
    PlayerSystem(EventBus& bus) {
      bus.subscribe("item_picked", [this]() { on_item_picked(); });
      bus.subscribe("player_died", [this]() { on_player_died(); });
    }
};