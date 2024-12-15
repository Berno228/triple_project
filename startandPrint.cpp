#include <iostream>
#include <random>
#include <ctime>
#include <array>
#include <string>
#include <algorithm>
#include "pythashki.h"

bool isCorrect(std::array<std::array<int, 4>, 4>& mass, int& i0)
{
    int sumK{};
    
    for (int i1 = 0, j1 = 0; i1 < 4;) {
        int k{ mass[i1][j1] };
        
        for (int i = i1; i < 4; ++i) {

            int j;
            if (i == i1) j = j1; else j = 0;

            for (; j < 4; ++j)
                if (k > mass[i][j] && mass[i][j] != 0)
                    sumK += 1;
        }
        ++j1;
        if (j1 == 4)
        {
            j1 = 0;
            ++i1;
        }
   
    }
    return (sumK % 2 == 0 && i0 % 2 != 0);
        
}

std::array<std::array<int, 4>, 4> startGame(int& i0, int& j0) {
    //подготовка к работе нач//
    std::array<std::array<int, 4>, 4> mass;
    int i = 0;
    int j = 0;
    int k = 0;
    int i14{}, j14{}, i15{}, j15{};
    std::string s = "0123456789ABCDEF";
    std::srand(std::time(0));

    //рандомно встряхиваем строку//
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(s.begin(), s.end(), g);

    //заполняем массив значением -1//
    for (int i = 0; i < 4; i++)
        for (int j = 0; i < 4; i++)
            mass[i][j] = -1;

    //заполняем массив (подготавливаем стартовое поле)//
    for (const char ch : s) {
        //переводим числа из 16сс в 10сс//
        switch (ch) {
        case '0': k = 0; break;
        case '1': k = 1; break;
        case '2': k = 2; break;
        case '3': k = 3; break;
        case '4': k = 4; break;
        case '5': k = 5; break;
        case '6': k = 6; break;
        case '7': k = 7; break;
        case '8': k = 8; break;
        case '9': k = 9; break;
        case 'A': k = 10; break;
        case 'B': k = 11; break;
        case 'C': k = 12; break;
        case 'D': k = 13; break;
        case 'E': k = 14; break;
        case 'F': k = 15; break;
        default:
            std::cout << "chislo is undefined" << "\n";
            break;
        }
        //полученное число в 10сс из строки вписываем в массив//
        mass[i][j] = k;
        if (k == 0) {
            i0 = i;
            j0 = j;
        }
        if (k == 14) {
            i14 = i;
            j14 = j;
        }
        if (k == 15) {
            i15 = i;
            j15 = j;
        }
        j++;
        //переход на новую строку массива//
        if (j == 4) {
            j = 0;
            i++;
        }
    }

    if (!isCorrect(mass, i0))
        std::swap(mass[i15][j15], mass[i14][j14]);
   
    return mass;
}

void printGame(const std::array<std::array<int, 4>, 4>& mass) {
    system("cls");

    std::cout << "Игра пятнашки. Нажимайте стрелки, чтобы передвигать пустую клетку. Удачи!\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n"
                     "*           *           *           *           *\n";

        for (int j = 0; j < 4; ++j) {
            if (mass[i][j] == 0)
                std::cout << "*           ";
            else if (mass[i][j] >= 10)
                std::cout << "*     " << mass[i][j] << "    ";
            else
                std::cout << "*     " << mass[i][j] << "     ";
        }
        std::cout << "*\n"
                     "*           *           *           *           *\n";
    }
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
}
