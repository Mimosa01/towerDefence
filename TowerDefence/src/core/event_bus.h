#pragma once 

#include <unordered_map>
#include <functional>
#include <vector>
#include <typeindex>
#include <any>

using namespace std;

class EventBus {
  template <typename EventT>
  using Handler = function<void(const EventT&)>;

  public:

    template <typename EventT>
    void subscribe(Handler<EventT> handler) {
      auto type_idx = type_index(typeid(EventT));

      handlers_[type_idx].push_back(
        [handler = std::move(handler)](const any& data) {
          handler(any_cast<const EventT&>(data));
        }
      );
    }

    template <typename EventT>
    void publish(const EventT& event) {
      auto type_idx = type_index(typeid(EventT));
      auto temp = handlers_.find(type_idx);

      if (temp != handlers_.end()) {
        for (const auto& handler: temp->second) {
          handler(event);
        }
      }
    }

  private:
    unordered_map<type_index, vector<function<void(const any&)>>> handlers_;
};