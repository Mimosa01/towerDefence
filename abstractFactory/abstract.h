#pragma once

class Enemy {
public:
  virtual void attack() = 0;
  virtual void takeDamage() = 0;
};

class Loot {
public:
  virtual void collect() = 0;
};

class Terrain {
public:
  virtual void render() = 0;
};

class AbstractFactory {
public:
  virtual Enemy* createEnemy() = 0;
  virtual Loot* createLoot() = 0;
  virtual Terrain* createTerrain() = 0;
};