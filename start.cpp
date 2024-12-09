#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;
#include <string>

array<array<int, 4>, 4> startGame(int& i0, int& j0) {
    //подготовка к работе нач//
    array<array<int, 4>, 4> mass;
    int i = 0;
    int j = 0;
    int k = 0;
    string s = "0123456789ABCDEF";
    std::srand(std::time(0));

    //рандомно встряхиваем строку//
    random_shuffle(s.begin(), s.end());


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
            cout << "chislo is undefined" << "\n";
            break;
        }
        //полученное число в 10сс из строки вписываем в массив//
        mass[i][j] = k;
        if (k == 0) {
            i0 = i;
            j0 = j;
        }
        j++;
        //переход на новую строку массива//
        if (j == 4) {
            j = 0;
            i++;
        }
    }
    return mass;
}

//void printGame(const array<array<int, 4>, 4>& mass) {
//
//
//    int o = 0;
//    int p = 0;
//
//    //рисуем поле, выводим значения//
//    for (int o = 0; o < 4; o++) {
//        //* * * * *...//
//        for (int i = 0; i < 5; i++) cout << "* * * * * ";
//        cout << endl;
//        //*   *    *    *    *//
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*" << endl;
//
//        //  * 1 * 2 * 3 * 4 * //
//        cout << "*";
//        if (mass[o][p] > 9) {
//            for (int i = 0; i < 4; i++)cout << " ";
//            cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        else {
//            for (int i = 0; i < 5; i++)cout << " ";
//            if (mass[o][p] == 0)
//                cout << " ";
//            else
//                cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//
//        }
//        p++; //сдвиг столбца массива//
//        if (mass[o][p] > 9) {
//            for (int i = 0; i < 4; i++)cout << " ";
//            cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        else {
//            for (int i = 0; i < 5; i++)cout << " ";
//            if (mass[o][p] == 0)
//                cout << " ";
//            else
//                cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        p++; //сдвиг столбца массива//
//        if (mass[o][p] > 9) {
//            for (int i = 0; i < 4; i++)cout << " ";
//            cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        else {
//            for (int i = 0; i < 5; i++)cout << " ";
//            if (mass[o][p] == 0)
//                cout << " ";
//            else
//                cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        p++; //сдвиг столбца массива//
//        if (mass[o][p] > 9) {
//            for (int i = 0; i < 4; i++)cout << " ";
//            cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//        }
//        else {
//            for (int i = 0; i < 5; i++)cout << " ";
//            if (mass[o][p] == 0)
//                cout << " ";
//            else
//                cout << mass[o][p];
//            for (int i = 0; i < 5; i++)cout << " ";
//            cout << "*";
//
//        }
//        p = 0; //начинаем с 0, тк переходим на новую строку массива//
//        cout << endl;
//
//
//
//
//        //_____//
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*";
//        for (int i = 0; i < 11; i++)cout << " ";
//        cout << "*" << endl;
//
//
//
//        //-------------------------------//
//    }
//    for (int i = 0; i < 5; i++)cout << "* * * * * ";
//    cout << endl;
//}

void printGame(const array<array<int, 4>, 4>& mass) {
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