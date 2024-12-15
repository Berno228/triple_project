#include <iostream>
#include <array>
#include <string>
#include <Windows.h>
#include "pythashki.h"

bool victory(std::array<std::array<int, 4>, 4>& base) {
    return (base == std::array<std::array<int, 4>, 4>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0});
}//проверка текущего состояния на победу


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	hideCursor();

	std::string s;
	while (s != "нет") {
		int i0{}, j0{}, trys{};
		std::array<std::array<int, 4>, 4> base = startGame(i0, j0);

		swapElements(base, i0, j0, trys);

		std::cout << "Вы выиграли поздравляю!\n"
			"кол-во клеток, которые пришлось передвинуть: " << trys << '\n'
			<< "Желаете сыграть еще раз введите (да/нет): ";
		std::cin >> s;

		//проверка ввода
		while (!(s == "нет" || s == "да")) {
			std::cout << "Вы ввели некорректное значение, повторите ввод.\n";
			std::cin.ignore(32000, '\n');
			std::cin >> s;
		}
	}

	return 0;
}
