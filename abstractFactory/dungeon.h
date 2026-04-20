#pragma once

#include <iostream>
#include "abstract.h"

class DungeonEnemy : public Enemy {
  void attack() override {
    std::cout << "Dungeon Enemy attack" << std::endl;
  }

  void takeDamage() override {
    std::cout << "Dungeon Enemy take damage" << std::endl;
  }
};

class DungeonLoot : public Loot {
  void collect() override {
    std::cout << "Dungeon Loot collect" << std::endl;
  }
};

class DungeonTerrain : public Terrain {
  void render() override {
    std::cout << "Dungeon Terrain render" << std::endl;
  }
};

class DungeonFactory : public AbstractFactory {
  Enemy* createEnemy() override {
    return new DungeonEnemy();
  }

  Loot* createLoot() override {
    return new DungeonLoot();
  }

  Terrain* createTerrain() override {
    return new DungeonTerrain();
  };
};