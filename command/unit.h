#pragma once 

#include <iostream>

class Unit {
  public:
    void unitMove() {
      std::cout << "Unit переместился" << std::endl;
    }

    void attack() {
      std::cout << "Unit атаковал" << std::endl;
    }
};