#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	double a = 2.8, w = 1, y1, y2, y3;
	for (double x = 1; x <= 2; x = x + 0.05)
	{
		if (x < 1.2)
		{
			y1 = a * x * x - 0.3 * x + 4;
			cout << "x < 1.2 " << endl << y1 << endl;
		}
		if (x == 1.2)
		{
			y2 = a / x + sqrt(x * x + 1);
			cout << "x = 1.2 " << endl << y2 << endl;

		}
		if (x > 1.2)
		{
			y3 = (a - 0.3 * x) / sqrt(x * x + 1);
			cout << "x > 1.2 " << endl << y3 << endl;

		}
		w = w + 1;
	}

	return 0;
}

