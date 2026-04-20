#pragma once 

#include "legacy.h"

class WebsocketAdapter : public NetworkTransport {
  private:
    WebsocketLib* adaptee = new WebsocketLib();

  public:
    void send() override {
      adaptee->emit();
    }

    void receive(int data) override {
      adaptee->on_message(data);
    }
};