#include "thief.h"
#include <iostream>


Thief::Thief(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Thief::attack() {
    cout << "Yee-haw!\n" << endl;
}
