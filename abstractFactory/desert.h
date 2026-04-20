#pragma once

#include <iostream>
#include "abstract.h"

class DesertEnemy : public Enemy {
  void attack() override {
    std::cout << "Desert Enemy attack" << std::endl;
  }

  void takeDamage() override {
    std::cout << "Desert Enemy take damage" << std::endl;
  }
};

class DesertLoot : public Loot {
  void collect() override {
    std::cout << "Desert Loot collect" << std::endl;
  }
};

class DesertTerrain : public Terrain {
  void render() override {
    std::cout << "Desert Terrain render" << std::endl;
  }
};

class DesertFactory : public AbstractFactory {
  Enemy* createEnemy() override {
    return new DesertEnemy();
  }

  Loot* createLoot() override {
    return new DesertLoot();
  }

  Terrain* createTerrain() override {
    return new DesertTerrain();
  };
};