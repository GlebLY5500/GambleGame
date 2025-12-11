#include "BlackJack module.h"
#include <iostream>
#include <conio.h>
using namespace std;

void getRules() {
	cout << "Правила игры:" << endl;
	cout << "\t-Игроку и диллеру выдаются по две карты в открытую" << endl;
	cout << "\t-Задача игрока: набрать сумму значений карт равной 21" << endl;
	cout << "\t-В ходе раунда игрок делает выбор набрать ещё карты или оставить. Диллер делает тоже самое" << endl;
	cout << "\t-Победа достаётся тому кто ближе всего окажется по сумме к 21" << endl;
	cout << "\t-Если сумма - больше 21 - проигрыш" << endl;
	cout << "Нажмите любую клавишу чтобы выйти" << endl;
	_getch();
	system("cls");
}

void playGame(int &money) {
	int bet;


	system("cls");
	cout << "Сделайте свою ставку: ";
	cin >> bet;
	while (true) {
		
		if (bet > money) {
			system("cls");
			cout << "Некоректная ставка! Ставка не может быть больше вашего текущего баланса \n введите снова: " << endl;
			cin >> bet;
		}
		else if (cin.fail() == true) {
			system("cls");
			cin.clear();
			cin.ignore();
			cout << "Некоректная ставка! Ставка должна быть числом \n введите снова: " << endl;
			cin >> bet;
		}
		else {
			cout << "Ваша ставка принята" << endl << endl;
			money -= bet;

			int Dcards[10], Pcards[10], Dsum=0,Psum=0;
			char key;
			Pcards[0] = rand() % 13 + 1;
			Pcards[1] = rand() % 13 + 1;
			Dcards[0] = rand() % 13 + 1;
			Dcards[1] = rand() % 13 + 1;
			Dsum = Dcards[0] + Dcards[1];
			Psum = Pcards[0] + Pcards[1];
			for (int i = 2; i < 10; i++) {			
				cout << "+------------------------------+" << endl;
				cout << "Числа диллера: " << Dcards[0] << " " << Dcards[1] << endl;
				cout << "Сумма диллера: " << Dsum << endl;
				cout << "+------------------------------+" << endl;
				cout << "Ваши числа: " << Pcards[0] << " " << Pcards[1] << endl;
				cout << "Ваша сумма: " << Psum << endl;
				cout << "+------------------------------+" << endl << endl;
				cout << "Что вы хотите сделать? (Нажмите 1 чтобы набрать ещё карту, нажмите 0 чтобы оставить текущую руку)" << endl;
				key = _getch();
			}
		}
	}
}

void playBlackJack(int& money) {
	char key;
	while (true) {
		cout << "+-----------------------------+" << endl;
		cout << "| Добро пожаловать в БлекДжек |" << endl;
		cout << "+-----------------------------+" << endl;
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
		if (key == '3') return;
		else if (key == '2') getRules();
		else if (key == '1') playGame(money);
	}
	
}