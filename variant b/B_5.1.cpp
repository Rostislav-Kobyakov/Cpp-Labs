#include <iostream>
using namespace std;
void sum_k2(unsigned int factorial, unsigned int factorial_2, unsigned int k, float x, double &sum_k)
{
	factorial *= k;
	factorial_2 *= k + 1;
	sum_k = (pow(-1, k) / (factorial * factorial_2)) * pow(x / 2, 2 * k + 1);
	//return sum_k;
}

int main()
{
	double E = 10e-6, sum = 0, sum_k = 0;
	unsigned int factorial = 1, factorial_2 = 2, k;
	float x;
	cout << "Enter x: " << endl;
	cin >> x;
	if (x > 0 && x < 1)
	{
		for (k = 1; ; k++)
		{
			sum_k2(k, k + 1, k, x, sum_k);
			if (fabs(sum_k) <= E)
				break;
			sum += sum_k;
		}
		cout << "sum is " << sum << endl << "number of iterations: " << k - 1 << endl;
	}
	else cout << "error";
	return 0;
}

