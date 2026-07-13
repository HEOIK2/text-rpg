
#include <iostream>
#include <string>
using namespace std;

void printStatus(string name, int stat[]) {
    cout << "\n" << "<" << name << ">" << "\n\n";
    cout << "체력: " << stat[0] << "\n";
    cout << "부품: " << stat[1] << "\n";
    cout << "명중률: " << stat[2] << "\n";
    cout << "장갑도: " << stat[3] << "\n";
}

int main()
{
    string name;
    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // [0] HP, [1] AMMO, [2] ATK, [3] DEF
    cout << "================================================================================\n";
    cout << "                           [ †B lack D ead R edemti●n† ]\n";
    cout << "================================================================================\n";

    cout << "\n???: 이보게 잘생긴 총잡이, 당신 이름이 뭐요?  \n";
    cout << "나 : ";
    getline(cin, name);

    cout << "\n???: 어디보자.. 체력은 어떤가? 부품은 몇 발 남았고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "나 : ";
        cin >> stat[0] >> stat[1];
        if (stat[0] > 50 && stat[0] <= 80 && stat[1] > 50 && stat[1] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n" << "\n";
    }

    cout << "\n???: 그리고... 명중률은? 옷은 두껍고? (두 스탯을 51-80 사이로 입력하시오.)  \n";
    while (true) {
        cout << "나 : ";
        cin >> stat[2] >> stat[3];
        if (stat[2] > 50 && stat[2] <= 80 && stat[3] > 50 && stat[4] <= 80) break;
        cout << "???: 적절치 않군... 다시 생각해보게나. \n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "                                      [Status]";
    printStatus(name, stat);
    cout << "---------------------------------------------------------------------------------\n";
    return 0;
}   

