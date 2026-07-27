#include "archer.h"
#include <iostream>
#include "monster.h"

 Archer::Archer(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

 void Archer::attack(Monster* monster) {
     int damage = power/3 - monster->getDefence();
     if (damage <= 0) {
         damage = 1;
     }
     cout << "탕탕후루후루 탕탕후루루루루!\n";
     for (int i = 0; i < 3; i++) {

         monster->setHP(monster->getHP() - damage);
         cout << monster->getName() << "에게" << damage << " Damage!(x3)" << endl;
     }
     
 }

 void Archer::introduce() {
     cout << "석양이 진다....\n";
 }