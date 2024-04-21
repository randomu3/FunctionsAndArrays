#include <iostream>
#include <cstdlib>
#include <map>

#define DEFAULT_MAX_VALUE 10
#define MAX_COLS 10
#define MAX_ROWS 10

using namespace std;

template <typename T>
void Search(const T arr[MAX_ROWS][MAX_COLS], int rows, int cols);

void FillRand(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max = DEFAULT_MAX_VALUE);
void Print(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int Sum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int minValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int maxValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void Sort(int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void Unique(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max = DEFAULT_MAX_VALUE);

void FillRand(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max = DEFAULT_MAX_VALUE);
void Print(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Sum(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double minValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double maxValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void Sort(double arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void Unique(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max = DEFAULT_MAX_VALUE);

void FillRand(char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void Print(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
int Sum(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
double Avg(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
char minValueIn(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
char maxValueIn(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void shiftLeft(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void shiftRight(char arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift);
void Sort(char arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void Unique(char arr[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 5;
    const int cols = 10;
    int i_arr[rows][cols];
    //double d_arr[rows][cols];
    //char ch_arr[rows][cols];

    FillRand(i_arr, rows, cols);
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

void FillRand(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % max;
        }
    }
}

void FillRand(char arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 'a' + rand() % 26;
        }
    }
}

void Print(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Элемненты массива:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Print(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void Print(const char arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int Sum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

double Sum(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int Sum(const char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += ch_arr[i][j];
        }
    }
    return sum;
}

double Avg(const int i_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    return Sum(i_arr, rows, cols) / (double)(rows * cols);
}

double Avg(const double d_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    return Sum(d_arr, rows, cols) / (rows * cols);
}

double Avg(const char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    return Sum(ch_arr, rows, cols) / (double)(rows * cols);
}

int minValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

int maxValueIn(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

double minValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

char minValueIn(const char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

double maxValueIn(const double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

char maxValueIn(const char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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

void shiftLeft(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void shiftLeft(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void shiftLeft(char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void shiftRight(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void shiftRight(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void shiftRight(char ch_arr[MAX_ROWS][MAX_COLS], int rows, int cols, int shift) {
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

void Sort(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

void Sort(double arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    double temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

void Sort(char arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    char temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

void Unique(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int max) {
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

void Unique(double arr[MAX_ROWS][MAX_COLS], int rows, int cols, double max) {
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

void Unique(char arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
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