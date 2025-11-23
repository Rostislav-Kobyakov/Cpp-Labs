#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// Функция для обмена строк
void SwapLines(int line1, int line2, vector<vector<double>>& a) {
    vector<double> tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}

// Прямой ход метода Гаусса
void forwardGauss(vector<vector<double>>& matrix, const int N, const int M) {
    for (int i = 0; i < N; ++i) {
        int pivotRow = i;
        double maxValue = abs(matrix[i][i]);

        for (int j = i + 1; j < N; ++j) {
            if (abs(matrix[j][i]) > maxValue) {
                pivotRow = j;
                maxValue = abs(matrix[j][i]);
            }
        }

        SwapLines(i, pivotRow, matrix);

        if (maxValue == 0) {
            cerr << "Решение невозможно." << endl;
            exit(EXIT_FAILURE);
        }

        double mainElement = matrix[i][i];
        for (int j = i; j <= M; ++j) {
            matrix[i][j] /= mainElement;
        }

        for (int j = i + 1; j < N; j++) {
            double coef = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= M; k++)
                matrix[j][k] -= coef * matrix[i][k];
        }
    }
}

// Обратный ход метода Гаусса
void backwardGauss(vector<vector<double>>& matrix, vector<double>& x, const int N, const int M) {
    x[N - 1] = matrix[N - 1][M];
    for (int i = N - 2; i >= 0; i--) {
        double sum = 0;
        for (int k = i + 1; k < N; k++) {
            sum += matrix[i][k] * x[k];
        }
        x[i] = matrix[i][M] - sum;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод табличных данных
    vector<double> H = { 0.164, 0.328, 0.656, 0.984, 1.312, 1.640 };
    vector<double> mu = { 0.448, 0.432, 0.421, 0.417, 0.414, 0.412 };

    int N = H.size();
    int m = 1; // степень аппроксимирующего полинома

    // Сформировать матрицу коэффициентов A размером (m+1)x(m+1)
    vector<vector<double>> A(m + 1, vector<double>(m + 2, 0.0));
    A[0][0] = N;
    for (int l = 1; l <= m; ++l) {
        for (int j = 1; j <= m + 1; ++j) {
            int k = l + j - 2;
            A[l][j] = accumulate(H.begin(), H.end(), 0.0, [l](double acc, double h) { return acc + pow(h, l); });
        }
    }

    // Сформировать правую часть системы
    vector<double> PRAW(m + 1, 0.0);
    for (int l = 0; l <= m; ++l) {
        PRAW[l] = accumulate(mu.begin(), mu.end(), 0.0, [l, &H](double acc, double mi) 
            { return acc + mi * pow(H[mi], l); });
    }

    // Добавить правые части к матрице коэффициентов
    for (int i = 0; i <= m; ++i) {
        A[i][m + 1] = PRAW[i];
    }

    // Прямой ход метода Гаусса
    forwardGauss(A, m + 1, m + 1);

    // Обратный ход метода Гаусса
    vector<double> coefficients(m + 1, 0.0);
    backwardGauss(A, coefficients, m + 1, m + 1);

    // Вывод коэффициентов
    cout << "Коэффициенты аппроксимации: ";
    for (int i = 0; i <= m; ++i) {
        cout << "a" << i << " = " << coefficients[i] << " ";
    }
    cout << endl;

    // Расчет дисперсии и среднеквадратического отклонения
    double sum_residuals = 0.0;
    for (int i = 0; i < N; ++i) {
        double predicted = coefficients[0];
        for (int j = 1; j <= m; ++j) {
            predicted += coefficients[j] * pow(H[i], j);
        }
        sum_residuals += pow(mu[i] - predicted, 2);
    }

    double variance = sum_residuals / (N - m - 1);
    double standard_deviation = sqrt(variance);

    cout << "Дисперсия: " << variance << endl;
    cout << "Среднеквадратическое отклонение: " << standard_deviation << endl;

    return 0;
}
