#include <iostream>
#include "MatrixUtils.h"

using namespace std;

template <>
void Print<int>(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Ёлемненты массива:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}
template <>
void Print<double>(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
template <>
void Print<char>(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

template void Print<char>(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template void Print<double>(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template void Print<int>(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <>
void FillRand<int>(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % max;
        }
    }
}
template <>
void FillRand<double>(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (double)rand() / RAND_MAX * max;
        }
    }
}
template <>
void FillRand<char>(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 'a' + rand() % 26;
        }
    }
}

template void FillRand<int>(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max);
template void FillRand<double>(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max);
template void FillRand<char>(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max);