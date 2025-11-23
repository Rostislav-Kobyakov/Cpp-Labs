#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void SwapLines(int line1, int line2, double** a)
{
    double* tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}

// Прямой ход
void forwardGauss(double** matrix, const int N = 3, const int M = 4)
{
    for (int i = 0; i < N; ++i) {
        // Находим строку с главным элементом (pivotRow - строка с максимальным элементом в текущем столбце, maxValue - значение максимального элемента)
        int pivotRow = i;
        double maxValue = abs(matrix[i][i]);
        //ищем элемент с наибольшим абсолютным значением
        for (int j = i + 1; j < N; ++j) {
            if (abs(matrix[j][i]) > maxValue) {
                pivotRow = j;
                maxValue = abs(matrix[j][i]);
            }
        }

        //меняем строки местами
        SwapLines(i, pivotRow, matrix);
        //проверяем что макс элемент не равен 0 чтоб не делить на 0
        if (maxValue == 0) {
            cerr << "Решение невозможно." << endl;
            exit(EXIT_FAILURE);
        }
        // Приводим главный элемент к единице путем деления всей строки на значение главного элемента
        double mainElement = matrix[i][i];
        for (int j = i; j <= M; ++j) {
            matrix[i][j] /= mainElement;
        }
        //зануляем элементы ниже главного элемента
        for (int j = i + 1; j < N; j++) {
            double coef = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= M; k++)
                matrix[j][k] -= coef * matrix[i][k];
        }
    }
}

// Обратный ход
void backwardGauss(double** matrix, double* x, const int N = 3, const int M = 4)
{
    x[N - 1] = matrix[N - 1][M - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int k = i + 1; k < N; k++)
        {
            sum += matrix[i][k] * x[k];
        }
        x[i] = matrix[i][M - 1] - sum;
    }
}

// Вычисление относительной погрешности delta = ||x~~ - x~|| / ||x~||
double relativeError(double* x_exact, double* x_approx, const int N)
{
    double norm_x_exact = 0;
    double norm_difference = 0;

    for (int i = 0; i < N; ++i)
    {
        double diff = x_exact[i] - x_approx[i];
        norm_difference += diff * diff;
        norm_x_exact += x_exact[i] * x_exact[i];
    }

    norm_x_exact = sqrt(norm_x_exact);
    double delta = sqrt(norm_difference) / norm_x_exact;

    return delta;
}

void outputMatrix(double** matrix, const int N = 3, const int M = 4)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << setw(10) << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 3, M = 4;

    double** arr = new double* [N];

    arr[0] = new double[M] { 21.547, -95.510, -96.121, -49.930 };
    arr[1] = new double[M] { 10.223, -91.065, -7.343, -12.465 };
    arr[2] = new double[M] { 51.218, 12.264, 86.457, 60.812 };

    double** arr_copy = new double* [N];

    arr_copy[0] = new double[M] {21.547, -95.510, -96.121, -49.930 };
    arr_copy[1] = new double[M] { 10.223, -91.065, -7.343, -12.465 };
    arr_copy[2] = new double[M] { 51.218, 12.264, 86.457, 60.812 };

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    outputMatrix(arr, N, M);

    double** matrix = new double* [N];
    matrix = arr;
    // Прямой ход
    forwardGauss(matrix, N, M);

    // Вывод преобразованной матрицы
    cout << "Преобразованная матрица:" << endl;
    outputMatrix(matrix, N, M);

    // Обратный ход
    double* x = new double[N];
    backwardGauss(matrix, x, N, M);

    cout << "Корни системы: " << endl;
    for (int i = 0; i < N; i++)
        cout << "x" << i+1 << " = " << x[i] << " " << endl;
    cout << endl;

    // Вектор невязки
    double* b = new double[N];
    for (int i = 0; i < N; i++)
    {
        double s = 0;
        for (int j = 0; j < N; j++)
        {
            s += arr_copy[i][j] * x[j];
            cout << s << setw(20);
        }
        b[i] = (arr_copy[i][N] - s);
        cout << "b" << i+1 << "=" << b[i] << " " << endl;
    }
    cout << endl;

    //Норма вектора невязки
    double norm = 0;
    for (int i = 0; i < N; i++)
    {
        norm += b[i]*b[i];
    }
    norm = sqrt(norm);
    cout << "Норма вектора невязки: " << norm << endl << endl;

    // Создание вспомогательной матрицы
    double** augmented_matrix = new double* [N];
    for (int i = 0; i < N; ++i)
    {
        augmented_matrix[i] = new double[M];

        for (int j = 0; j < M; ++j)
        {
            augmented_matrix[i][j] = arr_copy[i][j];
        }
        augmented_matrix[i][M-1] = x[i];  // Добавление свободного члена в последний столбец
    }
    // Вывод вспомогательной матрицы
    cout << "Исходная вспомогательная матрица:" << endl;
    outputMatrix(augmented_matrix, N, M);

    // Прямой ход Гаусса для вспомогательной матрицы
    forwardGauss(augmented_matrix, N, M);

    // Обратный ход Гаусса для вспомогательной матрицы
    double* x_approx = new double[N];
    backwardGauss(augmented_matrix, x_approx, N, M);

    // Вывод преобразованной вспомогательной матрицы
    cout << "Преобразованная вспомогательная матрица:" << endl;
    outputMatrix(augmented_matrix, N, M);

    // Вывод решения вспомогательной системы
    cout << "Решение вспомогательной матрицы:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "x_approx[" << i + 1 << "] = " << x_approx[i] << endl;
    }

    // Вычисление относительной погрешности для вспомогательной матрицы
    double delta = relativeError(x, x_approx, N);
    cout << "Относительная погрешность delta = " << delta << endl;

    // Освобождение памяти
    delete[] matrix;
    delete[] augmented_matrix;
    delete[] arr_copy;
    delete[] x;
    delete[] b;
    delete[] x_approx;

    return 0;
}