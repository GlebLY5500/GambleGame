#include "BlackJack module.h"
#include <iostream>
#include <conio.h>
using namespace std;

void getRules() {
	cout << "Правила игры:" << endl;
	cout << "\t-Игроку и диллеру выдаются по 2 случайных числа от 1 до 10" << endl;
	cout << "\t-Задача игрока: набрать сумму значений чисел равной 21" << endl;
	cout << "\t-В ходе раунда игрок делает выбор набрать ещё число или оставить текущие до конца. Диллер делает тоже самое" << endl;
	cout << "\t-Победа достаётся тому кто ближе всего окажется по сумме к 21" << endl;
	cout << "\t-Если сумма - больше 21 - проигрыш" << endl;
	cout << "Нажмите любую клавишу чтобы выйти" << endl;
	_getch();
	system("cls");
}

int getSum(int elements[], int NumberOfElements) {
	int SumOfElements = 0;
	for (int i = 0; i < NumberOfElements; i++) {
		SumOfElements += elements[i];
	}
	return SumOfElements;
}

void showElements(int elements[], int NumberOfElements) {
	for (int i = 0; i < NumberOfElements; i++) {
		cout << " " << elements[i];
	}
	cout << endl;
}

int getRandomCard() {
	return (rand() % 10 + 1);
}

void playGame(int &money) {
	int bet=0;
	int i = 2, j = 2;
	bool endflag = false;
	int Dcards[10] = { 0,0,0,0,0,0,0,0,0,0 }, Pcards[10] = { 0,0,0,0,0,0,0,0,0,0 }, Dsum = 0, Psum = 0;
	char key;
	system("cls");
	cout << "Сделайте свою ставку: ";
	cin >> bet;
	while (true) {
		
		if (bet > money) {
			system("cls");
			cout << "Некоректная ставка! Ставка не может быть больше вашего текущего баланса \n введите снова: " << endl;
			cin >> bet;
		}
		else if (bet == 0) {
			system("cls");
			cout << "Некоректная ставка! Ставка должна быть больше 0 \n введите снова: " << endl;
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


			Pcards[0] = getRandomCard();
			Pcards[1] = getRandomCard();
			Dcards[0] = getRandomCard();
			Dcards[1] = getRandomCard();

			while(true) {
				
				Dsum = getSum(Dcards, j);
				Psum = getSum(Pcards, i);
				cout << "+------------------------------+" << endl;
				cout << "Числа диллера: ";
				showElements(Dcards,j);
				cout << "Сумма диллера: " << Dsum << endl;
				cout << "+------------------------------+" << endl;
				cout << "Ваши числа: ";
				showElements(Pcards, i);
				cout << "Ваша сумма: " << Psum << endl;
				cout << "+------------------------------+" << endl << endl;
				if (Psum == 21 && Dsum !=21) {
					cout << "Ваша сумма равна 21! Вы выиграли" << endl;
					money += bet * 2;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (Psum == 21 && Dsum == 21) {
					cout << "У вас обоих сумма 21. Ничья. Поставленые деньги возвращены." << endl;
					money += bet;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (Psum != 21 && Dsum == 21) {
					cout << "Сумма значений диллера равна 21. Вы проиграли." << endl;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (Psum > 21 && Dsum < 21) {
					cout << "Ваша сумма оказалась больше 21. Вы проиграли.";
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (Psum < 21 && Dsum > 21) {
					cout << "Вы выиграли! Сумма диллера - больше 21.";
					money += bet * 2;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (endflag && (abs(21 - Dsum) < abs(21 - Psum))) {
					cout << "Сумма значений диллера ближе к 21. Вы проиграли." << endl;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (endflag && (abs(21 - Dsum) > abs(21 - Psum))) {
					cout << "Ваша сумма ближе к 21! Вы выиграли" << endl;
					money += bet * 2;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				if (endflag && Psum==Dsum) {
					cout << "Ничья. Деньги возвращены" << endl;
					money += bet;
					cout << endl << "Нажмите любую клавишу чтобы вернуться..." << endl;
					_getch();
					system("cls");
					return;
				}
				cout << "Что вы хотите сделать? (Нажмите 1 чтобы набрать ещё карту, нажмите любую клавишу чтобы оставить текущую руку)" << endl;
				key = _getch();

				if (key == '1') {
					Pcards[i] = getRandomCard();
					i++;
				}
				Dsum = getSum(Dcards, i);
				Psum = getSum(Pcards, i);
				if ((abs(21 - Dsum) > abs(21 - Psum))&&Psum<21&&key=='1') {
					Dcards[j] = getRandomCard();
					j++;
				}
				if (key != '1') {
					endflag = true;
					while (abs(21 - Dsum) > abs(21 - Psum) && Dsum <= 21) {
						Dcards[j] = getRandomCard();
						j++;
						Dsum = getSum(Dcards, j);
					}
				}
				system("cls");
			}

			

		}
	}
}



void playBlackJack(int& money) {
	char key;
	while (true) {
		cout << "+-----------------------+" << endl;
		cout << "| Добро пожаловать в 21 |" << endl;
		cout << "+-----------------------+" << endl;
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