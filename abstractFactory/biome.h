#pragma once

#include "abstract.h"
#include "desert.h"
#include "forest.h"
#include "dungeon.h"

enum BiomeType {
  DESERT,
  FOREST,
  DUNGEON
};

struct Biome {
  Enemy* enemy;
  Loot* loot;
  Terrain* terrain;
};

inline AbstractFactory* resolveFactory(BiomeType factoryName) {
  if (factoryName == 0) {
    return new DesertFactory();
  } 
  else if (factoryName == 1) {
    return new ForestFactory();
  }
  else if (factoryName == 2) {
    return new DungeonFactory();
  }
  else {
    return new ForestFactory();
  }
};

inline Biome getRoom(AbstractFactory* factory) {
  Biome room;

  room.enemy = factory->createEnemy();
  room.loot = factory->createLoot();
  room.terrain = factory->createTerrain();

  return room;
};