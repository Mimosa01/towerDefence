#pragma once

#include <iostream>
#include "abstract.h"

class ForestEnemy : public Enemy {
  void attack() override {
    std::cout << "Forest Enemy attack" << std::endl;
  }

  void takeDamage() override {
    std::cout << "Forest Enemy take damage" << std::endl;
  }
};

class ForestLoot : public Loot {
  void collect() override {
    std::cout << "Forest Loot collect" << std::endl;
  }
};

class ForestTerrain : public Terrain {
  void render() override {
    std::cout << "Forest Terrain render" << std::endl;
  }
};

class ForestFactory : public AbstractFactory {
  Enemy* createEnemy() override {
    return new ForestEnemy();
  }

  Loot* createLoot() override {
    return new ForestLoot();
  }

  Terrain* createTerrain() override {
    return new ForestTerrain();
  };
};