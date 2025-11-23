#include <iostream>
using namespace std;
int main()
{
	int n, factorial = 1;
	double x,sum, y = 1;
	cout << "enter n" << endl;
	cin >> n;
	cout << "enter x" << endl;
	cin >> x;
	if (n > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			factorial = factorial * i;
			for (int j = 1; j <= i; j++)
			{
				sum = x + j;
			}
			y = y * (factorial / sum);
		}
		cout << "y = " << y << endl;
	}
	else cout << "n is bad" << endl;
	return 0;
}
