#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Warrior::attack() {
    cout << "또 보자고, 존 마스턴.\n" << endl;
}