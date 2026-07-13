
#include <iostream>
#include <string>
using namespace std;

void printStatus(string name, int stat[]) {
    cout << "\n" << "<" << name << ">" << "\n";
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

    cout << "\n???: 어디보자.. 체력은 어떤가? 부품은 몇 발 남았고? (두 스탯을 1-100 사이로 입력하시오.)  \n";
    cout << "나 : ";
    cin >> stat[0] >> stat[1];
    cout << "\n???: 그리고... 명중률은? 옷은 두껍고? (두 스탯을 1-100 사이로 입력하시오.)  \n";
    cout << "나 : ";

    cin >> stat[2] >> stat[3];
    cout << "---------------------------------------------------------------------------------\n";
    cout << "                                      [Status]";
    printStatus(name, stat);
    cout << "---------------------------------------------------------------------------------\n";
    return 0;
}   

