#include <iostream>
using namespace std;
int main()
{
	unsigned int n, n1 = 0;
	cout << "enter n" << endl;
	cin >> n;
	cout << endl;
	unsigned int double_n = n * 2 - 1;
	for (;n <= double_n ;n++)
	{
		bool pr = true;
		for (int k = 2, pr = true; (k <= sqrt(n) && pr); k++)
		{
			if (!(n % k))
			{
				pr = false;
				break;
			}
			else
			{
				if (n1 + 2 == n)
				cout << "simple numbers with +2: " << n1 << " " << n << endl;
				n1 = n;
				break;
			}
		}
	}
	return 0;
}
