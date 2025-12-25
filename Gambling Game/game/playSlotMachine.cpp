#include "SlotMachine module.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void get_Slots_Rules()
{
    cout << "Правила игры:" << endl;
    cout << "\t-Игрок делает ставку и ожидает результата" << endl;
    cout << "\t-Машина крутиться, деньги мутятся" << endl;
    cout << "\t-Условия выигрыша/проигрыша:" << endl;
    cout << "\t-Не совпало ничего: Отсутствует" << endl;
    cout << "\t-Совпало 2 ячейки: Двухкратный" << endl;
    cout << "\t-Совпало 3 ячейки: Трёхкратный" << endl;
    cout << "Нажмите любую клавишу чтобы выйти..." << endl;
    _getch();
    system("cls");
}

void play_Slots(int& money)
{

    setlocale(LC_ALL, "Russian");

    int stavka;
    char play = 'y';

    const char symbols[] = { 'A', '7', '#', '&', '$' };
    const int SIZE = 5;

    char s1, s2, s3;
    cout << "СЛОТ-РУЛЕТКА\n";
        cout << "Баланс: " << money << " монет\n\n";
    cout << "Введите ставку: ";
        cin >> stavka;
    while (play == 'y' || play == 'Y')
    {
        
        srand(time(0));

        system("cls");
        
        if (money == 0) return;

        

        if (stavka > money) {
            system("cls");
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Некоректная ставка! Ставка не может быть больше вашего текущего баланса \n введите снова: " << endl;
            cin >> stavka;
            continue;
        }
        else if (stavka <= 0) {
            system("cls");
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Некоректная ставка! \n введите снова: " << endl;
            cin >> stavka;
            continue;
        }


        for (int i = 0; i < 20; i++)
        {
            s1 = symbols[rand() % SIZE];
            s2 = symbols[rand() % SIZE];
            s3 = symbols[rand() % SIZE];


            system("cls");

            cout << "КРУТИМ...\n\n";
            cout << " [ " << s1 << " | " << s2 << " | " << s3 << " ]\n";

            Sleep(120);
        }


        system("cls");


        cout << "РЕЗУЛЬТАТ\n\n";
        cout << " [ " << s1 << " | " << s2 << " | " << s3 << " ]\n\n";

        if (s1 == s2 && s2 == s3) {
            int win = stavka * 3;
            money += win;
            cout << "ДЖЕКПОТ!" << "\n";
            cout << "Выигрыш:" << win;
        }
        else if (s1 == s2 || s2 == s3 || s1 == s3) {
            int win = stavka * 2;
            money += win;
            cout << "Совпадение!" << "\n";
            cout << "Выигрыш:" << win;

        }
        else {
            money -= stavka;
            cout << "Проигрыш - " << stavka << "\n";
        }

        cout << "\nТекущий баланс: " << money << "\n";
        cout << "\nИграть ещё? (y/n): ";
        cin >> play;
    }
    system("cls");
}


void playSlotMachine(int& money) {
    char key;

    while (true) {
        if (money == 0) return;

        system("cls");

        cout << "+--------------------------+" << endl;
        cout << "| Добро пожаловать в Слоты |" << endl;
        cout << "+--------------------------+" << endl;
        cout << endl;
        cout << "\tВаш баланс: " << money << " жетонов" << endl;
        cout << endl;
        cout << "Что вы хотите сделать ? " << endl;
        cout << "\t(1) Сыграть" << endl;
        cout << "\t(2) Узнать правила" << endl;
        cout << "\t(3) Выйти" << endl;
        cout << "-(Нажмите необходимую клавишу)-" << endl;
        key = _getch();
        system("cls");
        if (key == '3') {
            return;
        }
        else if (key == '2') {
            get_Slots_Rules();
        }
        else if (key == '1') {
            play_Slots(money);
        }
    }
}
