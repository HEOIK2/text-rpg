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
    int exp;
    int maxExp;
public:
    Player(string name, int hp, int mp, int power, int defence);
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getExp();
    int getMaxExp();
    int getLevel();
    string getName();
    void setHP(int newHP);
    void setMP(int newMP);
    void setPower(int newPower);
    void setDefence(int newDefence);
    void setJob(string newJob);
    void setLevel(int newLevel);
    void setExp(int newExp);
    void gainExp(int amount);
    void printPlayerStatus();

    
    virtual void attack() = 0;
    virtual ~Player() {}
};