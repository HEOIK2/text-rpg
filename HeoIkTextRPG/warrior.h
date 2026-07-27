#pragma once
#include "player.h"

class Warrior : public Player {
public:
    Warrior(string name, int hp, int mp, int power, int defence);
    void attack(Monster* monster) override;
    void introduce() override;
};