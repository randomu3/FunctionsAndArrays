#include <iostream>
#include <cstdlib>

#define DEFAULT_MAX_VALUE 10
#define MAX_COLS 10
#define MAX_ROWS 10

using namespace std;

// Функции для работы с массивами типа int
void FillRand(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max = DEFAULT_MAX_VALUE);
void Print(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int Sum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int minValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int maxValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);

// Перегрузки для двумерных массивов типа double
void FillRand(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max = DEFAULT_MAX_VALUE);
void Print(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Sum(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double minValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double maxValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);

// Перегрузки для двумерных массивов типа double
void FillRand(char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void Print(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Sum(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double minValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double maxValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 5;
    const int cols = 10;
    int i_arr[rows][cols];
    double d_arr[rows][cols];
    char ch_arr[rows][cols];

    FillRand(i_arr, rows, cols);
    Print(i_arr, rows, cols);

    cout << "Сумма: " << Sum(i_arr, rows, cols) << endl;
    cout << "Среднее значение: " << Avg(i_arr, rows, cols) << endl;
    cout << "Минимальное значение: " << minValueIn(i_arr, rows, cols) << endl;
    cout << "Максимальное значение: " << maxValueIn(i_arr, rows, cols) << endl;

    shiftLeft(i_arr, rows, cols, 3);
    Print(i_arr, rows, cols);

    shiftRight(i_arr, rows, cols, 3);
    Print(i_arr, rows, cols);

    return 0;
}

void FillRand(int arr[][MAX_COLS], int rows, int cols, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % max;
        }
    }
}

void FillRand(char arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 'a' + rand() % 26;
        }
    }
}

void Print(const int arr[][MAX_COLS], int rows, int cols) {
    cout << "Элемненты массива:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Print(const double arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void Print(const char arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int Sum(const int arr[][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

double Sum(const double arr[][MAX_COLS], int rows, int cols) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int Sum(const char ch_arr[][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += ch_arr[i][j];
        }
    }
    return sum;
}

double Avg(const int i_arr[][MAX_COLS], int rows, int cols) {
    return Sum(i_arr, rows, cols) / (double)(rows * cols);
}

double Avg(const double d_arr[][MAX_COLS], int rows, int cols) {
    return Sum(d_arr, rows, cols) / (rows * cols);
}

double Avg(const char ch_arr[][MAX_COLS], int rows, int cols) {
    return Sum(ch_arr, rows, cols) / (double)(rows * cols);
}

int minValueIn(const int arr[][MAX_COLS], int rows, int cols) {
    int min_val = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
            }
        }
    }
    return min_val;
}

double minValueIn(const double arr[][MAX_COLS], int rows, int cols) {
    double min_val = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
            }
        }
    }
    return min_val;
}

char minValueIn(const char ch_arr[][MAX_COLS], int rows, int cols) {
    char min_val = ch_arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (ch_arr[i][j] < min_val) {
                min_val = ch_arr[i][j];
            }
        }
    }
    return min_val;
}

int maxValueIn(const int arr[][MAX_COLS], int rows, int cols) {
    int max_val = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }
    }
    return max_val;
}

double maxValueIn(const double arr[][MAX_COLS], int rows, int cols) {
    double max_val = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }
    }
    return max_val;
}

char maxValueIn(const char ch_arr[][MAX_COLS], int rows, int cols) {
    char max_val = ch_arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (ch_arr[i][j] > max_val) {
                max_val = ch_arr[i][j];
            }
        }
    }
    return max_val;
}

void shiftLeft(int arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            int temp = arr[i][0];
            for (int j = 0; j < cols - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = temp;
        }
    }
}

void shiftLeft(double arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            double temp = arr[i][0];
            for (int j = 0; j < cols - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = temp;
        }
    }
}

void shiftLeft(char ch_arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            char temp = ch_arr[i][0];
            for (int j = 0; j < cols - 1; j++) {
                ch_arr[i][j] = ch_arr[i][j + 1];
            }
            ch_arr[i][cols - 1] = temp;
        }
    }
}

void shiftRight(int arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            int temp = arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
}

void shiftRight(double arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            double temp = arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
}

void shiftRight(char ch_arr[][MAX_COLS], int rows, int cols, int shift) {
    for (int k = 0; k < shift; k++) {
        for (int i = 0; i < rows; i++) {
            char temp = ch_arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                ch_arr[i][j] = ch_arr[i][j - 1];
            }
            ch_arr[i][0] = temp;
        }
    }
}