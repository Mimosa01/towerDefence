#pragma once

#include "legacy.h"

class UDPAdapter : public NetworkTransport {
  private:
    LegacyUDP* adaptee = new LegacyUDP();

  public:  
    void send() override {
      adaptee->push_packet();
    }

    void receive(int data) override {
      adaptee->pull_packet(data);
    }
};