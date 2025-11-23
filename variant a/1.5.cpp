#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	double x, y;
	cout << "Enter x" << endl;
	cin >> x;
	if (x >= -9 && x <= -5)
	{
		y = acos((-x - 7) / 2);
		y = fabs(cos(y) * 1.5);
		cout << "y = " << y << endl;
		}
	else
		if (x >= -5 && x <= -4)
		{
			y = 1.5;
			cout << "y = " << y << endl;
		}
		else
			if (x >= -4 && x <= 0)
			{
				y = -x / 4 * 1.5;
				cout << "y = " << y << endl;
			}
			else
				if (x > 0 && x <= M_PI)
				{
					y = sin(x);
					cout << "y = " << y << endl;
				}
				else
					if (x >= M_PI && x <= 5)
					{
						y = x - M_PI;
						cout << "y = " << y << endl;
					}
					else
						cout << "x is not in domain of function" << endl;
	return 0;
}
