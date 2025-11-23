#include <iostream>
#include <cmath>
#include <iomanip>

// Уравнения
double equation1(double x1, double x2) {
    return 1.5 * pow(x1, 3) - pow(x2, 2) - 1.0;
}

double equation2(double x1, double x2) {
    return x1 * pow(x2, 3) - x2 - 4.0;
}

// Производные по x1 и x2 для уравнений (аналитический метод)
void analyticalJacobian(double x1, double x2, double& j11, double& j12, double& j21, double& j22) {
    j11 = 4.5 * pow(x1, 2);
    j12 = -2 * x2;
    j21 = pow(x2, 3);
    j22 = 3 * x1 * pow(x2, 2) - 1;
}

// Производные по x1 и x2 для уравнений (численный метод)
void numericalJacobian(double x1, double x2, double h, double& j11, double& j12, double& j21, double& j22) {
    j11 = (equation1(x1 + h, x2) - equation1(x1, x2)) / h;
    j12 = (equation1(x1, x2 + h) - equation1(x1, x2)) / h;
    j21 = (equation2(x1 + h, x2) - equation2(x1, x2)) / h;
    j22 = (equation2(x1, x2 + h) - equation2(x1, x2)) / h;
}

// Решение СНАУ методом Ньютона
void newtonMethod(double& x1, double& x2, double E1, double E2, int NIT, double M, bool useAnalyticalJacobian) {
    int k = 1;

    std::cout << std::setw(5) << "Iter" << std::setw(15) << "x1" << std::setw(15) << "x2" << std::setw(15) << "d1" << std::setw(15) << "d2" << std::endl;

    while (true) {
        double f1 = equation1(x1, x2);
        double f2 = equation2(x1, x2);

        double j11, j12, j21, j22;

        if (useAnalyticalJacobian) {
            analyticalJacobian(x1, x2, j11, j12, j21, j22);
        }
        else {
            double h = 1e-5;
            numericalJacobian(x1, x2, h, j11, j12, j21, j22);
        }

        double detJ = j11 * j22 - j12 * j21;

        if (std::abs(detJ) < 1e-9) {
            std::cout << "Newton's method failed: Jacobian determinant is close to zero." << std::endl;
            return;
        }

        double dx1 = (-j22 * f1 + j12 * f2) / detJ;
        double dx2 = (j21 * f1 - j11 * f2) / detJ;

        x1 += M * dx1;
        x2 += M * dx2;

        double d1 = std::fabs(M * dx1);
        double d2 = std::fabs(M * dx2);

        std::cout << std::setw(5) << k << std::setw(15) << x1 << std::setw(15) << x2 << std::setw(15) << d1 << std::setw(15) << d2 << std::endl;

        if (d1 < E1 && d2 < E2) {
            std::cout << "Converged to solution: x1 = " << x1 << ", x2 = " << x2 << std::endl;
            break;
        }

        if (k >= NIT) {
            std::cout << "Maximum number of iterations reached." << std::endl;
            break;
        }

        k++;
    }
}

int main() {
    double x1 = 1.0;
    double x2 = 1.0;
    double E1 = 1e-9;
    double E2 = 1e-9;
    int NIT = 500;

    std::cout << "Using Analytical Jacobian:" << std::endl;
    newtonMethod(x1, x2, E1, E2, NIT, 0.01, true);
    std::cout << std::endl;
    x1 = 1;
    x2 = 1;
    std::cout << "Using Numerical Jacobian:" << std::endl;
    newtonMethod(x1, x2, E1, E2, NIT, 0.01, false);
    std::cout << std::endl;
    x1 = 1;
    x2 = 1;
    std::cout << "Comparison for different M values:" << std::endl;
    for (double M : {0.01, 0.05, 0.1}) {
        std::cout << "M = " << M << ":" << std::endl;
        std::cout << "1" << std::endl;
        newtonMethod(x1, x2, E1, E2, NIT, M, true);
        std::cout << "2" <<std:: endl;
        newtonMethod(x1, x2, E1, E2, NIT, M, false);
        x1 = 1;
        x2 = 1;
        std::cout << std::endl;
    }

    return 0;
}
