#ifndef PYTHASHKI_H
#define PYTHASHKI_H

bool isCorrect(std::array<std::array<int, 4>, 4>& mass, int& i0);
void hideCursor();
void printGame(const std::array<std::array<int, 4>, 4>& mass);
bool victory(std::array<std::array<int, 4>, 4>& base);
std::array<std::array<int, 4>, 4> startGame(int& i0, int& j0);
void swapElements(std::array<std::array<int, 4>, 4>& base, int& i0, int& j0, int& trys);

#endif
