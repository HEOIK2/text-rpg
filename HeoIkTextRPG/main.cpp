
#include <iostream>
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
    Player(string name, int hp, int mp, int power, int defence) : name(name), hp(hp), mp(mp), power(power), defence(defence) {};
    int getHP() {
        return hp;
    }
    int getMP() {
        return mp;
    }
    int getPower() {
        return power;
    }
    int getDefence() {
        return defence;
    }
    string getName() {
        return name;
    }
    void setHP(int newHP) {
        hp = newHP;
    }
    void setMP(int newMP) {
        mp = newMP;
    }
    void setPower(int newPower) {
        power = newPower;
    }
    void setDefence(int newDefence) {
        defence = newDefence;
    }
    void setJob(string newJob) {
        job = newJob;
    }
    void setLevel(int newLevel) {
        level = newLevel;
    }
    virtual void attack() = 0;
    virtual ~Player() {}
};

class Monster {

protected:
    string name;
    int hp;
    int power;
    int defence;
    string dropItemName;
public:
    Monster(string name, int hp, int power, int defence, string dropItemName) : name(name), hp(hp), power(power), defence(defence), dropItemName(dropItemName) {};
    int getHP() {
        return hp;
    }
    int getPower() {
        return power;
    }
    int getDefence() {
        return defence;
    }
    void setHP(int newHP) {
        hp = newHP;
    }
    string getName() {
        return name;
    }
    void attack(Player* player) {
        int damage = power - player->getDefence();
        if (damage <= 0) {
            damage = 1;
        }
        player->setHP(player->getHP() - damage);
        cout << name << "이 당신에게 " << damage << "의 데미지를 입혔습니다!" << endl;
    }
        string getDropItemName() {
            return dropItemName;
        }

    
};

void printStatus(string name, int stat[]) {
    cout << "\n" << "<" << name << ">" << "\n\n";
    cout << "HP: " << stat[0] << "\n";
    cout << "MP: " << stat[1] << "\n";
    cout << "PWR: " << stat[2] << "\n";
    cout << "DEF: " << stat[3] << "\n";
}

class Warrior : public Player {
public:
    Warrior(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}
    void attack() override {
        cout << "데마시아!" << endl;
    }
};

class Magician : public Player {
public:
    Magician(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}
    void attack() override {
        cout << "마법발사! 뿅뿅뿡뿡" << endl;
    }
};

class Thief : public Player {
public:
    Thief(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}
    void attack() override {
        cout << "슈슉 슈숙. 슉. 시. ***아." << endl;
    }
};

class Archer : public Player {
public:
    Archer(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence) {}
    void attack() override {
        cout << "어둠에 빠진 자들을 사냥해볼까?" << endl;
    }
};

int main()
{
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // [0] HP, [1] AMMO, [2] ATK, [3] DEF
    cout << "================================================================================\n";
    cout << "                           [ †B lack D ead R edemti●n† ]\n";
    cout << "================================================================================\n";

    cout << "\n???: 이보게 모험가, 당신 이름이 뭐요?  \n";
    cout << "나 : ";
    getline(cin, name);

    cout << "\n???: 어디보자.. HP은 어떤가? MP은 얼마나 남았고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "나 : ";
        cin >> stat[0] >> stat[1];
        if (stat[0] > 50 && stat[0] <= 80 && stat[1] > 50 && stat[1] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n" << "\n";
    }

    cout << "\n???: 그리고... 공격력은? 방어력은 어떻고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "나 : ";
        cin >> stat[2] >> stat[3];
        if (stat[2] > 50 && stat[2] <= 80 && stat[3] > 50 && stat[3] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "                                      [Status]";
    printStatus(name, stat);
    cout << "---------------------------------------------------------------------------------\n";

    int H_Potion = 5;
    int M_Potion = 5;
    bool isGameStart = false;
    int choice = 0;



    while (!isGameStart) {
        cout << "< 캐릭터 강화 >\n" << " 1. HP UP " << " 2. MP UP " << " 3. 공격력 2배 \n" << " 4. 방어력 2배 " << " 5. 현재능력치 " << " 0. 게임 시작 \n\n" << "입력: ";
        cin >> choice;
        cout << "\n" << "---------------------------------------------------------------------------------\n";
        switch (choice) {
        case 0: 
            cout << "게임을 시작합니다앗!";
            isGameStart = true;
            break;
        case 1: if (H_Potion > 0) {
            stat[0] += 20;
            H_Potion -= 1;
            cout << "HP 포션을 사용했습니다. (남은 포션: " << H_Potion << "개)\n";
            cout << "---------------------------------------------------------------------------------\n";
        }    

              else {
            cout << "HP 포션이 부족합니다. \n\n";
            cout << "---------------------------------------------------------------------------------\n";

        }
            break;
        case 2: if (M_Potion > 0) {
            stat[1] += 20;
            M_Potion -= 1;
            cout << "MP 포션을 사용했습니다. (남은 포션: " << M_Potion << "개)\n";
            cout << "---------------------------------------------------------------------------------\n";
        }
              else {
            cout << "MP 포션이 부족합니다. \n\n";
            cout << "---------------------------------------------------------------------------------\n";

        }
            break;
        case 3: stat[2] *= 2;
            cout << "공격력이 올랐습니다. \n";
            cout << "---------------------------------------------------------------------------------\n";
            break;
        case 4: stat[3] *= 2;
            cout << "방어력이 올랐습니다. \n";
            cout << "---------------------------------------------------------------------------------\n";
            break;
        case 5: printStatus(name, stat);
            cout << "\n";
            break;

        }
    }

    Player* player = nullptr;
    int job = 0;
    cout << "< 직업 선택 >\n" << " 1. 전사 " << " 2. 마법사 " << " 3. 도적 " << " 4. 궁수 " << "\n\n 입력: " ;
    cin >> job;
    switch (job) {
    case 1:
        player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
        player->setHP(player->getHP() + 30);
        cout << "\n* 전사로 전직하였습니다. (HP +30)\n";
        player->attack();
        break;

    case 2:
        player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
        player->setMP(player->getMP() + 30);
        cout << "\n* 마법사로 전직하였습니다. (MP +30)\n";
        player->attack();
        break;

    case 3:
        player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
        player->setDefence(player->getDefence() + 30);
        cout << "\n* 도적으로 전직하였습니다. (DEF +30)\n";
        player->attack();
        break;

    case 4:
        player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
        player->setPower(player->getPower() + 30);
        cout << "\n* 궁수로 전직하였습니다. (ATK +30)\n";
        player->attack();
        break;
    }

    Monster slime("슬라임", 30, 20, 10, "끈적한 점액질");

    cout << "[ 전투 시작! ]    " << name << " vs " << slime.getName() << endl;

    while (player->getHP() > 0 && slime.getHP() > 0) {
        cout << " --- 플레이어의 턴 ---" << endl;
        player->attack();
        cout << "슬라임에게 " << player->getPower() - slime.getDefence() << " 데미지!" << endl;
        slime.setHP(slime.getHP() - (player->getPower() - slime.getDefence()));
        if (slime.getHP() <= 0) {
            cout << "승리하였습니다! " << slime.getDropItemName() << "을 얻었습니다!" << endl;
            break;
        }
        cout << " --- 적의 턴 ---" << endl;
        slime.attack(player);

    }
    if (player->getHP() <= 0) {
        cout << "패배하였습니다..." << endl;
    }

    delete player;
    
    return 0;
}   
