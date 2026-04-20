#include "biome.h"

int main () {
  AbstractFactory* factory = resolveFactory(FOREST);
  Biome room = getRoom(factory);

  room.enemy->attack();
  room.loot->collect();
  room.terrain->render();

  factory = resolveFactory(DESERT);
  Biome room_1 = getRoom(factory);

  room_1.enemy->attack();
  room_1.loot->collect();
  room_1.terrain->render();
}