#include <iostream>
#include "MatrixManipulations.h"

using namespace std;

template <>
void Unique<int>(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max) {
    if (rows * cols > max) {
        cout << "Ошибка: невозможно заполнить массив уникальными числами, так как количество элементов превышает максимально возможное значение." << endl;
        return;
    }

    int filled = 0;
    while (filled < rows * cols) {
        int random_number = rand() % max;
        bool already_exists = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == random_number) {
                    already_exists = true;
                    break;
                }
            }
            if (already_exists) {
                break;
            }
        }

        if (!already_exists) {
            int rowIndex = filled / cols;
            int colIndex = filled % cols;
            arr[rowIndex][colIndex] = random_number;
            filled++;
        }
    }
}
template <>
void Unique<double>(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max) {
    if (rows * cols > max) {
        cout << "Ошибка: невозможно заполнить массив уникальными числами, так как количество элементов превышает максимально возможное значение." << endl;
        return;
    }

    int filled = 0;
    while (filled < rows * cols) {
        double random_number = (double)(rand()) / RAND_MAX * max;
        random_number = floor(random_number);
        bool already_exists = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((int)arr[i][j] == (int)random_number) {
                    already_exists = true;
                    break;
                }
            }
            if (already_exists) {
                break;
            }
        }

        if (!already_exists) {
            int rowIndex = filled / cols;
            int colIndex = filled % cols;
            arr[rowIndex][colIndex] = random_number;
            filled++;
        }
    }
}
template <>
void Unique<char>(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max) {
    if (rows * cols > 26) {
        cout << "Ошибка: невозможно заполнить массив уникальными буквами." << endl;
        return;
    }

    int filled = 0;
    while (filled < rows * cols) {
        char random_char = 'a' + rand() % 26;
        bool already_exists = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == random_char) {
                    already_exists = true;
                    break;
                }
            }
            if (already_exists) {
                break;
            }
        }

        if (!already_exists) {
            int rowIndex = filled / cols;
            int colIndex = filled % cols;
            arr[rowIndex][colIndex] = random_char;
            filled++;
        }
    }
}

template void Unique<int>(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max);
template void Unique<double>(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max);
template void Unique<char>(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max);