#pragma once

#define MAX_COLS 10
#define MAX_ROWS 10

template <typename T>
T Sum(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    T sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}
template <typename T>
double Avg(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    double sum = (double)(Sum(arr, rows, cols));
    return sum / (rows * cols);
}
template <typename T>
T minValueIn(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    T min_val = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
            }
        }
    }
    return min_val;
}
template <typename T>
T maxValueIn(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    T max_val = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }
    }
    return max_val;
}