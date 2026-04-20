#pragma once 

#include <unordered_map>
#include <functional>
#include <vector>
#include <string>

using namespace std;

class EventBus {
  using Handler = function<void()>;

  private:
    std::unordered_map<string, vector<Handler>> listeners_;

  public:
    void subscribe(const string& event, Handler handler) {
      listeners_[event].push_back(move(handler));
    }

    void publish(const string& event) {
      auto temp = listeners_.find(event);

      if (temp != listeners_.end()) {
        for (const auto& handler: temp->second) {
          handler();
        }
      }
    }
}