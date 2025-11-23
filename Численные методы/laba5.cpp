#include <iostream>
#include <cmath>
using namespace std;

double integrand1D(double x) {
    return sqrt(1 + 2 * pow(x, 3));
}

double trapezoidalRule1D(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (integrand1D(a) + integrand1D(b));

    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += integrand1D(x_i);
    }

    return h * sum;
}

double simpsonsRule1D(double a, double b, int n) {
    if (n % 2 != 0) {
        std::cerr << "Error: Number of subintervals must be even for Simpson's rule." << std::endl;
        return 0.0;
    }

    double h = (b - a) / n;
    double sum = integrand1D(a) + integrand1D(b);

    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += (i % 2 == 0) ? 2 * integrand1D(x_i) : 4 * integrand1D(x_i);
    }

    return h / 3.0 * sum;
}

// Подынтегральная функция для интеграла функции двух переменных
double integrand2D(double x, double y) {
    return x * x + 2 * y;
}

// Метод Симпсона для интеграла функции двух переменных
double simpsonsRule2D(double a, double b, double c, double d, int nx, int ny, double (*f)(double, double)) {
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;
    double sum = 0.0;

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            double x_i = a + i * hx + 0.5 * hx;
            double y_j = c + j * hy + 0.5 * hy;

            sum += f(x_i, y_j);
        }
    }

    return hx * hy * sum;
}

bool convergenceCriterionTrapezoidal(double Ih, double Ih_half, double epsilon) {
    return std::fabs(Ih_half - Ih) <= 3 * epsilon;  // Критерий (5.4) для метода трапеций
}

bool convergenceCriterionSimpson(double Ih, double Ih_half, double epsilon) {
    return std::fabs(Ih_half - Ih) <= 15 * epsilon;  // Критерий (5.6) для метода Симпсона
}

int main() {
    double a_1D = 1.2;
    double b_1D = 2.471;  // Измененный интервал
    double epsilon1 = 1e-4;
    double epsilon2 = 1e-5;

    // Интегрирование методом трапеций с точностью E-4
    double Ih_1D, Ih_half_1D;
    int n_1D = 2;

    do {
        Ih_1D = trapezoidalRule1D(a_1D, b_1D, n_1D);
        Ih_half_1D = trapezoidalRule1D(a_1D, b_1D, 2 * n_1D);

        // Увеличение числа интервалов
        n_1D *= 2;
    } while (!convergenceCriterionTrapezoidal(Ih_1D, Ih_half_1D, epsilon1));

    std::cout << "Trapezoidal Rule converged for n = " << n_1D << " with epsilon = " << epsilon1 << std::endl;
    std::cout << "Result (1D): " << Ih_half_1D << std::endl;

    // Интегрирование методом трапеций с точностью E-5
    do {
        Ih_1D = trapezoidalRule1D(a_1D, b_1D, n_1D);
        Ih_half_1D = trapezoidalRule1D(a_1D, b_1D, 2 * n_1D);

        // Увеличение числа интервалов
        n_1D *= 2;
    } while (!convergenceCriterionTrapezoidal(Ih_1D, Ih_half_1D, epsilon2));

    std::cout << "Trapezoidal Rule converged for n = " << n_1D << " with epsilon = " << epsilon2 << std::endl;
    std::cout << "Result (1D): " << Ih_half_1D << std::endl;

    // Интегрирование методом Симпсона с точностью E-4
    n_1D = 2;

    do {
        Ih_1D = simpsonsRule1D(a_1D, b_1D, n_1D);
        Ih_half_1D = simpsonsRule1D(a_1D, b_1D, 2 * n_1D);

        // Увеличение числа интервалов
        n_1D *= 2;
    } while (!convergenceCriterionSimpson(Ih_1D, Ih_half_1D, epsilon1));

    std::cout << "Simpson's Rule converged for n = " << n_1D << " with epsilon = " << epsilon1 << std::endl;
    std::cout << "Result (1D): " << Ih_half_1D << std::endl;

    // Интегрирование методом Симпсона с точностью E-5
    do {
        Ih_1D = simpsonsRule1D(a_1D, b_1D, n_1D);
        Ih_half_1D = simpsonsRule1D(a_1D, b_1D, 2 * n_1D);

        // Увеличение числа интервалов
        n_1D *= 2;
    } while (!convergenceCriterionSimpson(Ih_1D, Ih_half_1D, epsilon2));

    std::cout << "Simpson's Rule converged for n = " << n_1D << " with epsilon = " << epsilon2 << std::endl;
    std::cout << "Result (1D): " << Ih_half_1D << std::endl;

    // Интегрирование функции двух переменных методом Симпсона
    double a_2D = 0.0;
    double b_2D = 2.0;
    double c_2D = 0.0;
    double d_2D = 1.0;
    int nx_2D = static_cast<int>((b_2D - a_2D) / 1e-4);
    int ny_2D = static_cast<int>((d_2D - c_2D) / 1e-4);
    double result2D = simpsonsRule2D(a_2D, b_2D, c_2D, d_2D, nx_2D, ny_2D);

    std::cout << "Result of 2D Simpson's Rule: " << result2D << std::endl;

    return 0;
}