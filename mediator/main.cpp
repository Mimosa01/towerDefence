#include <iostream>
#include "mediator.h"
#include "audioSystem.h"
#include "achievementSystem.h"
#include "questSystem.h"
#include "uiSystem.h"
#include "playerSystem.h"

int main() {
  EventBus bus;

  AudioSystem audioSystem(bus);
  AchievementSystem achievementSystem(bus);
  QuestSystem questSystem(bus);
  UISystem uiSystem(bus);
  PlayerSystem playerSystem(bus)

  std::cout << "🎮 Игровая сессия\n" << std::string(40, '=') << "\n";

  std::cout << "Мы убили противника" << std::endl;
  bus.publish("enemy_killed");

  std::cout << "\n\nМы подняли уровень" << std::endl;
  bus.publish("level_up");

  std::cout << "\n\nМы подняли предмет" << std::endl;
  bus.publish("item_picked"); 

}