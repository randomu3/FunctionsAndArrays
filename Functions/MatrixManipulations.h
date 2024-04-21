#pragma once

#define MAX_COLS 10
#define MAX_ROWS 10

template <typename T>
void shiftLeft(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            T temp = arr[i][0];
            for (int j = 0; j < cols - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = temp;
        }
    }
}
template <typename T>
void shiftRight(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            T temp = arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
}
template <typename T>
void Sort(T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    T temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}
template <typename T>
void Unique(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, T max);