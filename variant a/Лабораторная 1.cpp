// Лабораторная 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main ()
{
    int x;
    cout << "Enter x" << endl;
    cin >> x;
    cout << "x = " << x << endl;
    double y;
    double _1_1;
    double _1_2;
    double _1_3;
    double _2_1;
    double _2_2;
    _1_1 = sin(x);
    _1_2 = pow(x, 2);
    _1_3 = exp(cos(x));
    _2_1 = log(pow(x , 2));
    _2_2 = sin(M_PI *(pow(x, 2)));
    y = sqrt(((_1_1 + _1_2 + _1_3, 2) + pow(_2_1 + _2_2,3)));
    cout << "y = " << y << endl;
    return 0;
}

;
