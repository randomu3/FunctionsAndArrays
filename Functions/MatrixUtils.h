#include <iostream>
#include <map>
#pragma once

using namespace std;

#define DEFAULT_MAX_VALUE 10
#define MAX_COLS 10
#define MAX_ROWS 10

template <typename T>
void FillRand(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, T max = DEFAULT_MAX_VALUE);
template <typename T>
void Print(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template <typename T>
void Search(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    map<T, int> count_map;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count_map[arr[i][j]]++;
        }
    }

    cout << "Повторяющиеся элементы:\n";
    for (const auto& element : count_map) {
        if (element.second > 1) {
            cout << element.first << " встречается " << element.second << " раз(а)\n";
        }
    }
}