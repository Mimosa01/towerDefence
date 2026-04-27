#pragma once

#include <string>
#include "coord.h"

struct TowerPlacedEvent {
  Coord position;
  std::string type;
  int cost;
};

struct TowerSoldEvent {
  Coord c;
  int refund;
};

struct EnemyKilledEvent {
  int reward;
  bool is_boss;
};

struct BossApearedEvent {};

struct WaveCompletedEvent { int wave_num; };