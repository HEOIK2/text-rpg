
#include <iostream>
#include <string>
using namespace std;

void printStatus(string name, int stat[]) {
    cout << "\n" << "<" << name << ">" << "\n";
    cout << "HP: " << stat[0] << "\n";
    cout << "MP: " << stat[1] << "\n";
    cout << "ATK: " << stat[2] << "\n";
    cout << "DEF: " << stat[3] << "\n";
}

int main()
{
    string name;
    cout << "이보게 잘생긴 총잡이, 당신 이름이 뭐요?  ";

    getline(cin, name);

    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // [0] HP, [1] MP, [2] ATK, [3] DEF
    

    cout << "어디보자.. HP는? MP는? (두 스탯을 1-100 사이로 입력하시오.)  ";
    cin >> stat[0] >> stat[1];
    cout << "그리고... ATK는? DEF는? (두 스탯을 1-100 사이로 입력하시오.)  ";
    cin >> stat[2] >> stat[3];

    printStatus(name, stat);

    return 0;
}   

