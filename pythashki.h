#ifndef	PYTHASKI_H
#define PYTHASKI_H

#include <array>
#include "startAndPrint.cpp"
#include "swapElements.cpp"
#include "victoryAndMain.cpp"

void swapElements(array<array<int, 4>, 4>& base, int& i0, int& j0, int& trys);
void hideCursor();
array<array<int, 4>, 4> startGame(int& i0, int& j0);
void printGame(const array<array<int, 4>, 4>& mass);
inline bool victory(array<array<int, 4>, 4>& base);

#endif
