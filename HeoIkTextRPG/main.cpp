#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"

using namespace std;

struct Item {
    string name;
    int price;
    void PrintInfo() const {
        cout << name << " (" << price << " Gold" << ")\n";
    }
};

struct PotionRecipe {
    string name;
    string ingredient1;
    string ingredient2;
    void PotionInfo() const {
        cout << name << " (" << ingredient1 << ", " << ingredient2 << ")\n";

    }
};

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}


void printStatus(string name, int stat[]) {
    cout << "\n" << "<" << name << ">" << "\n";
    cout << "HP: " << stat[0] << "\n";
    cout << "MP: " << stat[1] << "\n";
    cout << "PWR: " << stat[2] << "\n";
    cout << "DEF: " << stat[3] << "\n";
}

int main()
{

    int H_Potion = 0;
    int M_Potion = 0;

    setPotion(5, &H_Potion, &M_Potion);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));
    const int MAX_INVENTORY = 10;
    vector<Item> inventory;
    vector<PotionRecipe> recipeList;
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // [0] HP, [1] AMMO, [2] ATK, [3] DEF
    cout << "================================================================================\n";
    cout << "             [ 눈을 떠보니 미국 서부개척시대 카우보이로 회귀해있었다. ]\n";
    cout << "================================================================================\n";

    cout << "\n???: 이보게 자네, 이름이 뭔가?  \n";
    cout << "입력 : ";
    getline(cin, name);

    cout << "\n???: 어디보자.. HP은 어떤가? MP은 얼마나 남았고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "입력 : ";
        stat[0] = getInt();
        stat[1] = getInt();
        if (stat[0] > 50 && stat[0] <= 80 && stat[1] > 50 && stat[1] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n" << "\n";
    }

    cout << "\n???: 그리고... 공격력은? 방어력은 어떻고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "입력 : ";
        stat[2] = getInt();
        stat[3] = getInt();
        if (stat[2] > 50 && stat[2] <= 80 && stat[3] > 50 && stat[3] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "                                      [Status]";
    printStatus(name, stat);
    cout << "---------------------------------------------------------------------------------\n\n";


    bool isGameStart = false;
    int choice = 0;



    while (!isGameStart) {
        cout << "< 캐릭터 강화 >\n" << " 1. HP UP " << " 2. MP UP " << " 3. 공격력 2배 \n" << " 4. 방어력 2배 " << " 5. 현재능력치 " << " 0. 게임 시작 \n\n";
        cout << "입력 : ";
        choice = getInt();
        cout << "\n" << "---------------------------------------------------------------------------------\n\n";
        switch (choice) {
        case 0: 
            cout << "게임을 시작하지.\n";
            cout << "\n" << "---------------------------------------------------------------------------------\n\n";

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
            cout << "---------------------------------------------------------------------------------\n\n";
            break;
        case 5: printStatus(name, stat);
            cout << "\n";
            break;
        default:
            cout << "잘못된 입력입니다.\n";

        }
    }
    Player* player = nullptr;

    while(player == nullptr){
    int job = 0;
    cout << "< 직업 선택 >\n" << " 1. 무법자 " << " 2. 보안관 " << " 3. 목동 " << " 4. 현상금 사냥꾼 \n\n" ;
    cout << "입력 : ";
    job = getInt();
    switch (job) {
    case 1:
        player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
        player->setHP(player->getHP() + 30);
        cout << "---------------------------------------------------------------------------------\n\n";
        cout << "* 무법자로 전직하였습니다. (HP +30)\n\n";
        cout << "---------------------------------------------------------------------------------\n\n";
        player->attack();
        break;

    case 2:
        player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
        player->setMP(player->getMP() + 30);
        cout << "---------------------------------------------------------------------------------\n\n";
        cout << "* 보안관으로 전직하였습니다. (MP +30)\n\n";
        cout << "---------------------------------------------------------------------------------\n\n";

        player->attack();
        break;

    case 3:
        player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
        player->setDefence(player->getDefence() + 30);
        cout << "---------------------------------------------------------------------------------\n\n";
        cout << "* 목동으로 전직하였습니다. (DEF +30)\n\n";
        cout << "---------------------------------------------------------------------------------\n\n";

        player->attack();
        break;

    case 4:
        player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
        player->setPower(player->getPower() + 30);
        cout << "---------------------------------------------------------------------------------\n\n";
        cout << "* 현상금 사냥꾼으로 전직하였습니다. (ATK +30)\n\n";
        cout << "---------------------------------------------------------------------------------\n\n";

        player->attack();
        break;
    default:
        cout << "정확한 숫자를 입력해주세요. \n";
            break;
    }
    }


    bool isPlaying = true;
    while (isPlaying) {
        cout << "---------------------------------------------------------------------------------\n\n";

        cout << "< 메인 메뉴 >\n1.사냥터 입장      2. 배낭 확인      3. 살론 주점으로      4. 상태 확인      0. 게임종료\n\n";
        int menu;
        cout << "입력 : ";
        menu = getInt();

        switch (menu) {
        case 1: {
            Monster monsters[3]{
                Monster("회전초", 30, 20, 10, "나뭇가지", 50),
                Monster("들소", 60, 40, 20, "소머리", 100),
                Monster("마피아", 90, 60, 30, "총알구멍 난 중절모", 150)
            };
            int pick = rand() % 3;
            cout << "\n[ 전투 시작! ]    \n" << name << " vs " << monsters[pick].getName() << "\n" << endl;

            while (player->getHP() > 0 && monsters[pick].getHP() > 0) {
                cout << "---------------------------------------------------------------------------------\n";
                cout << "  *플레이어의 턴* \n";
                cout << "---------------------------------------------------------------------------------\n";

                player->attack();

                int damage = player->getPower() - monsters[pick].getDefence();
                if (damage <= 0) damage = 1;


                cout << monsters[pick].getName() << " 에게 " << damage << " 데미지를 입혔습니다! \n" << endl;

                monsters[pick].setHP(monsters[pick].getHP() - damage);

                if (monsters[pick].getHP() <= 0) {
                    cout << "승리하였습니다! \n" << monsters[pick].getDropItemName() << "을 얻었습니다!" << endl;
                    player->gainExp(30);
                    Item drop;
                    drop.name = monsters[pick].getDropItemName();
                    drop.price = monsters[pick].getDropItemPrice();
                    inventory.push_back(drop);
                    break;
                }
                cout << "---------------------------------------------------------------------------------\n";
                cout << "  *적의 턴* \n";
                cout << "---------------------------------------------------------------------------------\n";

                monsters[pick].attack(player);

            }
            if (player->getHP() <= 0) {
                cout << "---------------------------------------------------------------------------------\n";
                cout << "Game Over" << endl;
                cout << "---------------------------------------------------------------------------------\n";

            }
        }
              break;

        case 2:
            cout << "[ 인벤토리 " << inventory.size() << " / " << MAX_INVENTORY << "]\n";
            for (Item inventoryCheck : inventory) {
                inventoryCheck.PrintInfo();
            }
            break;

        case 0:
            isPlaying = false;
            break;

        case 3: {
            PotionRecipe HPPR;
            HPPR.name = "위스키(샷)";
            HPPR.ingredient1 = "버팔로트레이스";
            HPPR.ingredient2 = "얼음";
            recipeList.push_back(HPPR);

            PotionRecipe STPR;
            STPR.name = "라거(파인트)";
            STPR.ingredient1 = "버드와이저";
            STPR.ingredient2 = "얼음";
            recipeList.push_back(STPR);

            bool inWorkshop = true;
            while (inWorkshop) {
                int potionMenu;
                cout << "---------------------------------------------------------------------------------\n";
                cout << " 살론 주점 \n 1. 전체 레시피 \n 2. 메뉴 이름으로 찾기\n 3. 재료로 찾기\n 0. 돌아가기\n";
                cout << "---------------------------------------------------------------------------------\n";

                cout << "입력 : ";

                potionMenu = getInt();
                switch (potionMenu) {
                case 1: // 전체레시피
                    for (PotionRecipe r : recipeList) {
                        r.PotionInfo();
                    }
                    break;
                case 2: // 이름 검색

                {
                    string keyword;
                    cout << "검색할 메뉴: ";
                    cin >> keyword;

                    bool found = false;
                    for (PotionRecipe r : recipeList) {
                        if (r.name == keyword) {
                            r.PotionInfo();
                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "해당 칵테일을 찾을 수 없습니다. \n";
                    }

                    break;
                }
                case 3: // 재료 검색
                {
                    string keyword;
                    cout << "검색할 재료명: ";
                    cin >> keyword;
                    bool found = false;
                    for (PotionRecipe r : recipeList) {
                        if (r.ingredient1 == keyword || r.ingredient2 == keyword) {
                            r.PotionInfo();
                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "해당 재료를 찾을 수 없습니다. \n";
                    }
                    break;
                }
                case 0: // 돌아가기
                    inWorkshop = false;
                    break;

                }

               
            }





        }
        case 4: player->printPlayerStatus();
        }
    }


    delete player;
    
    return 0;
}   
