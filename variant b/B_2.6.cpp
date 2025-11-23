#include <iostream>
using namespace std;
int main()
{
	double y, x0 = 1, xm = 5, dx = 0.5, a = 1;
	int i;
	cout << "enter n" << endl;
	cin >> i;
	for (; x0 <= xm;)
	{
		int sum = 0, pr = 0;
		//обычный прикол
		y = 0;
		int n = i;
		for (; n > 0;)
		{
			y = y + (2 * n - 1) * pow(x0, (2 * n - 1));
			++sum;
			pr = pr + 2 * n;
			--n;
		}
		y += 10;
		++sum;
		cout << "x = " << x0 << endl << "y = " << y << endl << "sum = " << sum << " " << "proizvedenie = " << pr << endl;
		//схема горнера
		sum = 0;
		pr = 0;
		double result;
		int dwaPower;
		n = i;
		result = 2 * n - 1;
		dwaPower = 2 * n - 1;
		for (; n > 1; n--)
		{
			dwaPower -= 2;
			result = result * x0 * x0 + dwaPower;
			sum = sum + 1;
			pr = pr + 2;
		}
		result *= x0;
		result += 10;
		++pr;
		++sum;
		cout <<"horner = " << result << endl << "sum = " << sum << " " << "proizvedenie = " << pr << endl;

		x0 += dx;
	}
	return 0;
}
