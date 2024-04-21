#include <iostream>
#include <cstdlib>
#include <map>

#define DEFAULT_MAX_VALUE 10
#define MAX_COLS 10
#define MAX_ROWS 10

using namespace std;

template <typename T>
void Search(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
void FillRand(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, T max = DEFAULT_MAX_VALUE);
template <>
void FillRand(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max);
template <>
void FillRand(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max);
template <>
void FillRand(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max);

template <typename T>
void Print(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template <>
void Print(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template <>
void Print(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
template <>
void Print(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
T Sum(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
double Avg(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
T minValueIn(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
T maxValueIn(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
void shiftLeft(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);

template <typename T>
void shiftRight(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);

template <typename T>
void Sort(T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

template <typename T>
void Unique(T arr[MAX_ROWS][MAX_COLS], int rows, int cols, T max);
template <>
void Unique<int>(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max);
template <>
void Unique<double>(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max);
template <>
void Unique<char>(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, char max);

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

template <>
void Print<int>(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Элемненты массива:\n";
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