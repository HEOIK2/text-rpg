#include "monster.h"
#include <iostream>

 Monster::Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice) : name(name), hp(hp), power(power), defence(defence), dropItemName(dropItemName), dropItemPrice(dropItemPrice) {}

 int Monster::getHP() {
    return hp;
}

 int Monster::getPower() {
    return power;
}

 int Monster::getDefence() {
    return defence;
}

 void Monster::setHP(int newHP) {
    hp = newHP;
}

 string Monster::getName() {
    return name;
}

 void Monster::attack(Player* player) {
    int damage = power - player->getDefence();
    if (damage <= 0) {
        damage = 1;
    }
    player->setHP(player->getHP() - damage);
    cout << name << "이 당신에게 " << damage << "의 데미지를 입혔습니다!\n" << endl;
}

 string Monster::getDropItemName() {
    return dropItemName;
}

 int Monster::getDropItemPrice() {
    return dropItemPrice;
}

int getInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "잘못된 입력입니다.\n";
        }
        else {
            return value;
        }
    }
}
