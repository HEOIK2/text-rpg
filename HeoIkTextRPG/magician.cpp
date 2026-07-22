#include "magician.h"
#include <iostream>
using namespace std;


Magician::Magician(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}

void Magician::attack() {
    cout << "이 사건은 내가 맡죠.\n" << endl;
}
