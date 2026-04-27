#pragma once 

#include <unordered_map>
#include <functional>
#include <vector>
#include <string>

class EventBus {
  using Handler = std::function<void()>;

  private:
    std::unordered_map<std::string, std::vector<Handler>> listeners_;

  public:
    void subscribe(const std::string& event, Handler handler) {
      listeners_[event].push_back(std::move(handler));
    }

    void publish(const std::string& event) {
      auto temp = listeners_.find(event);

      if (temp != listeners_.end()) {
        for (const auto& handler: temp->second) {
          handler();
        }
      }
    }
};
