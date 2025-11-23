#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x0 = -2, xn = 2, dx = 0.2, y = 0,y1 = 0, y_c, e = 10e-6;
	for (;x0 <= xn;)
	{
		int fact = 1;
		int i = 1;
			do
			{
				y1 = pow(x0, i) / fact;
				if (i % 2 == 0)
					y += y1;
				else
					y -= y1;
				++i;
				fact = fact * i;
			}while (abs(y1) >= e);
		y_c = exp(-x0) - 1;
		cout << "xi = " << x0 << endl;
		cout << "y = " << y << endl;
		cout << "c++ function = " << y_c << endl << endl;
		x0 += dx;
		y = 0;
	}

	return 0;

}
