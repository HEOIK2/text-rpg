#include "magician.h"
#include <iostream>
#include "monster.h"


Magician::Magician(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Magician::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) {
        damage = 1;
    }
    monster->setHP(monster->getHP() - damage);
    cout << " 빵야!\n" << monster->getName() << "에게" << damage << " Damage!" << endl;
}

void Magician::introduce() {
    cout << "이 사건은 내가 맞죠.\n";
}