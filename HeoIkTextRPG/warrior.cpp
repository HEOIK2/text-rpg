#include "warrior.h"
#include <iostream>
#include "monster.h"

using namespace std;

Warrior::Warrior(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Warrior::attack(Monster* monster) {
    int damage = power - monster->getDefence();
        if (damage <= 0) {
            damage = 1;
        }
    monster->setHP(monster->getHP() - damage);
    cout << "Bang! Bang! Bang!\n" << monster->getName() << "에게" << damage << " Damage!" << endl;
}

void Warrior::introduce() {
    cout << "See you around. John Maston.\n";
}