#include <iostream>
#include <array>
#include <string>
#include <Windows.h>
using namespace std;

void swapElements(array<array<int, 4>, 4>& base, int& i0, int& j0, int& trys);
void hideCursor();
array<array<int, 4>, 4> startGame(int& i0, int& j0);
void printGame(const array<array<int, 4>, 4>& mass);

bool victory(array<array<int, 4>, 4>& base) {
    return (base == array<array<int, 4>, 4>{(1, 2, 3, 4), (5, 6, 7, 8), (9, 10, 11, 12), (13, 14, 15, 0)});
}//проверка текущего состояния на победу


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	hideCursor();

	std::string s;
	while (s != "нет") {
		int i0{}, j0{}, trys{};
		array<array<int, 4>, 4> base = startGame(i0, j0);

		swapElements(base, i0, j0, trys);

		cout << "Вы выиграли поздравляю!\n"
			"кол-во клеток, которые пришлось передвинуть: " << trys << '\n'
			<< "Желаете сыграть еще раз введите (да/нет): ";
		cin >> s;

		//проверка ввода
		while (s != "нет" || s != "да") {
			cout << "Вы ввели некорректное значение, повторите ввод.";
			cin.ignore(32000, '\n');
			cin >> s;
		}
	}

	return 0;
}