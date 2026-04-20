#include <iostream>

#include "builder.h"
#include "unit.h"
#include "director.h"

int main() {
  Director* director = new Director();

  Unit unit_1 = director->buildWarrior();
  Unit unit_2 = director->buildPreMag("BooldHealth");

  std::cout << "Class: " << unit_1.classUnit << std::endl;
  std::cout << "Perk: " << unit_1.perk << std::endl;
  std::cout << "Equip: " << unit_1.equip << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Class: " << unit_2.classUnit << std::endl;
  std::cout << "Perk: " << unit_2.perk << std::endl;
  std::cout << "Equip: " << unit_2.equip << std::endl;

}