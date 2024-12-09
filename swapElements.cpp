#include <iostream>
#include <array>
#include <Windows.h>
using namespace std;

inline bool victory(array<array<int, 4>, 4>& base);
array<array<int, 4>, 4> startGame(int& i0, int& j0);
void printGame(const array<array<int, 4>, 4>& mass);

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void swapElements(array<array<int, 4>, 4>& base, int& i0, int& j0, int& trys) {
	printGame(base);

	while (true) {

		if (victory(base))
			break;

		if (i0 >= 1 and i0 <= 3 and GetAsyncKeyState(VK_UP)) {
			std::swap(base[i0][j0], base[i0--][j0]);
			printGame(base);
			++trys;
		}
		
		if (i0 >= 0 and i0 <= 2 and GetAsyncKeyState(VK_DOWN)) {
			std::swap(base[i0][j0], base[i0++][j0]);
			printGame(base);
			++trys;
		}

		
		if (j0 >= 1 and j0 <= 3 and GetAsyncKeyState(VK_LEFT)) {
			std::swap(base[i0][j0], base[i0][j0--]);
			printGame(base);
			++trys;
		}

	
		if (j0 >= 0 and j0 <= 2 and GetAsyncKeyState(VK_RIGHT)) {
			std::swap(base[i0][j0], base[i0][j0++]);
			printGame(base);
			++trys;
		}

		if (GetAsyncKeyState(VK_ESCAPE))
			exit(0);
			
		
		Sleep(200);
	}
}

