#include <iostream>
#include <memory>


class Switch;

class State {
public:
  virtual ~State() = default;
  virtual void toggle(Switch& sw) = 0;
};

class Switch {
private:
  std::unique_ptr<State> state;

public:
  int color = 1;
  Switch(std::unique_ptr<State> initialState) {
    state = std::move(initialState);
  }

  void setState(std::unique_ptr<State> newState) {
    state = std::move(newState);
  }

  void pressButton() {
    state->toggle(*this);
  }
};

class OnState : public State {
public:
  void toggle(Switch& sw) override;
};

class OffState : public State {
public:
  void toggle(Switch& sw) override;
};

class ColorEdit : public State {
public:
  void toggle(Switch& sw) override;
}

void OnState::toggle(Switch& sw) {
  std::cout << "[ВКЛ] свет включили" << std::endl;
  sw.setState(std::unique_ptr<State>(new OffState()));
}

void OffState::toggle(Switch& sw) {
  std::cout << "[ВЫКЛ] свет выключили" << std::endl;
  sw.setState(std::unique_ptr<State>(new OnState()));
}

int main() {
  Switch light("Выключено");

  light.pressButton();
  light.pressButton();
}