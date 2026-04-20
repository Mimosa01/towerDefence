#include <iostream>

#include "damage.h"
#include "shieldDecorator.h"
#include "armoDecorator.h"

int main() {
  Damage* damageObj = new Damage();

  ArmoDecorator* armo = new ArmoDecorator(damageObj, 5);
  ShieldDecorator* shield = new ShieldDecorator(armo, 0.5);

  float res_2 = shield->handle(100);
  std::cout << "С броней урон - " << res_2 << std::endl;
  
  std::cout << "Стандартный урон - " << damageObj->handle(10) << std::endl;

}