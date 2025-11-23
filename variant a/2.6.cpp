#include <iostream>
using namespace std;
int main()
{
	unsigned int n, m, sum = 0, k;
	bool pr = true;
	cout << "enter n" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "enter number" << endl;
		cin >> m;
		int x = sqrt(i);
		for (k = 2, pr = true; (k <= x && pr); k++)
			if (i % k == 0)
				pr = false;
			else pr = true;
		if (pr == true)
		{
			sum = sum + m;
		}
	}
	cout << "sum is " << sum << endl;

	return 0;
}