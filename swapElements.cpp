#include <iostream>
#include <array>
#include <Windows.h>
#include "pythashki.h"

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void swapElements(std::array<std::array<int, 4>, 4>& base, int& i0, int& j0, int& trys) {
	printGame(base);

	while (true) {

		if (victory(base))
			break;

		if (i0 >= 1 && i0 <= 3 && GetAsyncKeyState(VK_UP)) {
			std::swap(base[i0][j0], base[i0--][j0]);
			printGame(base);
			++trys;
		}
		
		if (i0 >= 0 && i0 <= 2 && GetAsyncKeyState(VK_DOWN)) {
			std::swap(base[i0][j0], base[i0++][j0]);
			printGame(base);
			++trys;
		}

		
		if (j0 >= 1 && j0 <= 3 && GetAsyncKeyState(VK_LEFT)) {
			std::swap(base[i0][j0], base[i0][j0--]);
			printGame(base);
			++trys;
		}

	
		if (j0 >= 0 && j0 <= 2 && GetAsyncKeyState(VK_RIGHT)) {
			std::swap(base[i0][j0], base[i0][j0++]);
			printGame(base);
			++trys;
		}

		if (GetAsyncKeyState(VK_ESCAPE))
			exit(0);
			
		
		Sleep(200);
	}
}
