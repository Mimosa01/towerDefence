#pragma once

#include <iostream>
#include "mediator.h"

class QuestSystem {
  void on_item_picked() {
    std::cout << "[Quest] Item Picked Counted." << std::endl;
  }

  void on_player_died() {
    std::cout << "[Quest] Player Died." << std::endl;
  }

  public:
    QuestSystem(EventBus& bus) {
      bus.subscribe("item_picked", [this]() { on_item_picked(); });
      bus.subscribe("player_died", [this]() { on_player_died(); });
    }
};
