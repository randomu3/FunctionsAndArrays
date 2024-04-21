#include <iostream>
#include <cstdlib>
#include <map>
#include "MatrixUtils.h"
#include "MatrixStats.h"
#include "MatrixManipulations.h"

#define DEFAULT_MAX_VALUE 10

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 5;
    const int cols = 10;
    int i_arr[rows][cols];
    //double d_arr[rows][cols];
    //char ch_arr[rows][cols];

    FillRand(i_arr, rows, cols, DEFAULT_MAX_VALUE);
    Print(i_arr, rows, cols);

    Search(i_arr, rows, cols);

    cout << "Сумма: " << Sum(i_arr, rows, cols) << endl;
    cout << "Среднее значение: " << Avg(i_arr, rows, cols) << endl;
    cout << "Минимальное значение: " << minValueIn(i_arr, rows, cols) << endl;
    cout << "Максимальное значение: " << maxValueIn(i_arr, rows, cols) << endl;

    Sort(i_arr, rows, cols);
    Print(i_arr, rows, cols);

    shiftLeft(i_arr, rows, cols, 3);
    Print(i_arr, rows, cols);

    shiftRight(i_arr, rows, cols, 3);
    Print(i_arr, rows, cols);

    Unique(i_arr, rows, cols, 60);
    Print(i_arr, rows, cols);

    return 0;
}