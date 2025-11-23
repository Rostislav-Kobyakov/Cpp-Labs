#include <iostream>
using namespace std;
int main()
{
	double nmbr;
	unsigned int k, nmbr_k, digit_k, n, sum = 0;
	cout << "enter nmbr" << endl;
	cin >> nmbr;
	cout << "enter k" << endl;
	cin >> k;
	cout << "enter n" << endl;
	cin >> n;
	if (nmbr > 0)
	{
		nmbr_k = int(nmbr * pow(10, k + n)); // нахождение цифр после запятой
		k = pow(10, n + 1); // столько после запятой цифр нада
		digit_k = nmbr_k % k * 10 / k; // цифра k
		for (int i = 1; i <= n; i++)
		{
			sum += nmbr_k % 10; // сумма n цифр после k
			nmbr_k /= 10;
		}
		if (sum == digit_k)
			cout << "True" << endl;
		else cout << "False" << endl;
	}
	else cout << "n is bad" << endl;
	return 0;

}

