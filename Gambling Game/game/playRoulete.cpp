#include "Roulete module.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits>
using namespace std;

void getRouleteRules() {
	cout << "Правила игры:" << endl;
	cout << "\t-Игрок делает ставку выбирая на какую цифру, цвет или дюжину он хочет поставить" << endl;
	cout << "\t-Рулетка крутится" << endl;
	cout << "\t-Условия выигрыша/проигрыша:" << endl;
	cout << "\t-Совпал цвет: х2" << endl;
	cout << "\t-Совпали дюжины: х3" << endl;
	cout << "\t-Совпало число: х5" << endl;
	cout << "\t-Совпал 0: х10" << endl;
	cout << "\t-Промах - проигрыш" << endl;
	cout << "Нажмите любую клавишу чтобы выйти..." << endl;
	_getch();
	system("cls");
}

void playAnimation() {
	for (int i = 0; i < 4; i++) {
		cout << "     ##|##   " << endl;
		cout << "   ##     ## " << endl;
		cout << "  \\         /" << endl;
		cout << " #           #" << endl;
		cout << " #           #" << endl;
		cout << "#             #" << endl;
		cout << "#             #" << endl;
		cout << "- =====O===== -" << endl;
		cout << "#             #" << endl;
		cout << "#             #" << endl;
		cout << " #           #" << endl;
		cout << " #           #" << endl;
		cout << "  /         \\" << endl;
		cout << "   ##     ## " << endl;
		cout << "     ##|##   " << endl;
		Sleep(500);
		system("cls");
		cout << "     ##|##   " << endl;
		cout << "   ##     ## " << endl;
		cout << "  \\         /" << endl;
		cout << " #           #" << endl;
		cout << " #  \\        #" << endl;
		cout << "#    \\        #" << endl;
		cout << "#     \\       #" << endl;
		cout << "-      O      -" << endl;
		cout << "#       \\     #" << endl;
		cout << "#        \\    #" << endl;
		cout << " #        \\  #" << endl;
		cout << " #           #" << endl;
		cout << "  /         \\" << endl;
		cout << "   ##     ## " << endl;
		cout << "     ##|##   " << endl;
		Sleep(500);
		system("cls");
		cout << "     ##|##   " << endl;
		cout << "   ##     ## " << endl;
		cout << "  \\    |    /" << endl;
		cout << " #     |     #" << endl;
		cout << " #     |     #" << endl;
		cout << "#      |      #" << endl;
		cout << "#      |      #" << endl;
		cout << "-      O      -" << endl;
		cout << "#      |      #" << endl;
		cout << "#      |      #" << endl;
		cout << " #     |     #" << endl;
		cout << " #     |     #" << endl;
		cout << "  /    |    \\" << endl;
		cout << "   ##     ## " << endl;
		cout << "     ##|##   " << endl;
		Sleep(500);
		system("cls");
		cout << "     ##|##   " << endl;
		cout << "   ##     ## " << endl;
		cout << "  \\         /" << endl;
		cout << " #           #" << endl;
		cout << " #        /  #" << endl;
		cout << "#        /    #" << endl;
		cout << "#       /     #" << endl;
		cout << "-      O      -" << endl;
		cout << "#     /       #" << endl;
		cout << "#    /        #" << endl;
		cout << " #  /        #" << endl;
		cout << " #           #" << endl;
		cout << "  /         \\" << endl;
		cout << "   ##     ## " << endl;
		cout << "     ##|##   " << endl;
		Sleep(500);
		system("cls");
	}
	
}


void playGameRoulete(int& balance) {
	int bet = 0, number, betnumber;
	int twelve, oddeven;
	char choice = ' ';
	cout << "Выберите на что вы хотите поставить:" << endl;
	cout << "----------Выигрыш х2----------" << endl;
	cout << "\t(1) Красное (чётное)" << endl;
	cout << "\t(2) Чёрное (нечётное)" << endl;
	cout << "----------Выигрыш х3----------" << endl;
	cout << "\t(3) 1-ая дюжина (1-12)" << endl;
	cout << "\t(4) 2-ая дюжина (13-24)" << endl;
	cout << "\t(5) 3-я дюжина (25-36)" << endl;
	cout << "----------Выигрыш х5----------" << endl;
	cout << "\t(6) Ставка на число (1-36)" << endl;
	cout << "----------Выигрыш х10----------" << endl;
	cout << "\t(7) Ставка на 0 (zero)" << endl;
	cout << endl;
	cout << "Чтобы вернуться нажмите другое" << endl;
	cout << endl;
	cout << "Сделайте выбор... " << endl;
	choice = _getch();
	if (choice>'7'||choice<'1') { system("cls"); return; }

	

	cout << "Вы выбрали: " << choice << endl;
	if (choice == '6') {
		cout << "Введите число на которое хотите поставить (от 1 до 36)" << endl;
		cin >> betnumber;
		while ((betnumber > 36 || betnumber < 1) || cin.fail() == true) {
			cout << "Вы ввели некоректно. Повторите ввод " << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> betnumber;
		}
	}
	cout << endl;
	cout << "Ваш баланс: " << balance << endl;
	cout << "\t Сделайте ставку: ";
	cin >> bet;
	while (true) {
		
		if (bet > balance) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Некоректная ставка! Ставка не может быть больше вашего текущего баланса \n введите снова: " << endl;
			cin >> bet;
			
		}
		else if (bet <= 0) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Некоректная ставка!  \n введите снова: " << endl;
			cin >> bet;
			
		}
		else {
			cout << "Ваша ставка принята" << endl << endl;
			balance -= bet;
			Sleep(500);
			system("cls");
			playAnimation();
			number = rand() % 36 + 1;
			cout << endl;
			cout << "На рулетке выпало число - " << number;
			if (number % 2 == 0 && number != 0) { cout << " (чётное)"; oddeven = 2; }
			else if (number % 2 == 1 && number != 0) { cout << " (нечётное)"; oddeven = 1; }
			if (number > 0 && number < 13) { cout << " (1-ая дюжина)"; twelve = 1; }
			else if (number > 12 && number < 25) { cout << " (2-ая дюжина)"; twelve = 2; }
			else if (number > 24 && number < 37) { cout << " (3-я дюжина)"; twelve = 3; }
			if (number == 0) { cout << " (zero)"; oddeven = 0; twelve = 0; }
			cout << endl;
			if (choice == '1' && oddeven == 2) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet*2;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '2' && oddeven == 1) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 2;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '3' && twelve == 1) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 3;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '4' && twelve == 2) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 3;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '5' && twelve == 3) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 3;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '6' && betnumber==number) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 5;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else if (choice == '7' && number == 0) {
				cout << "Поздравляю, вы победили! " << endl;
				balance += bet * 10;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			else {
				cout << "Нам жаль, но вы проиграли" << endl;
				cout << "Ваш баланс теперь: " << balance << " жетонов" << endl;
			}
			cout << "Нажмите любую клавишу чтобы вернуться...";
			_getch();
			system("cls");
			return;
		}

	}
}




void playRoulete(int& money) {
	

	char key;
	while (true) {
		if (money == 0) return;
		cout << "+----------------------------+" << endl;
		cout << "| Добро пожаловать в рулетку |" << endl;
		cout << "+----------------------------+" << endl;
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
		else if (key == '2') getRouleteRules();
		else if (key == '1') playGameRoulete(money);
	}

}