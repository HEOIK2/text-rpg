#include "thief.h"
#include <iostream>
#include "monster.h"



Thief::Thief(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Thief::attack(Monster* monster) {
    int damage = power / 5 - monster->getDefence();
    if (damage <= 0) {
        damage = 1;
    }
    cout << "Yee-Haw!\n";
    for (int i = 0; i < 5; i++) {

        monster->setHP(monster->getHP() - damage);
        cout << monster->getName() << "에게" << damage << " Damage!(x5)" << endl;
    }

}

void Thief::introduce() {
    cout << "There's a snake in my boot!\n";
}