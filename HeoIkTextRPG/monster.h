#pragma once
#include "player.h"

class Monster {

protected:
    string name;
    int hp;
    int power;
    int defence;
    string dropItemName;
    int dropItemPrice;
public:
    Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice);;
    int getHP();
    int getPower();
    int getDefence();
    void setHP(int newHP);
    string getName();
    void attack(Player* player);
    string getDropItemName();
    int getDropItemPrice();

};

int getInt();
