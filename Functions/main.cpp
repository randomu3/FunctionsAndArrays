#include <iostream>
#include <cstdlib>

using namespace std;

void FillRand(int arr[], const int n); // заполн€ет массив случайными числами
void Print(const int arr[], const int n); // выводит массив на экран
int Sum(const int arr[], const int n); // возвращает сумму элементов массива
double Avg(const int arr[], const int n); // возвращает среднее-арифметическое элементов массива
int minValueIn(const int arr[], const int n); // возвращает минимальное значение в массиве
int maxValueIn(const int arr[], const int n); // возвращает максимальное значение в массиве
void shiftLeft(int arr[], const int n, int shift); // циклически сдвигает массив на заданное число элементов влево
void shiftRight(int arr[], const int n, int shift); // циклически сдвигает массив на заданное число элементов вправо


int main() {
    const int n = 10;
    int arr[n];

    FillRand(arr, n);
    Print(arr, n);

    cout << "Sum: " << Sum(arr, n) << endl;
    cout << "Avg: " << Avg(arr, n) << endl;
    cout << "Min: " << minValueIn(arr, n) << endl;
    cout << "Max: " << maxValueIn(arr, n) << endl;

    shiftLeft(arr, n, 3);
    Print(arr, n);

    shiftRight(arr, n, 3);
    Print(arr, n);

    return 0;
}

void FillRand(int arr[], const int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void Print(const int arr[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Sum(const int arr[], const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double Avg(const int arr[], const int n) {
    return (double)Sum(arr, n) / n;
}

int minValueIn(const int arr[], const int n) {
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
    }
    return min_val;
}

int maxValueIn(const int arr[], const int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

void shiftLeft(int arr[], const int n, int shift) {
    shift %= n;
    for (int i = 0; i < shift; i++) {
        int temp = arr[0];
        for (int j = 1; j < n; j++) {
            arr[j - 1] = arr[j];
        }
        arr[n - 1] = temp;
    }
}

void shiftRight(int arr[], const int n, int shift) {
    shift %= n; 
    int temp;
    for (int i = 0; i < shift; i++) {
        temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}