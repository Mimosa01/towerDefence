#include <iostream>

#include "legacy.h"
#include "UDPAdapter.h"
#include "WebsocketAdapter.h"

void gameLoop(NetworkTransport* transport) {
  transport->send();
  transport->receive(10);
};

int main() {
  UDPAdapter* adapter_1 = new UDPAdapter();
  WebsocketAdapter* adapter_2 = new WebsocketAdapter();

  gameLoop(adapter_1);
  std::cout << std::endl;
  gameLoop(adapter_2);
};