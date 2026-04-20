#include <memory>
#include "command.h"

class Remote {
  private:
    std::unique_ptr<GameCommand> currentCmd;
    std::unique_ptr<GameCommand> lastCmd = nullptr;

  public:
    void setCommand(std::unique_ptr<GameCommand> newCmd) {
      currentCmd = std::move(newCmd);
    }

    void executeCmd() {
      currentCmd->execute();
      lastCmd = std::move(currentCmd);
      currentCmd = nullptr;
    }

    void undoCmd() {
      if (lastCmd) {
        lastCmd->undo();
        
      }
    }
};

int main() {
  Unit unit;
  Remote remote;

  remote.setCommand(std::unique_ptr<GameCommand>(new MoveCommand(unit)));
  remote.undoCmd();
  remote.executeCmd();
  remote.undoCmd();


  remote.setCommand(std::unique_ptr<GameCommand>(new AttackCommand(unit)));
  remote.executeCmd();
  remote.undoCmd();
}
