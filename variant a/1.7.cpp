
#include <iostream>
using namespace std;
int main()
{
	int k, l, m, n;
	cout << "Enter k" << endl;
		cin >> k;
		if (k > 0 && k <= 8)
		{ }
		else cout << "k is bad!" << endl;
	cout << "Enter l" << endl;
		cin >> l;
		if (l > 0 && l <= 8)
		{ }
		else cout << "l is bad!" << endl;
	cout << "Enter m" << endl;
		cin >> m;
		if (m > 0 && m <= 8)
		{ }
		else cout << "m is bad!" << endl;
	cout << "Enter n" << endl;
		cin >> n;
		if (n > 0 && n <= 8)
		{}
		else
			cout << "n is bad!" << endl;
		if ((k + 2 == m && l + 1 == n) || (k - 2 == m && l + 1 == n) || (k - 2 == m && l - 1 == n) || (k + 2 == m && l - 1 == n) ||
			(k + 1 == m && l + 2 == n) || (k - 1 == m && l + 2 == n) || (k - 1 == m && l - 2 == n) || (k + 1 == m && l - 2 == n))
		{
			cout << "m,n is under attack!!!" << endl;
		}
		else
			cout << "all good" << endl;
	return 0;
}

