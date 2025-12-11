#include <iostream>
#include "all modules.h"
#include <conio.h>
#include <windows.h>

using namespace std;

void menutype(int &num) {
	if (num <= 0) num = 4;
	if (num >= 5) num = 1;
	if (num == 1) {
		cout << "+-----------------+" << endl;
		cout << "| Сыграть в слоты |" << endl;
		cout << "+-----------------+" << endl;
		cout << "  Сыграть в блекджек" << endl;
		cout << "  Сыграть в Рулетку" << endl;
		cout << endl;
		cout << "  Выйти" << endl;
	}
	if (num == 2) {
		cout << "  Сыграть в слоты" << endl;
		cout << "+--------------------+" << endl;
		cout << "| Сыграть в блекджек |" << endl;
		cout << "+--------------------+" << endl;
		cout << "  Сыграть в Рулетку" << endl;
		cout << endl;
		cout << "  Выйти" << endl;
	}
	if (num == 3) {
		cout << "  Сыграть в слоты" << endl;
		cout << "  Сыграть в блекджек" << endl;
		cout << "+-------------------+" << endl;
		cout << "| Сыграть в Рулетку |" << endl;
		cout << "+-------------------+" << endl;
		cout << endl;
		cout << "  Выйти" << endl;
	}
	if (num == 4) {
		cout << "  Сыграть в слоты" << endl;
		cout << "  Сыграть в блекджек" << endl;
		cout << "  Сыграть в Рулетку" << endl;
		cout << endl;
		cout << "+-------+" << endl;
		cout << "| Выйти |" << endl;
		cout << "+-------+" << endl;
	}
	cout << endl;
	cout << "-(для управления используйте W и S)-" << endl;
}


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int balance = 5000, menupoint=1;
	char key;

	while (true) {

		cout << "Добро пожаловать в Игровой Зал!\n\tВаш баланс: " << balance << " жетонов";
		cout << endl;
		cout << "Ваша задача: повысить свой стартовый капитал как минимум в 4 раза (иметь баланс равный или больше 20000 жетонов)" << endl;
		cout << endl;
		menutype(menupoint);
		key = _getch();
		if (key == 'w' || key=='ц') menupoint--;
		else if (key == 's' || key == 'ы') menupoint++;
		system("cls");
		if (key == ' ' && menupoint == 1) playSlotMachine(balance);
		if (key == ' ' && menupoint == 2) playBlackJack(balance);
		if (key == ' ' && menupoint == 3) playRoulete(balance);
		if (key == ' ' && menupoint == 4) break;
	}


	
}