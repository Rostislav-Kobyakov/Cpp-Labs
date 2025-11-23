#include <math.h>
#include <iostream>           //  cin cout

using namespace std;

void main()
{
	unsigned int n1 = 0;
	const int N = 200;
	bool a[N] = { 0 };
	// заполним все ячейки числом 1
	for (int i = 2; i < N; i++)
		a[i] = true;

	unsigned int n = sqrt(double(N));

	for (int i = 2; i <= n; i++)
		if (a[i]) // вычеркиваем (обнуляем) кратные числа
			for (int j = i * 2; j < N; j += i)
				a[j] = false;

	for (int i = N / 2 - 1; i+2 < N; i++)
		if (a[i] && a[i + 2])
		{
			n1 = i+2;
			cout << "simple number with +2: " << i << " " << n1 << endl;
		}
	cout << endl;
}