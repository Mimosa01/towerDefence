#pragma once

#include <iostream>

class NetworkTransport {
  public:
    virtual void send() = 0;
    virtual void receive(int data) = 0;
};

class LegacyUDP {
  public:
    void push_packet() {
      std::cout << "Push LegacyUDP" << std::endl;
    }

    void pull_packet(int data) {
      std::cout << "Pull LegacyUDP " << data << " bytes" << std::endl;
    }
};

class WebsocketLib {
  public:
    void emit() {
      std::cout << "Websocket send data" << std::endl;
    }

    void on_message(int data) {
      std::cout << "Pull Websocket " << data << " bytes" << std::endl;
    }
};