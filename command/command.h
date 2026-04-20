#pragma once 
#include "unit.h"


class GameCommand {
  public:
    virtual ~GameCommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class MoveCommand : public GameCommand {
  private:
    Unit& unit;

  public:
    explicit MoveCommand(Unit& u) : unit(u) {};
    
    void execute() override {
      unit.unitMove();
    }

    void undo() override {
      std::cout << "Отменили перемещение" << std::endl;
    }
};

class AttackCommand : public GameCommand {
  private:
    Unit& unit;

  public:
    explicit AttackCommand(Unit& u) : unit(u) {};
    
    void execute() override {
      unit.attack();
    }

    void undo() override {
      std::cout << "Отменили атаку" << std::endl;
    }
};