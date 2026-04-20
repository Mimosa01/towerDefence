#include "bullet.h"
#include "shipFactory.h"
#include "builder.h"

#include "finalbossFactory.h"

#include <iostream>

using namespace std;

Bullet fire(ShipFactory* factory) {
  Builder* builder = factory->createBulletBuilder();
  return builder->build();
}

int main() {
  ShipFactory* pF = new FinalbossFactory();

  Bullet bullet = fire(pF);

  cout << "Speed:         " << bullet.speed << endl;
  cout << "Damage:        " << bullet.damage << endl;
  cout << "Effect:        " << bullet.effect << endl;
  cout << "Visual Effect: " << bullet.visualEffect << endl;
}
