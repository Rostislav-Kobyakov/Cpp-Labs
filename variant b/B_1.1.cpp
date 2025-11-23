#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    int s, t;
    double x;
    cout << "Enter x" << endl;
    cin >> x;
    cout << "x = " << x << endl;
    cout << "Enter s" << endl;
    cin >> s;
    cout << "s = " << s << endl;
    cout << "Enter t" << endl;
    cin >> t;
    cout << "t = " << t << endl;
    double y;
    double _1_1;
    double _1_2;
    double _2_1;
    double _2_2;
    _1_1 = pow(x, 1 / t);
    _1_2 = atan(_1_1);
    _2_1 = log(x);
    _2_2 = sin(_2_1);
    if (x > 0 && (x * x + s * _2_2) != 0 && t != 0 && s != -(x * x / _2_2) && _2_2)
    {
        y = _1_2 / (x * x + s * _2_2);
        cout << "y = " << y << endl;
    }
    else cout << "check x" << endl;
    return 0;
}

;
