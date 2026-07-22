#pragma once
#include <string>
using namespace std;

class Player {
protected: 
    string name;
    string job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;
public:
    Player(string name, int hp, int mp, int power, int defence);
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    string getName();
    void setHP(int newHP);
    void setMP(int newMP);
    void setPower(int newPower);
    void setDefence(int newDefence);
    void setJob(string newJob);
    void setLevel(int newLevel);
    virtual void attack() = 0;
    virtual ~Player() {}
};