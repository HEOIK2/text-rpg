#include "archer.h"
#include <iostream>

 Archer::Archer(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

 void Archer::attack() {
    cout << "석양이 진다...\n" << endl;
}
